// Gregory Linville
// December 7
// Exam 2

#include <string>
#include "Employee.h"
using namespace std;

Employee::Employee(int id, string myName) {
	employeeID = id;
	name = myName;
	balance = 0;
	payRate = 10;
}

int Employee::getEmployeeID() {
	return employeeID;
}

double Employee::getPayRate() {
	return payRate;
}

double Employee::getBalance() {
	return balance;
}

string Employee::getName() {
	return name;
}

void Employee::giveRaise(int rate) {
	double percent = rate * 0.01;
	payRate += payRate * percent;
}

void Employee::pay() {
	balance += payRate;
}

void Employee::fire() {
	payRate = 0;
	employed = false;
}

bool Employee::isEmployed() {
	return employed;
}