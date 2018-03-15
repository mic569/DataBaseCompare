#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "pay.h"
using namespace std;
//#include "Source.cpp"



Manager::Manager()
{
    bonus = 500;
}

void Manager::SetLastName(string thename)
{
    lastname = thename;
}
string Manager::GetLastName()
{
    return lastname;
}

void Manager::SetID(int theID)
{
    ID = theID;
}
int Manager::GetID()
{
    return ID;
}
void Manager::SetDept(string thedept)
{
    dept = thedept;
}
void Manager::SetSalary(double thesalary)
{
    salary = thesalary;
}
double Manager::TotalPay()
{
    double allpay = salary + bonus;
    return allpay;
}
string CompareM1andM2(Manager m1, Manager m2) // send back last name of higher-paid
{
    string paid;
    if (m1.TotalPay() > m2.TotalPay())
        paid = m1.GetLastName();
    else if (m1.TotalPay() < m2.TotalPay())
        paid = m2.GetLastName();
    else
        paid = " Have equal pay ";
    return paid;
}
string CompareM1andT1(Manager m1, Teller t1)  //send back last name of higher-paid
{
    string fullpaid;
    if (m1.TotalPay() > t1.TotalPay())
        fullpaid = m1.GetLastName();
    else if (m1.TotalPay() < t1.TotalPay())
        fullpaid = t1.GetLastName();
    else
        fullpaid = " Have equal pay ";
    return fullpaid;
}


//FUNCTIONS FOR THE TELLER CLASS
Teller::Teller()
{
    monthly = 3900;
}
void Teller::SetID(int theID)
{
    id = theID;
}

int Teller::GetID()
{
    return id;
}

void Teller::SetLastName(string thename)
{
    lastname = thename;
}

string Teller::GetLastName()
{
    return lastname;
}
void Teller::SetSuper(string thesuper)
{
    supervisor = thesuper;
}
void Teller::SetStatus(int thestatus)
{
    statuscode = thestatus;
}

int Teller::GetStatus()
{
    return statuscode;
}
double Teller::TotalPay()
{
    double entirepay;
    if (GetStatus() == 1)
        entirepay = monthly *12.0;
    else
        entirepay = (monthly / 2) * 12.0;
    return entirepay;
}

//ORDINARY FUNCTIONS
void ReadMData(ifstream &file, Manager arry[], int &nmbrm)
{
    int temp;
    string department, lastn;
    double tempPay;
    file >> temp;
    while (!file.eof())
    {
        temp = arry[nmbrm].GetID();
        file >> lastn;
        arry[nmbrm].SetLastName(lastn);
        file >> department;
        file >> tempPay;
        arry[nmbrm].SetSalary(tempPay);
        file >> temp;
        nmbrm++; //Subscript is n+1
    }
    return;
}

void ReadTData(ifstream &file, Teller ary[], int &nmbrt)
{
    int Id, status;
    string lastnm, firstnm;
    file >> Id;
    while (!file.eof())
    {
        ary[nmbrt].SetID(Id);
        file >> lastnm;
         ary[nmbrt].SetLastName(lastnm);
         file >> firstnm;
         file >> status;
        ary[nmbrt].SetStatus(status);
        nmbrt++;
        file >> Id;
    }
    return;
}
