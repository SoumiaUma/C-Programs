#include<iostream>

using namespace std;

//Creating a class called person to store variables that define a person
class Person{
  //Making the variables in the class private
  private:
	string firstName;
	string lastName;
	int age;
	bool isEmployed;
	bool isStudent;

  public:
    Person();
	Person(string fName,string lName,int a,bool e, bool s);
	void toString();
	int getAge();
	string getFirstName();
	string getLastName();
	void setAge(int a);
	void setFirstName(string fN);
	void setLastName(string lN);
};
void Person::toString(){
	cout << "First name is: " << firstName << endl;
	cout << "Last name is: " << lastName << endl;
	if (age < 0 )
	{
		cout << "Age is is unknown. " << endl;
	}
	else
	{
		cout << "Age is (in years) " << age << endl;
	}
	if (isEmployed == true)
	{
		cout << "Is employed? Yes." << endl;
	}
	else
	{
		cout << "Is employed? No." << endl;
	}
	if (isStudent == true)
	{
		cout << "Is student? Yes." << endl;
	}
	else
	{
		cout << "Is student? No." << endl;
	} 
}
//Creating the get functions for age, first name, and last name variables
string Person::getFirstName(){
	return firstName;
}
string Person::getLastName(){
	return lastName;
}
int Person::getAge(){
	return age;
}
//Creating the set functions for age, first name, and last name variables
void Person::setFirstName(string fN){
	firstName = fN;
}
void Person::setLastName(string lN){
	lastName = lN;
}
void Person::setAge(int a){
	//Checking to see if age is invalid
	if (a < 0 )
	{
		age = -1;
	}
	//If age is valid then set age to a 
	else
	{
		age = a;	
	}
}
Person::Person(){
	firstName = "FNU";
	lastName = "LNU";
	age = -1;
	isEmployed = false;
	isStudent = false;
}
Person::Person(string fName, string lName, int a, bool e, bool s){
	firstName = fName;
	lastName = lName;
	age = a;
	isEmployed = e;
	isStudent = s;
}
	
int main(){
	
	//Initalizing the class using default constructor
	Person *p1 = new Person ();
	//Initalizing the class with constructor with arguments
	Person *p2 = new Person ("Soumia","Umaputhiran",18,false,true);
	//Calling the toString function
	p2->toString();
	cout << endl;
	p1->toString();
	
	return 0;
}