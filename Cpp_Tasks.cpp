// Cpp_Tasks.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include <stdexcept>
#include "Student.h"

double studentGPA(const std::vector<Student> students, std::string name) {
	bool match = false;							// flag wheter the name was found in the array
	size_t index;								// the index it was found at
	for (size_t i = 0; i < students.size(); i++){
		if (students[i].getName() == name) {
			match = true;
			index = i;
			break;
		}
	}
	if (!match)
		throw("Student not found");              // notifying the user when there is no match
	else
		return students[index].calculateGPA();
}
std::string recursiveConcat(std::string string, size_t n, std::string separator) {
	if (n <= 1) {
		// base case, we only have to print out string once when n <= 1
		return string;
	}
	else{	
		// when n > 1 we append the separator and then append the function for n-1 
		return string.append(separator).append(recursiveConcat(string, n - 1, separator));
	}
}

int main()
{
	// Testing
	// Task 4 - recursive concatenation function
	std::cout << recursiveConcat("inensia", 1, " <3 ") << "\n";
	std::cout << recursiveConcat("inensia", 5, " <3<3 ") << "\n";
	// Task 3 - class student + GPA function
	double m1[] = {6, 6, 4, 3, 5 }
		 , m2[] = {2, 3, 6, 4, 6, 6}
		 , m3[] = {3, 4, 3, 6};
	Student s1("ivo", "72356", m1, 5)
		  , s2("pesho", "72543", m2, 6)
		  , s3(s1) // copy constructor test
		  , s4("ivan", "72476", m3, 4);
	s1 = s4; // assignment operator test
	std::vector<Student> students; // creating vector of students
	// addin elements
	students.push_back(s1);
	students.push_back(s2);
	students.push_back(s3);
	// printing info for all students
	for (size_t i = 0; i < students.size(); i++){
		students[i].print();
	}
	std::cout << studentGPA(students, "ivo") << "\n";    // function test
	//std::cout << studentGPA(students, "tosho") << "\n";  // exception test when incorect parameters are used
}

