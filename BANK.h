#pragma once
class BANK {

    char CustomerName[20];
    double Balance;
    int Pincode;
public:
    //these functions will perform actions on single instances of customers 

    BANK();
    bool CreateAccount();
    void ShowData();
    int GetcustomerId()const;
    void Modify();
    void showAll();
    void AddDeposit();
    void Withdraw();

};