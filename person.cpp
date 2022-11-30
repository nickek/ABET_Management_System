#include "person.h"

// constructors
person::person() {
	name = "Default";
	job = "Default";
	department = "Default";
}

person::person(string in_name) {
	name = in_name;
	job = "Default";
	department = "Default";
}

person::person(string in_name, string in_job) {
	name = in_name;
	job = in_job;
	department = "Default";
}

person::person(string in_name, string in_job, string in_department) {
	name = in_name;
	job = in_job;
	department = in_department;
}

// methods
void person::print_out() {
	cout << "Name: " << name << endl;
	cout << "Job Title: " << job << endl;
	cout << "Department: " << department << endl;
}

void person::change_department(string in_department) {
	department = in_department;
}

string person::get_name() {
	return name;
}

string person::get_jobtitle() {
	return job;
}

string person::get_department() {
	return department;
}

// destructor
person::~person() {

}