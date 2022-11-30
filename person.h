#pragma once
#include <iostream>
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class person
{
	// attributes
	string name;
	string job;
	string department;

public:
	// constructors
	person();
	person(string in_name);
	person(string in_name, string in_job);
	person(string in_name, string in_job, string in_department);

	// methods
	void print_out();
	string get_name();
	string get_jobtitle();
	string get_department();


	void change_department(string in_department);

	// destructor
	~person();
};

