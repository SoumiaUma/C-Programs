#include <iostream>

using namespace std;

struct Person{
	string firstName;
	string lastName;
	int age;
	bool isEmployed;
	bool isStudent;
};	

int main(){
	//Creating ordinary variables from person structure 
	Person p1;
	p1.firstName = "Soumia";
	p1.lastName = "Umaputhiran";
	p1.age = 18;
	p1.isEmployed = false;
	p1.isStudent = true;
	
	cout << p1.firstName << " " << p1.lastName << " is " << p1.age << " years old." << endl;
	
	//Creating dynamic variables from the person structure
	Person *p2 = new Person;
	(*p2).firstName = "Maxwell";
	//Another way to initalize the dynamic variable (easier way to type)
	p2->lastName = "McLaughLin";
	p2->age = 18;
	p2->isEmployed = false;
	p2->isStudent= true;
	
	cout << p2->firstName << " " << p2->lastName << " is " << p2->age << " years old." << endl;
	
	if (p2->isStudent)
	{
		cout << p2->firstName << " " << p2->lastName << " is a student." << endl;
	}
	
	delete p2;
	
	return 0;
}