#pragma once
#include <string>
#include <vector>
class Student {
private:
	std::string name;								 // name
	std::string facultyNumber;						 // faculty number
	size_t size;									 // number of marks
	double* marks;									 // array with marks
public:
	// constructor, copy constructoru, assignment operator and destructor
	Student(std::string _name, std::string _facultyNumber, const double* _marks, size_t _size);
	Student(const Student& other);
	Student& operator=(const Student& other);
	~Student();
	// getters and setters
	const std::string& getName() const;
	const std::string& getFacultyNumber() const;
	const double* getMarks() const;
	void setName(std::string& _name);
	void setFacultyNumber(std::string& _FacultyNumbe);
	// utility methods 
	void addMark(const double& mark);
	double calculateGPA() const;
	const void print() const;
};

