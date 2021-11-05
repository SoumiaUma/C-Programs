#include <iostream>
#include <string>

using namespace std;

//Function to calculates which day of the week, the first day of the month falls on, for a month in a year
//Used this website to get a formula: (http://www.cplusplus.com/forum/general/174165/)
int firstDay(int year, int month, int day) 
{                                                  
    int x, y, z;
    x = (14 - month) / 12;
    y = year - x;
    z = month + (12 * x) - 2;
    return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * z) / 12)) % 7;
}

//Function that displays yearly calendar
void printYear(int year)
{
    int week=0;
    string monthNames[]={"January", "Feburary","March","April","May","June","July","August","September","October","November","December"};
    //Array to store number of days in each month 
    int monthDays[]={31,28,31,30,31,30,31,31,30,31,30,31};
    //Check for leap year and if so, add extra day to February
    if ((year%4==0 and year%100!=0) or (year%400==0)){ 
        monthDays[1]=29;
    }
    cout<<endl;
    //Prinitng the calendar for each month in the year 
    for (int month=0;month<12;month++){
        cout<<monthNames[month]<<" "<<year<<endl;
        //Displaying the names of the days in the week
        cout << "Sun Mon Tue Wed Thu Fri Sat" << endl;
        //Filling days of the week without dates with blank spaces (so until first day of the month is reached) 
        for (week=0;week<firstDay(year, month+1,1);week++)
        {
            cout<<"    ";
        }
        //Print each day of the month under the corrct day of the week
        for(int day=1;day<=monthDays[month];day++)
        {
            printf("%3d ",day);
            //Check if end of week (7 days) has passed and if so, set the week to the beginning and go next line 
            if (++week>6)
            {
                cout<<endl;
                week=0;
            }
        }
        cout<<endl;
        cout<<endl;
        cout<<endl;
    }
}

//Function that displays the monthly claendar
void printMonth(int year, int month)
{
    int week = 0;
    string months[]={"January", "Feburary","March","April","May","June","July","August","September","October","November","December"};
    int monthDays[]={31,28,31,30,31,30,31,31,30,31,30,31};//make array of days in each month

    if ((year%4==0 and year%100!=0) or (year%400==0))//add extra day to Feb. if leap year
    {
        monthDays[1]=29;
    }
    //Printing heading for the calendar
    cout << endl;
    cout << "Calendar - " << year << endl;
    cout << "Month: " << months[month-1] << endl;
    cout << "Sun Mon Tue Wed Thu Fri Sat" << endl;
    //Filling days of the week without dates with blank spaces (so until first day of the month is reached) 
    for (week=0;week<firstDay(year, month,1);week++)
    {
        cout<<"    ";
    }
    //Print each day of month under corrct day of the week
    for (int i=1;i<=monthDays[month-1];i++)
    {
        printf("%3d ",i);
        //Check if end of week (7 days) has passed and if so, set the week to the beginning and go next line 
        if (++week>6)
        {
            cout<<endl;
            week=0;
        }
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
}

int main() {
    int year, month, choice;
    //Array to display the options for the month user would like to view the calendar for 
	string monthName[12] = {"1. January", "2. February", "3. March", "4. April", 
					   "5. May", "6. June", "7. July", "8. August","9. September", 
					   "10. October", "11. November", "12. December"}; 
    //Getting user input for type of calendar they wouant to view 
    cout << "Which calendar would you like to view: \n1. Month Calendar\n2. Year Calendar " << endl;
    cin >> choice;

    //Display monthly calendar options and then display the calendar of the chosen month
    if (choice==1)
    {
        cout << "Enter the month you would like to view the calendar for:" << endl;
		for (int i=0;i<12;i++)
		{
			cout << monthName[i] << endl;
		}
		cin >> month;
		cout << "Enter the year you would like to view the calendar for: " << endl;
		cin >> year;
        printMonth(year,month);
        
    }
    //Display the yearly calendar
    else if (choice == 2)
    {
        cout << "Enter the year you would like to view the calendar for: " <<  endl;
		cin >> year;
        printYear(year);
    }
    //Invalid input is not excepted for the type of calendar. User needs to enter either 1 for month calendar or 2 for year calendar 
	else
	{
		while (choice!=1 && choice!=2)
		{
			cout << "Invalid input! Which calendar would you like to view: \n1. Month Calendar\n2. Year Calendar " << endl;
			cin >> choice;
		}
	}
}
