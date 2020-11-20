#include "Customer.h"

Customer::Customer(string name, string lastName, int balance)
{
	this->name = name;
	this->lastName = lastName;
	this->balance = balance;
	Counter++;
	this->Id = to_string(Counter);
}

string Customer::GetId()
{
	return this->Id;
}

string Customer::GetName()
{
	return name;
}

string Customer::GetLastName()
{
	return this->lastName;
}

double Customer::GetBalance()
{
	return this->balance;
}

void Customer::updateName(string name)
{
	this->name = name;
}

void Customer::updateLastName(string lastName)
{
	this->lastName = lastName;
}

void Customer::updateBalance(int balance)
{
	this->balance = balance;
}
