#pragma once
class Binary {

    int MasterKey;
public:
    Binary();//constructor will get key automatically from file
    void ChangeMasterKey(int PreviousKey);//to change master key
    int GetMasterkey();//to read key from file
    void CreateAccount();
    void ShowData(int ID);
    void ModifyCustomerData(int ID);
    void ShowAllFromFile(int MasterKey);
    void DeleteAccount(int ID);
    void AddDeposit(int ID);
    void Withdraw(int ID);
    bool checkSamekey(int ID);//it will check if two customers have same key

};

