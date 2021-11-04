#include<iostream>

using namespace std;

class Person{
  private:
	//Member variables
	string firstName;
	string lastName;
	int age;
	bool isEmployed;
	bool isStudent;
	
	//Member functions 
  public:
  //Default constructor
  Person();
  Person (string f, string l, int a ,bool e, bool s);
  ~Person();
  
  //Getter and Setter 
  //Declaring the getter function for first name inside the class
  string getFirstName();
  //Setting firstName inside the class
  void setFirstName(string f){firstName = f;}
  string getLastName(){return lastName;}
  void setLastName(string l){lastName = l;}
  //Declaring and defining inside the class
  int getAge() {return age;};
  int setAge(int a){age = a;}
  
  bool isEqual(Person p);
  bool operator == (Person p);
};
//Using overloaded operator to compare both objects' values 
bool Person::operator==(Person *p)
{
	return (firstName == p->getFirstName() && lastName == p->getLastName() && age == p->getAge());
}
bool Person::isEqual(Person p)
{
	if (firstName != p.getFirstName())
	{
		return false;
	}
	if (lastName != p.getLastName())
	{
		return false;
	}
	if (age != p.getAge())
	{
		return false;
	}
}
//Definning getter function outside the class
string Person::getFirstName(){
	return firstName;
}
Person::Person (string f, string l, int a ,bool e, bool s)
{
	firstName = f;
	lastName = l; 
	age = a;
	isEmployed = e;
	isStudent = s;
}
Person::Person(){
	firstName = "FNU";
	lastName = "LNU";
	age = -1;
	isEmployed = false;
	isStudent = false;
}
Person::~Person(){
	cout << "Destructor called!" << endl;
}
int main(){
	
	Person *p1 = new Person();
	
	cout << "First Object: " << endl;
	cout << p1->getFirstName()<< " is " << p1->getAge() << " years old. " << endl;
	
	Person *p2 = new Person ("Georege", "LName", 18, false, true);
	cout << "\nSecond Object" << endl;
	cout << p2->getFirstName()<< " is " << p2->getAge() << " years old. " << endl;
	
	if (p1->isEqual(*p2))
	{
		cout << "Same person." << endl;
	}
	else
	{
		cout << "Different Person." << endl;
	}
	cout << endl;
	if (p1 == p2)
	{
		cout << "Same person." << endl;
	}
	else
	{
		cout << "Different Person." << endl;
	}
		
	//When delete is called it automatically calls the destructor and prints the message in that constructor 
	delete p1;
	delete p2;
	
	return 0;
	
}