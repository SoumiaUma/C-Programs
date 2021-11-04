#include<iostream>
#include<string>

using namespace std;

class Person{
	private:
		string firstName;
		string lastName;
		int age;
	public:
		string getFirstName() {return firstName;};
		void setFirstName(string fName) {firstName=fName;};
		string getLastName() {return lastName;};
		void setLastName(string lName) {lastName=lName;};
		int getAge() {return age;};
		void setAge(int a) {age = a;};
		Person();
		Person(string fName,string lName, int a);
		~Person();
};
Person::~Person()
{
	cout << "Destructor Called!" << endl;
}
Person::Person()
{
	firstName="Soumia";
	lastName="Umaputhiran";
	age = 18;
}
Person::Person(string fName,string lName, int a)
{
	firstName = fName;
	lastName = lName;
	age = a;
}
int main(){
	
	Person *p1 = new Person();
	cout << p1->getFirstName() << endl;
	cout << p1->getLastName() << endl;
	cout << p1->getAge()<< endl;
	
	Person *p2 = new Person("FNU","LNU",-1);
	cout << p2->getFirstName() << endl;
	cout << p2->getLastName() << endl;
	cout << p2->getAge()<< endl;
	
	return 0;
	
}