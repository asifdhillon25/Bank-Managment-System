#include "Binary.h"
#include <iostream>
#include <fstream>
#include "BANK.h"
using namespace std;


Binary::Binary()
{
    MasterKey = GetMasterkey();//will read master key from file 
}

void Binary::ChangeMasterKey(int PreviousKey)
{


    fstream Datafile;
    Datafile.open("MasterKey.dat", ios::out | ios::binary);
    if (!Datafile)
    {
        cout << "Error! File not open " << endl;
        return;
    }

    if (PreviousKey == GetMasterkey())
    {
        cout << "Enter New Master Key\n";
        int MKEY;
        cin >> MKEY;
        Datafile.write(reinterpret_cast<char*>(&MKEY), sizeof(MKEY));
        Datafile.close();
    }
    else
    {
        cout << "Wrong Previous Key\n";
    }
    

}

int Binary::GetMasterkey()
{
    
    fstream Datafile;
    Datafile.open("MasterKey.dat", ios::in | ios::binary);
    if (!Datafile)
    {
        cerr << "Error! File not open " << endl;
       
    }
    Datafile.read(reinterpret_cast<char*>(&MasterKey), sizeof(MasterKey));
    Datafile.close();
    return MasterKey;
}

void Binary::CreateAccount() {

    BANK obj;
    fstream Datafile;
    Datafile.open("Bankdata.dat", ios::out | ios::binary | ios::app);
    if (!Datafile)
    {
        cout << "Error! File not open " << endl;
        return;
    }
    obj.CreateAccount();

    if (checkSamekey(obj.GetcustomerId()))
    {
        cout << "Pin Code Already Exist!!! Please use Another\n\a";
        Datafile.close();
        return;
    }
   

    Datafile.write(reinterpret_cast<char*>(&obj), sizeof(obj));
    Datafile.close();
    cout << "Data has been stored" << endl;
}

void Binary::ShowData(int ID) {

    bool flag = false;
    BANK obj;
    fstream Datafile;
    Datafile.open("Bankdata.dat", ios::in | ios::binary);
    if (!Datafile)
    {
        cout << "Error! File not open " << endl;
        return;
    }


    while (Datafile.read(reinterpret_cast<char*>(&obj), sizeof(obj)))
    {
        if (obj.GetcustomerId() == ID)
        {
            obj.ShowData();
            flag = true;
        }
    }
    if (!flag)
    {
        cout << "No Data with this ID" << endl;
    }
    Datafile.close();


}

void Binary::ModifyCustomerData(int ID) {

    bool flag = false;
    BANK obj;
    fstream Datafile;
    Datafile.open("Bankdata.dat", ios::in | ios::out | ios::binary);
    if (!Datafile)
    {
        cout << "Error! File not open " << endl;
        return;
    }


    while (Datafile.read(reinterpret_cast<char*>(&obj), sizeof(obj)) && !flag)
    {
        

        if (obj.GetcustomerId() == ID)
        {
            obj.ShowData();
            
            obj.Modify();
            int pos = (-1) * static_cast<int>(sizeof(obj));
            Datafile.seekp(pos, ios::cur);
            Datafile.write(reinterpret_cast<char*>(&obj), sizeof(obj));
            flag = true;
        }
    }
    if (!flag)
    {
        cout << "No Data with this ID" << endl;
    }
    Datafile.close();

}

void Binary::ShowAllFromFile(int MasterKey) {

    if (MasterKey != GetMasterkey())
    {
        cout << "Wrong Master Key \n";
        return;
    }

    BANK obj;
    ifstream Datafile;
    Datafile.open("Bankdata.dat", ios::binary);
    if (!Datafile)
    {
        cout << "Error! File not open " << endl;
        return;
    }
    cout << "================================================\n";
    cout << "CustomerName" << "   " << "PinCode" << "         " << "Balance"<< endl;
    cout << "================================================\n";

    while (Datafile.read(reinterpret_cast<char*>(&obj), sizeof(obj))) {
        obj.showAll();
    }
    Datafile.close();
}

void Binary::DeleteAccount(int ID) {

    BANK obj;
    ifstream Datafile;
    ofstream TempFile;

    TempFile.open("Temp.dat", ios::binary);
    Datafile.open("Bankdata.dat", ios::binary);
    if (!Datafile || !TempFile)
    {
        cout << "Error! File not open " << endl;
        return;
    }
    Datafile.seekg(0, ios::beg);

    while (Datafile.read(reinterpret_cast<char*>(&obj), sizeof(obj))) {

        if (ID == obj.GetcustomerId())
        {
            obj.ShowData();
        }
        if (ID != obj.GetcustomerId())
        {
            TempFile.write(reinterpret_cast<char*>(&obj), sizeof(obj));
        }
    }
    Datafile.close();
    TempFile.close();

    remove("Bankdata.dat");
    rename("Temp.dat", "Bankdata.dat");
    cout << "\nThis record has been Deleted\n";
}

void Binary::AddDeposit(int ID)
{
    bool flag = false;
    BANK obj;
    fstream Datafile;
    Datafile.open("Bankdata.dat", ios::in | ios::out | ios::binary);
    if (!Datafile)
    {
        cout << "Error! File not open " << endl;
        return;
    }

    while (Datafile.read(reinterpret_cast<char*>(&obj), sizeof(obj)) && !flag)
    {
        

        if (obj.GetcustomerId() == ID)
        {
            obj.ShowData();

            obj.AddDeposit();
            
            int pos = (-1) * static_cast<int>(sizeof(obj));
            Datafile.seekp(pos, ios::cur);
            Datafile.write(reinterpret_cast<char*>(&obj), sizeof(obj));
            flag = true;
        }
    }
    if (!flag)
    {
        cout << "No Data with this ID" << endl;
    }
    Datafile.close();

}

void Binary::Withdraw(int ID)
{
    bool flag = false;
    BANK obj;
    fstream Datafile;
    Datafile.open("Bankdata.dat", ios::in | ios::out | ios::binary);
    if (!Datafile)
    {
        cout << "Error! File not open " << endl;
        return;
    }

    while (Datafile.read(reinterpret_cast<char*>(&obj), sizeof(obj)) && !flag)
    {
       

        if (obj.GetcustomerId() == ID)
        {
            obj.ShowData();

            obj.Withdraw();
            int pos = (-1) * static_cast<int>(sizeof(obj));
            Datafile.seekp(pos, ios::cur);
            Datafile.write(reinterpret_cast<char*>(&obj), sizeof(obj));
            flag = true;
        }
    }
    if (!flag)
    {
        cout << "No Data with this ID" << endl;
    }
    Datafile.close();
}

bool Binary::checkSamekey(int ID)
{
    bool flag = false;
    BANK obj;
    fstream Datafile;
    Datafile.open("Bankdata.dat", ios::in |  ios::binary);
    if (!Datafile)
    {
        cout << "Error! File not open " << endl;
        return 0;
    }

    while (Datafile.read(reinterpret_cast<char*>(&obj), sizeof(obj)) && !flag)
    {
        if (obj.GetcustomerId() == ID)
        {
            flag = true;
        }
    }
   
    Datafile.close();
    return flag;
}
