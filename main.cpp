#include <iostream>
using namespace std;
#include "Binary.h"

void end();
int main() {
	//default Master Key is 0000

	Binary obj;
	char choice;

	do {
		system("cls");
		cout << "\n\n\t  Main Menu\n\n";
		cout << "\t1: Add New Customer\n\n"
			<< "\t2: Modify Customer Data\n\n"
			<< "\t3: Show Customer Data\n\n"
			<< "\t4: Show All Customer Data\n\n"
			<< "\t5: Delete Customer Record\n\n"
			<< "\t6: Deposit Amount\n\n"
			<< "\t7: Withdraw Amount\n\n"
			<< "\t8: Change Master Key\n\n"
			<< "\t9: Exit\n";

		cout << "\n\tEnter your choice: ";
		cin >> choice;
		system("cls");
		int ID = 0;
		switch (choice) {
		case '1':
			obj.CreateAccount();
			break;
		case '2':
			cout << "Enter Id of Customer\n";
			cin >> ID;
			obj.ModifyCustomerData(ID);
			break;
		case '3':
			cout << "Enter Id of Customer\n";
			cin >> ID;
			obj.ShowData(ID);
			break;
		case '4':
			cout << "Enter Master key\n";
			int masterkey;
			cin >> masterkey;
			obj.ShowAllFromFile(masterkey);
			break;
		case '5':
			cout << "Enter Id of Customer\n";
			cin >> ID;
			obj.DeleteAccount(ID);
			break;
		case '6':
			cout << "Enter Id of Customer\n";
			cin >> ID;
			obj.AddDeposit(ID);
			break;
		case '7':
			cout << "Enter Id of Customer\n";
			cin >> ID;
			obj.Withdraw(ID);
			break;
		case '8':
			cout << "Enter Previous Key: ";
			int prevkey; cin >> prevkey;
			obj.ChangeMasterKey(prevkey);
			break;
		case '9':
			end();
			break;
		default:
			cout << "INVALID INPUT!!!!\n";
			cout << "\a";
		}
		system("pause");
		system("cls");
	} while (choice != '9');
}

void end() {
	cout << "Thanks for using my code\n"
		<< "Made by Muhammad Asif\n"
		<< "email: asifdhillon25@gmail.com\n"
		<< "Phone: +923166588770\n";
}
