#include <iostream>
#include "Bank.h"
#include <iomanip>

/*
Bank::Bank()
{
	ifstream ifs(fileName);
	if (ifs.is_open())
	{
		ifs >> j;
		ifs.close();
	}
	else
	{
		std::cout << "Cannot open text file\n\n";
	}
	if (!j.is_null())
	{
		for (int i = 1;; i++)
		{
			string Id = std::to_string(i);
			if (!j[Id]["name"].is_null())
			{
				customers.push_back(Customer(j[Id]["name"], j[Id]["lastName"], j[Id]["balance"]));
			}
			else
			{
				break;
			}
		}
	}
}

Bank::~Bank()
{
	for (Customer customer : customers)
	{
		j[customer.GetId()]["name"] = customer.GetName();
		j[customer.GetId()]["lastName"] = customer.GetLastName();
		j[customer.GetId()]["balance"] = customer.GetBalance();
	}
	ofstream ofs(fileName);
	ofs.open(fileName);
	if (ofs.is_open())
	{
		ofs << setw(4) << j;
		ofs.close();
	}
	else
	{
		std::cout << "Failed to save data to file.";
	}
}
*/
void Bank::CreateAccount()
{
	std::cout << "Enter Name: ";
	std::string name;
	std::cin >> name;
	std::cout << '\n';

	std::cout << "Enter Last Name: ";
	std::string lastName;
	std::cin >> lastName;
	std::cout << '\n';

	std::cout << "Enter start balance: ";
	int balance;
	std::cin >> balance;
	std::cout << '\n';

	Customer customer = Customer(name, lastName, balance);
	customers.push_back(customer);
	std::cout << "User added.\n\n";
}
void Bank::UpdateInformation()
{
	std::cout << "Enter your user ID: ";
	std::string Id;
	std::cin >> Id;

	for (Customer& customer : customers)
	{
		if (customer.GetId() == Id)
		{
			std::cout << "User ID:  " << customer.GetId() << "\tName:  " << customer.GetName() << "\tLast Name:  "
				<< "\tBalance: " << customer.GetBalance() << "$\n";

			std::cout << "What exactly do you want to change?\n";
			std::cout << "1. First Name\n2. Last Name\n3. Balance\n";
			std::cout << "To change press 1, 2 or 3: ";
			char ch;
			std::cin >> ch;

			if (ch == '1')
			{
				std::cout << "Enter a new name: ";
				std::string newName;
				std::cin >> newName;

				customer.updateName(newName);
			}
			else if (ch == '2')
			{
				std::cout << "Enter a new last name: ";
				std::string newName;
				std::cin >> newName;

				customer.updateLastName(newName);
			}
			else if (ch == '3')
			{
				std::cout << "Enter balance: ";
				int newBalance;
				std::cin >> newBalance;

				customer.updateBalance(newBalance);
			}
			else
			{
				std::cout << "Sorry, your selection was not found.";
			}
			std::cout << "\n\n";
		}
	}
}
void Bank::Transaction()
{
	std::cout << "User ID - from which you want to transfer money: ";
	std::string IdFrom;
	std::cin >> IdFrom;

	std::cout << '\n';

	std::cout << "User ID - where you want to transfer money from: ";
	std::string IdTo;
	std::cin >> IdTo;

	std::cout << '\n';

	Customer *fromCust = nullptr, *toCust = nullptr;

	for (Customer& customer : customers)
	{
		if (customer.GetId() == IdFrom)
		{
			fromCust = &customer;
		}
		else if (customer.GetId() == IdTo)
		{
			toCust = &customer;
		}
	}

	if (fromCust != nullptr && toCust != nullptr)
	{
		std::cout << "Enter the amount to transfer: ";
		int sum;
		std::cin >> sum;

		if (fromCust->GetBalance() >= sum)
		{
			fromCust->updateBalance(fromCust->GetBalance()-sum);
			std::cout << "Successfully withrawn from the account " << fromCust->GetName() << ' ' << fromCust->GetLastName() << ' ' << sum << "$.\n";

			toCust->updateBalance(toCust->GetBalance() + sum);
			std::cout << "Successfully added to the account " << toCust->GetName() << ' ' << toCust->GetLastName() << ' ' << sum << "$.\n\n";
		}
		else
		{
			std::cout << "Sorry, there are not enough funds in the account: " << fromCust->GetName() << ' ' << fromCust->GetLastName() << "\n\n";
		}
	}
	else
	{
		std::cout << "Sorry, one of the users does not exist." << "\n\n";
	}
	
}
void Bank::CheckInformations()
{
	std::cout << "User ID: ";
	std::string UserId;
	std::cin >> UserId;
	std::cout << '\n';

	for (Customer &customer : customers)
	{
		if (customer.GetId() == UserId)
		{
			std::cout << "User ID: " << customer.GetId() << '\n';
			std::cout << "First Name: " << customer.GetName() << '\n';
			std::cout << "Last Name: " << customer.GetLastName() << '\n';
			std::cout << "Balance: " << customer.GetBalance() << "$\n\n";
		}
	}
}
void Bank::RemoveAccount()
{
	std::cout << "Please enter the ID of the User you want to remove from the list: ";
	std::string Id;
	std::cin >> Id;
	string fullName;
	bool have = false;

	for (Customer customer : customers)
	{
		if (customer.GetId() == Id)
		{
			customers.erase(std::remove_if(customers.begin(), customers.end(), [Id](Customer c)
				{
					return c.GetId() == Id;
				}));
			have = true;
		}
	}
	if (have)
	{
		std::cout << "User " << fullName << " deleted successfully.\n";
	}
	else
	{
		std::cout << "User with this ID does not exist.\n";
	}
}
void Bank::ViewCustomersList()
{
	for (Customer& customer : customers)
	{
		std::cout << "User ID: " << customer.GetId() << " Full Name: " << customer.GetName() << ' ' << customer.GetLastName()
			<< " Balance: " << customer.GetBalance() << "$\n";
	}
	std::cout << '\n';
}
