#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

using namespace std;

class Customer
{
private:
	string Id;
	string name;
	string lastName;
	int balance;

public:
	static int Counter;
	Customer(string name, string lastName, int balance);

	string GetId();
	string GetName();
	string GetLastName();
	double GetBalance();

	void updateName(string name);
	void updateLastName(string lastName);
	void updateBalance(int balance);
};
#endif // !CUSTOMER_H
