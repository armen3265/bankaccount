#include <iostream>
#include "Bank.h"
#include <string>
const char s = 178;
int Customer::Counter = 0;
int main()
{
	Bank bank = Bank();
	bool close = false;
	std::cout << "\tCUSTOMER ACCOUNT BANKING MANAGMENT SYSTEM\n\n";
	std::cout << '\t' << s << s << s << s << s << "WELCOME TO THE MAIN MENU" << s << s << s << s << s << "\n\n";

	while (!close)
	{
		//system("color 01");
		
		
		std::cout << "1. Create new account\n";
		std::cout << "2. Update information of existing account\n";
		std::cout << "3. For transactions\n";
		std::cout << "4. Check the details of existing account\n";
		std::cout << "5. Removing existing account\n";
		std::cout << "6. View customer's list\n";
		std::cout << "7. Exit\n\n\n\n";
		std::cout << "Enter your choice: ";

		int choice;

		std::cin >> choice;
		std::cout << '\n';

		switch (choice)
		{
		case 1:
			bank.CreateAccount();
			break;
		case 2:
			bank.UpdateInformation();
			break;
		case 3:
			bank.Transaction();
			break;
		case 4:
			bank.CheckInformations();
			break;
		case 5:
			bank.RemoveAccount();
			break;
		case 6:
			bank.ViewCustomersList();
			break;
		case 7:
			close = true;
			std::cout << "\tThank you!\n";
			break;
		default:
			std::cout << "Your selection was not found. Please try again.\n\n";

		}
	}
	
}
