#include "BANK.h"
#include <iostream>
#include <iomanip>
#include "BANK.h"
using namespace std;

BANK::BANK():Balance(0),Pincode(0)
{
}

bool BANK::CreateAccount() {

    cin.ignore();
    cout << "Enter Customer Name:  ";
    cin.getline(CustomerName, 20);
    cout << "Enter Customer 4 digit pincode (only use integers): " ;
    cin >> Pincode;
    cout << "Please deposit amount 500 to create account: ";
    cin >> Balance;
    if (Balance < 500)
    {
        cout << "Amount less than Five Hundred !!!\a\n";
        cout << "Account can not be created\n";
        return false;
    }

    return true;

}

void BANK::ShowData() {

    cout << "Student Name: "<<setw(10)<<left << CustomerName << endl;
    cout << "Pincode: " << setw(10) << left << Pincode << endl;
    cout << "Balance: " << setw(10) << left << '$' << Balance << "\n";



}

int BANK::GetcustomerId() const {
    return Pincode;
}

void BANK::Modify() {
    cout << "\n\n\t***Enter New Data***" << endl;
    cin.ignore();
    cout << "Enter New Customer Name:  ";
    cin.getline(CustomerName, 20);
    cout << "Enter NEW Customer 4 digit pincode (only use integers): ";
    cin >> Pincode;
}

void BANK::showAll() {


    cout << left << setw(15) << CustomerName
        << setw(16) << Pincode
        << setw(3) << "$ " << Balance << endl;
        

}

void BANK::AddDeposit()
{
    double amount;
    cout << "Enter amount to deposit: ";
    cin >> amount;
    Balance += amount;

}

void BANK::Withdraw()
{
    double amount;
    cout << "Enter amount to Withdraw: ";
    cin >> amount;
    if (amount > Balance)
    {
        cout << "insufficient Balance\a";
        return;
    }
    Balance -= amount;
}
