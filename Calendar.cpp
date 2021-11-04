#include <iostream>

using namespace std;
//Function to determine what day month starts on 
int dayNumber(int day, int month, int year) 
{ 
	//Array that stores the position that array starts on for each month
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 }; 
	//Formula that calculates the day the month starts on for that year
    year -= month < 3; 
    return ( year + year/4 - year/100 + year/400 + t[month-1] + day) % 7; 
} 
//Function to print calendar for one month on a specific year 
void printMonth(int month, int year)
{
	//Array to store the month name 
	string monthName[12];
	//Array to number of days in a month
	int day;
	//If else statements to store the number of days in the month entered and the name of the month
	if (month == 1)
	{
		day=31;
		monthName[0]= "January";
	}
	//Checking to see if year is a leap year for the month of Feburary
	else if (month== 2)
	{
		monthName[1]= "Feburary";
		// If the year is a leap year then February has 29 days 
		if ((year % 400 == 0 || year % 4 == 0 && year % 100 != 0)) 
        {
			day == 29;
		}
		//Otherwise, Feburary has 28 days
		else
		{
			day == 28; 
		}
	}
	else if (month==3)
	{
		day=31;
		monthName[2]= "March";
	}
	else if (month ==4)
	{
		day=30;
		monthName[3]= "April";
	}
	else if (month ==5)
	{
		day=31;
		monthName[4]= "May";
	}
	else if (month ==6)
	{
		day=30;
		monthName[5]= "June";
	}
	else if (month ==7)
	{
		day=31;
		monthName[6]= "July";
	}
	else if (month ==8)
	{
		day=31;
		monthName[7]= "August";
	}
	else if (month ==9)
	{
		day=30;
		monthName[8]= "September";
	}
	else if (month ==10)
	{
		day=31;
		monthName[9]= "October";
	}
	else if (month ==11)
	{
		day=30;
		monthName[10]= "November";
	}
	else if (month == 12)
	{
		day=31;
		monthName[11]= "December";
	}
	//Printing heading for the calendar
	cout << "Calendar - " << year << endl;
	cout << "Month: " << monthName[month-1] << endl;
	//Creating a variable to store the current day the month will start with using the dayNumber function
	int current = dayNumber (1, 1, year); 
	//Setting up the days in the calendar 
	cout << "Sun  Mon  Tue  Wed  Thu  Fri  Sat" << endl;
	int col;
	//Creating empty spaces for days with nothing at the beggining of the month
	for (col = 0; col < current; col++)
	{
        cout << "     "; 
	}
	//Displaying the day number under each column in the calendar
    for (int j = 1; j<= day; j++) 
    { 
		if (j<10)
		{
			cout << j << "    "; 
		}
		else
		{
			cout << j << "   ";
		}
		col++;
		//Moving output to next line when col is greater than 6
        if (col > 6) 
        {
			//Setting col to 0 for next row 
            col = 0; 
            cout << "\n"; 
        } 
    } 
	//Setting the current day to the value of col
    current = col; 
}
void printYear(int year)
{
	//Array to store the month name
	string monthName[12] = {"January", "February", "March", "April", 
					        "May", "June", "July", "August","September", 
					        "October", "November", "December"}; 
	//Variable to store the amount of days in the month
	int days;
	//Variable to set the number of days in each month
	int day;
	//Creating an array to store the amount of days in a month
	int months [12];
	//Initializing each position in the months array to num of days in that month
	months[0] = 31;
	//Checking to see if year is a leap year for the month of Feburary
	monthName[1]= "Feburary";
	// If the year is a leap year then February has 29 days 
	if ((year % 400 == 0 || year % 4 == 0 && year % 100 != 0)) 
	{
		day == 29;
		months[1]=29;
	}
	//Otherwise, Feburary has 28 days
	else
	{
		day == 28; 
		months[1]=28;
	}
	months[2] = 31;
	months[3]= 30;
	months[4] = 31;
	months [5]= 30;
	months [6] = 31;
	months [7] = 31;
	months[8] = 30;
	months [9] = 31;
	months[10]=30;
	months[11]=31;
	//Creating a variable to store the current day the month will start with using the dayNumber function
	int current = dayNumber (1, 1, year);
	//Displaying the header for the calendar 
	cout << "Calendar - " << year << endl;
	for (int i = 0; i < 12; i++) 
    { 
		//Setting the number of days each month has 
		days = months[i];
		//Printing the month name 
        cout << endl << monthName[i] << ":" << endl; 
		//Setting the columns of the calendar with the day of the week
		cout << "Sun  Mon  Tue  Wed  Thu  Fri  Sat" << endl;
		int col;
		for (col = 0; col < current; col++)
		{
            cout << "     "; 
		}
        for (int j = 1; j<= days; j++) 
        { 
			if (j<10)
			{
				cout << j << "    "; 
			}
			else
			{
				cout << j << "   ";
			} 
			col++;
            if (col > 6) 
            { 
                col= 0; 
                cout << "\n"; 
            } 
        } 
        current = col; 
	}
	
}
int main(){
	//Creating a variable to store user's option for which type of calender the user would like to view 
	int calendar,month,year;
	//Array to display the options for the month user would like to view the calendar for 
	string monthName[12] = {"1. January", "2. February", "3. March", "4. April", 
					   "5. May", "6. June", "7. July", "8. August","9. September", 
					   "10. October", "11. November", "12. December"}; 
	
	//Getting user input for type of calendar they wouant to view 
	cout << "Which calendar would you like to view: \n1. Month Calendar\n2. Year Calendar " << endl;
	cin >> calendar;
	
	//Getting user input to user input for month calendar
	if (calendar==1)
	{
		cout << "Enter the month you would like to view the calendar for:" << endl;
		for (int i=0;i<12;i++)
		{
			cout << monthName[i] << endl;
		}
		cin >> month;
		cout << "Enter the year you would like to view the calendar for: " << endl;
		cin >> year;
		
		printMonth(month,year);
		cout << endl;
	}
	//Getting user input for the year calendar 
	else if (calendar==2)
	{
		cout << "Enter the year you would like to view the calendar for: " <<  endl;
		cin >> year;
		printYear(year);
		cout << endl;
	}
	//Invalid input is not excepted for the type of calendar. User needs to enter either 1 for month calendar or 2 for year calendar 
	else
	{
		while (calendar!=1 && calendar!=2)
		{
			cout << "Invalid input! Which calendar would you like to view: \n1. Month Calendar\n2. Year Calendar " << endl;
			cin >> calendar;
		}
	}
	
	return 0;
}
	