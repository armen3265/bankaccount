#pragma once
#ifndef BANK_H
#define BANK_H


#include "json.hpp"
#include "Customer.h"
#include <string>
#include <list>
#include <fstream>

using json = nlohmann::json;
using namespace std;

class Bank
{
private:
	std::list<Customer> customers;
	//json j;
	//string fileName = "accounts.json";
public:
	//Bank();
	//~Bank();

	void CreateAccount();
	void UpdateInformation();
	void Transaction();
	void CheckInformations();
	void RemoveAccount();
	void ViewCustomersList();



};
#endif // !BANK_H