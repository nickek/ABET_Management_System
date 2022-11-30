#include <iostream>
#include <string>
#include <list>
#include "person.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::list;

void search(list<person> &i, string word);
string cap(string word);
void update(list<person>& i, string word);

int main() {

	// initializing the office
	person Jann = person("Jann", "CEO", "Corperate");
	person Michael = person("Michael", "Manager", "Corperate");
	person Dwight = person("Dwight", "Salesmen", "Sales");
	person Jim = person("Jim", "Salesmen", "Sales");
	person Stanley = person("Stanley", "Salesmen", "Sales");
	person Philis = person("Philis", "Salesmen", "Sales");
	person Kevin = person("Kevin", "Accountant", "Accounting");
	person Angela = person("Angela", "Accountant", "Accounting");
	person Oscar = person("Oscar", "Accountant", "Accounting");
	person Pam = person("Pam", "Receptionist", "Office");
	person Ryan = person("Ryan", "Intern", "Office");
	person Creed = person("Creed", "Unknown", "Office");
	person Toby = person("Toby", "Representitive", "HR");
	person Kelly = person("Kelly", "Represetitive", "HR");
	
	list <person> office = { Jann, Michael, Dwight, Jim, Stanley, Philis, Kevin, Angela, Oscar, Pam, Ryan, Creed, Toby, Kelly };

	bool use = true;

	cout << "Welcome to the office" << endl;

	do {										// program loop
		int user = 0;
		string name;
		string job;
		string department;
		cout << "Please select a function:" << endl;
		cout << "1. Add a new employee" << endl;
		cout << "2. Search" << endl;
		cout << "3. See all employees" << endl;
		cout << "4. Remove a employee" << endl;
		cout << "5. Exit" << endl;
		cout << "6. Update a department to [Engineering]" << endl;
		cin >> user;

		if (user == 1) {						// add employee
			cout << "Please enter the employees name: ";
			cin >> name;
			cout << "Please enter the employee's job title: ";
			cin >> job;
			cout << "Please enter the employee's department: ";
			cin >> department;
			name = cap(name);
			job = cap(job);
			department = cap(department);
			person user = person(name, job, department);
			office.push_back(user);
		}
		else if (user == 2) {					// search
			string word;
			cout << "Search: ";
			cin >> word;
			word = cap(word);
			search(office, word);
		}
		else if (user == 3) {					// list employees
			list <person>::iterator p = office.begin();
			cout << "Employees: " << endl;
			while (p != office.end()) {
				cout << p->get_name() << ": " << p->get_jobtitle() << ": " << p->get_department() << endl;
				p++;
			}
		}
		else if (user == 4) {					// remove employee
			cout << "Enter the name of the employee you want to remove: ";
			cin >> name;
			name = cap(name);
			list <person>::iterator p = office.begin();
			int a = 0;
			while (p != office.end()) {
				if (name == p->get_name()) {
					cout << "Removing " << p->get_name() << endl;
					p = office.erase(p);
					a++;
				}
				if( a > 0) {
					break;
				}
				p++;
			}
			if (a == 0) {
				cout << "No one found by " << name << endl;
			}
		}
		else if (user == 5) {					// exit
			use = false;
		}
		else if (user == 6) {					// LIVE CODE
			string word;
			cout << "Please enter a department you would like to change: " << endl;
			cin >> word;
			word = cap(word);
			update(office, word);
		}
		else {
			cout << "Invalid option! please try again" << endl;
		}
	} while (use == true);

	cout << "Thank you for managing the office!" << endl;
	return 0;
}

void search(list<person> &i, string word) {
	
	list <person>::iterator p = i.begin();
	int n = 0;

	while (p != i.end()) {
		if (word == p->get_name()) {	// check if search is a name
			cout << "Department: " << p->get_department() << endl;
			cout << "Job: " << p->get_jobtitle() << endl;
			cout << "Name: " << p->get_name() << endl;
		}
		else if (word == p->get_jobtitle()) {	// check if search is job
			list <person>::iterator j = i.begin();
			int k = 0;
			cout << "Job: " << p->get_jobtitle() << endl;
			while (j != i.end()) {
				if (j->get_jobtitle() == p->get_jobtitle()) {
					cout << j->get_name() << endl;
					k++;
				}
				j++;
			}
			if (k > 0) {
				break;
			}
		}
		else if (word == p->get_department()) {	// check if search is department
			list <person>::iterator j = i.begin();
			int k = 0;
			cout << "Department: " << p->get_department() << endl;
			while (j != i.end()) {
				if (j->get_department() == p->get_department()) {
					cout << j->get_jobtitle() << ": " << j->get_name() << endl;
					k++;
				}
				j++;
			}
			if (k > 0) {
				break;
			}
		}
		else {
			n++;
		}
		p++;
	}
	if (n == i.size()) {					// if no matches found
		cout << "No matches found for: " << word << endl;
	}
}

string cap(string word) {					// make sure word starts capitilized
	word[0] = toupper(word[0]);
	for (int i = 1; i < word.length(); i++) {
		word[i] = tolower(word[i]);
	}
	return word;
}

void update(list<person>& i, string word) {
	list <person>::iterator p = i.begin();
	string dep;
	int j = 0;
	while (p != i.end()) {
		if (word == p->get_department()) {
			p->change_department("Engineering");
			dep = p->get_department();
			j = 1;
		}
		p++;
	}
	if (j == 1) {
		cout << "Department: " << dep << " changed to 'Engineering' " << endl;
		
	}
}