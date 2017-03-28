

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

//Prototypes
using namespace std;

void header ( ofstream &output); 
//Tells the code to look for the header function below

void read( char &type, int &arrive, int &exit, ifstream &input); 
//Tells the code to look for the read function below

void calculate(char &type, int &arrive, int &exit, int &totalMin, float &totalCost, int &totalHours);
//Tells the code to look for the calculate function

void printTicket( ofstream &output, char &type, int &arrive, int &exit, int &totalMin, float &totalCost, int &totalHours);
//Tells the code to look for the print function

void footer (ofstream &output);
//Tells the code to look for the footer function


int main(){

char type;
int arrive;
int exit;
int totalMin;
int totalHours;
float totalCost;

ifstream input("data.txt", ios::in);//The variable input is linked to the text file selected
ofstream output("output.txt", ios::out);
output.setf(ios::fixed);
output.precision(2);


header(output);//Prints the header 

read(type, arrive, exit, input);
//read in the data from the file and store the information into variables

while(type != 'X')
 //This loop is created so that the entire text file is read until the character 'X' is passed through
{

 calculate(type, arrive, exit, totalMin, totalCost, totalHours);
 //calculate the total time in hours, 
 //	rounded up, that the car spends on the lot
 
 printTicket(output, type, arrive, exit, totalMin, totalCost, totalHours);
 //print the ticket after reading in the 
 //	paramaters for variables listed above
 
 read(type, arrive, exit, input);
 //This read call is used so that the loop can continue, or else is would be reading the same line of code endlessly 
 
}

footer(output);//Prints the footer 

return 0;
}

//**************************************** FUNCTION HEADER **************************************** 
void header ( ofstream &output)
{
			// Receives - The output file
			// Task - Prints the output preamble 
			// Returns - Nothing
	cout << setw(30) << "Alex Helbig";
	cout << setw(17) << "CSC 24400";
	cout << setw(15) << "Section 11" << endl;
	cout << setw(30) << "Spring 2017";
	cout << setw(20) << "Assignment #1" << endl;
	cout << setw(35) << "----------------------------------";
	cout << setw(35) << "----------------------------------" << endl << endl;
	return;
	}
//************************************ END OF FUNCTION HEADER ************************************


//****************************** FUNCTION HEADER ***************************	
void read( char &type, int &arrive, int &exit, ifstream &input)
	{
		input >> type;//First line read is a 'character' and places that value into the variable 'type'
		input >> arrive;//Next line read is a 'integer' and places that value into the variable 'arrive'
		input >> exit;//Final line read is another 'integer' and places that value into the variable 'exit'
	}



//****************************** FUNCTION HEADER ***************************	
void calculate(char &type, int &arrive, int &exit, int &totalMin, float &totalCost, int &totalHours)
	{
 			
 	//Recieves: Data read in by the ReadData function that
	//	was read in by the file
	//Task: Calculates the amount to be paid by each driver
	//	depending on the type of vehicle
	//	and the time spent on the lot
	//Returns: The cost of the ticket to be paid

//****************** END OF FUNCTION HEADER ********************************
 			
 			
 			
 			
 			//This if-else statement is used to calculate the total amount of hours to be printed on the final ticket
 			
	 	if ((exit-arrive)%60 == 0)
	 			{
	 			//This if is used to determine if they stay in the spot for an EXACT hour time
	 			totalHours = (exit-arrive)/60; 
	 			}
	 		
	 	else 
	 			{
	 			//In the event they stayed a minute or more past the hour, they are bumped up another hour
	 			totalHours = ((exit-arrive)/60)+1;
	 			}
	 			
	 			
//***************************************  CARS!  ***************************************

		if(type == 'C')//If the character letter 'C' is read then it calculates the ticket for the car rates
			{
				totalMin = exit - arrive;//Time is in total minutes so exit - arrive is the total time in minutes
				
			if (totalMin <=60)//60 minutes or less is just a $0.20 cent charge
					{
					totalCost = .2;
					
					}
					
			else if ((61 <= totalMin) && (totalMin <= 120))
					{
					//It has to be $0.40
					totalCost = .4;
					
					}
				
			else if ((121 <= totalMin) && (totalMin <= 300))//Time between 2 and 5 hours
					{
					// Three possible outcomes: it can be $0.55, $0.70, or $0.85 
					if((totalMin-120)%60 == 0)
						{
						//This if is used to determine if they stay in the spot for an EXACT hour time
						totalCost = (((totalMin-120)/60)*.15) + .4; 
						
						}
						
				else {
						//In the event they stayed a minute or more past the hour, they are charged for the entire next hour
						totalCost = ((((totalMin-120)/60) + 1) * .15) + .4;
						
					
						}
					}
				
			else if (301 <= totalMin)//Anything over 5 hours
					{
					
					//already being charged $0.85
				if ((totalMin-300)%60 == 0)
						{
						//This if is used to determine if they stay in the spot for an EXACT hour time
						totalCost = (((totalMin-300)/60)*.05) + .85;
						
						}
						
				else {
						//In the event they stayed a minute or more past the hour, they are charged for the entire next hour
						totalCost = ((((totalMin-300)/60) + 1) *.05) + .85;
						
					
						 }
					}
					
			}
			
			
//*************************************  TRUCKS!  *************************************

		else if(type == 'T')
			{

			totalMin = exit - arrive;//Time is in total minutes so exit - arrive is the total time in minutes
				
				if(totalMin <= 60)//For trucks they are charged $0.40 for only the first hour
				{
					totalCost = .4;
					
				} 
				
			else if((61<= totalMin) && (totalMin <= 240))//Time between 1 and 4 hours
				{
					//Already charged $0.40
				if((totalMin-60)%60 == 0)
					{
					//This if is used to determine if they stay in the spot for an EXACT hour time
					totalCost = (((totalMin-60)/60)*.25) + .4;
						
						
					}
						
				else {
					//In the event they stayed a minute or more past the hour, they are charged for the entire next hour
					totalCost = ((((totalMin-60)/60)+1)*.25) + .4;	
						
					}
				}
				
			else if(241<=totalMin)//Any time longer than 4 hours
				{
					//Already charged $1.15
				if((totalMin-240)%60 == 0)
					{
					//This if is used to determine if they stay in the spot for an EXACT hour time
					totalCost = (((totalMin-240)/60)*.1) + 1.15;
						 
					}
					
				else {
					//In the event they stayed a minute or more past the hour, they are charged for the entire next hour
					totalCost = ((((totalMin-240)/60)+1)*.1) + 1.15;
						 
					}
				
				
				}
			}
			
			
//***********************************  SENIOR CITIZENS  ***********************************

		else if(type == 'S')
			{
				
			totalMin = exit - arrive;
			//Time is in total minutes so exit - arrive is the total time in minutes
			totalCost = (totalMin/60);
				
			if ((totalMin%60) == 0)
				{
				//This if is used to determine if they stay in the spot for an EXACT hour time
				totalCost = (totalCost * .12);
					
				}
			else {
				//In the event they stayed a minute or more past the hour, they are charged for the entire next hour
				totalCost = (totalCost + 1) * .12;
					
				}
			
	 
	}

}
//************************* FUNCTION FOOTER ********************************

	//Recieves: Data read in by the ReadData function that
	//	was read in by the file
	//Task: Calculates the amount to be paid by each driver
	//	depending on the type of vehicle
	//	and the time spent on the lot
	//Returns: The cost of the ticket to be paid

//************************ END OF FUNCTION FOOTER **************************




//************************ FUNCTION HEADER *********************************
void printTicket( ofstream &output, char &type, int &arrive, int &exit, int &totalMin, float &totalCost, int &totalHours)
	{
			//Recieves: Data read from file and the cost calculated by the
			//	ProcessData function
			//Task: Prints the physical ticket to be paid by the driver of
			//	the vehicle
			//Returns: Nothing

//******************* END OF FUNCTION HEADER *******************************


	
	cout<<"The input data was: "<<endl;
	cout<<type<<" "<<arrive<<" "<<exit<<endl;
	
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;		//Prints the top part of the ticket
	cout<<"$                       $"<<endl;
	cout<<"$   MISSOURI WESTERN    $"<<endl;
	cout<<"$   UNIVERSITY          $"<<endl;
	cout<<"$                       $"<<endl;
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
	cout<<"$   PARKING FEE         $"<<endl;
	cout<<"$                       $"<<endl;
	cout<<"$   CUSTOMER            $"<<endl;		//End of top part of ticket
	
	if( type == 'C')
	//This was created so that the actual word car is printed instead of just the character 'C'
	{
	cout<<"$   CATEGORY: Car       $"<<endl;
	}
	
	if( type == 'T')
	//This was created so that the actual word truck is printed instead of just the character 'T'
	{
	cout<<"$   CATEGORY: Truck     $"<<endl;
	}
	
	if( type == 'S')
	//This was created so that the actual word Senior is printed instead of just the character 'S'
	{
	cout<<"$   CATEGORY: Senior    $"<<endl;
	}
	
	cout<<"$                       $"<<endl;
	
	if ( totalHours >= 10)
	//This if statement is used so that if the hours are more than one digit, then the spacing is properly printed 
	{
	cout<<"$   TIME:     "<<totalHours<< " hours  $"<<endl;
	
	}
	
	else if ( (totalHours < 10) && (totalHours > 1))
	//Single digit hour amount MORE than just one hour
	{
	cout<<"$   TIME:     "<<totalHours<< " hours   $"<<endl;
	
	}
	
	else if( totalHours <= 1 )
	//Prints for just one hour of parking
	{
	cout<<"$   TIME:     "<<totalHours<< " hour    $"<<endl;
	}
	
	cout<<"$                       $"<<endl;
	cout<<"$   AMOUNT              $"<<endl;
	cout<<"$   PAID:     $"<<fixed<<setprecision(2)<<totalCost<<"     $"<<endl;
	cout<<"$                       $"<<endl;
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	
	
	
	
	}
//************************* FUNCTION FOOTER *****************************

	//Recieves: Data read from file and the cost calculated by the
	//	ProcessData function
	//Task: Prints the physical ticket to be paid by the driver of
	//	the vehicle
	//Returns: Nothing

//************************ END OF FUNCTION FOOTER ************************
	

//**************************************** FUNCTION FOOTER **************************************** 	
void footer (ofstream &output)
{
			//Receives - The output file
			//Task - Prints the output salutation
			//Returns - Nothing
	cout << endl;
	cout << setw(35) << "-----------------------------------";
	cout << setw(35) << "|      END OF PROGRAM OUTPUT      |";
	cout << setw(35) << "-----------------------------------";
	return;

}
//************************************ END OF FUNCTION FOOTER ************************************
 
