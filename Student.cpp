#include "Student.h"
#include <iostream>
Student::Student(std::string _name, std::string _facultyNumber, const double* _marks, size_t _size) 
	: name(_name)
	, facultyNumber(_facultyNumber)
	, size(_size >= 0 ? _size : 0)
	, marks(new double[_size]) {
	for (size_t i = 0; i < _size; i++){
		this->marks[i] = _marks[i];
	}
}
Student::Student(const Student& other)
	: name(other.name)
	, facultyNumber(other.facultyNumber)
	, size(other.size)
	, marks(new double[other.size] ) {
	// after succssesful memory alocation we check for copying exceptions
	try{
		for (size_t i = 0; i < this->size; i++){
			this->marks[i] = other.marks[i];
		}
	} 
	// if an exception is thrown we have to free the alocated momery
	catch (...)
	{
		delete[] marks;
		throw;
	}
}
Student& Student::operator=(const Student& other) {
	// base exception safety
	if (this != &other) {
		this->name = other.name;
		this->facultyNumber = other.facultyNumber;
		this->size = other.size;
		delete[] this->marks;
		this->marks = new double[this->size];
		try {
			for (size_t i = 0; i < this->size; i++) {
				this->marks[i] = other.marks[i];
			}
		}
		// if an exception has accured we have to free the memory
		catch (...)
		{
			delete[] marks;
			throw;
		}
	}
	return *this;
}
Student::~Student() {
	// deleting the allocated memory
	delete[] this -> marks;
}
const std::string& Student::getName() const {
	return this->name;
}
const std::string& Student::getFacultyNumber() const {
	return this->facultyNumber;
}
const double* Student::getMarks() const {
	return this->marks;
}
void Student::setName(std::string& _name) {
	this->name = _name;
}
void Student::setFacultyNumber(std::string& _FacultyNumbe) {
	this->facultyNumber = _FacultyNumbe;
}
void Student::addMark(const double& mark) {
	double* result = new double[this->size + 1];
	try {
		for (size_t i = 0; i < size+1; i++){
			result[i] = marks[i];
		}
	}
	catch (...){
		delete[] result;
		throw;
	}
	result[size] = mark;
	size++;
	delete[] this->marks;
	marks = result;
}
double Student::calculateGPA() const {
	double result = 0;
	if (size != 0) {
		for (size_t i = 0; i < size; i++) {
			result += marks[i];
		}
		return result / size;
	}
	else
		return 0;
}	const void Student::print() const {
	std::cout << "Student name: " << this->name << "\n"
			  << "Faculty number: " << this->facultyNumber << "\n"
			  << "Marks: {";
	for (size_t i = 0; i < this->size; i++){
		std::cout << marks[i] << ", ";
	}
	std::cout << "}\n\n";
}
