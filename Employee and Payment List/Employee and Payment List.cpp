// Gregory Linville

#include <string>
#include<iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Employee.h"

using namespace std;

int main() {
	vector<Employee> Employees;

	ifstream fin("input.txt");
	ofstream fout("output.txt");

	// Throw error if can't open input file
	if (!fin.is_open()) {
		cerr << "Error opening input file!";
		system("pause");
		return 1;
	}

	while (fin.good()) {
		string input;
		int id;
		int i = 0;
		fin >> input;
		if (input == "NEW") {
			string firstname, lastname;
			fin >> id >> firstname >> lastname;
			string name = firstname + " " + lastname;
			Employee tempEmpolyee(id, name);
			Employees.push_back(tempEmpolyee);
		}
		if (input == "RAISE") {
			int raise;
			fin >> id >> raise;
			for (i = 0; i < Employees.size(); ++i) {
				if (Employees.at(i).getEmployeeID() == id)
					Employees.at(i).giveRaise(raise);
			}

		}
		if (input == "PAY") {
			for (i = 0; i < Employees.size(); ++i)
				Employees.at(i).pay();
		}
		if (input == "FIRE") {
			fin >> id;
			for (i = 0; i < Employees.size(); ++i) {
				if (Employees.at(i).getEmployeeID() == id)
					Employees.at(i).fire();
			}
		}
	}

	for (int i = 0; i < Employees.size(); ++i) {
		fout << Employees.at(i).getName() << ", ID Number " << Employees.at(i).getEmployeeID() << ":" << endl;
		if (Employees.at(i).isEmployed() == false) {
			fout << "Not employed with the company." << endl;
		}
		else
			fout << "Current pay rate: $" << Employees.at(i).getPayRate() << endl;
		fout << "Pay earned to date: $" << Employees.at(i).getBalance() << endl << endl;
	}

	fin.close();
	fout.close();
}