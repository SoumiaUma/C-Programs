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
	int getAge();
	string getFirstName();
	string getLastName();
	void setAge(int a);
	void setFirstName(string fN);
	void setLastName(string lN);
};
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
int main(){
	//Initalizing rhe class
	Person *p1 = new Person ();
	
	//Using values set in the Person constructor
	//Printing the values set through the get and set functions made for the age, first name and last name fucntions
	cout << p1->getFirstName() << " " <<  p1->getLastName() << " is " << p1->getAge() << " years old." << endl;
	
	return 0;
}