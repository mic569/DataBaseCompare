#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "pay.h"
#include "FSource.cpp"
using namespace std;


int main()
{
    Manager superV[31];
    Teller workers[96];
    int subMan(0), subTel(0), findMsub1, findMsub2, findTsub1;
    ifstream inputM, inputT;
    inputM.open("e:\\Datafile1.txt");
    inputT.open("e:\\Datafile2.txt");
    if (inputM.fail() || inputT.fail())
    {
        cout << "One of the files cannot open.\n";
        exit(1);
    }

    ReadMData(inputM, superV, subMan);
    ReadTData(inputT, workers, subTel);

    cout << "There are " << (subMan) << " managers.\n";
    cout << setw(20) << "Manager's Name " << setw(20) << "Total Annual Pay\n" << endl;
    for (int i = 0; i< subMan; i++)
    {
        cout << setw(15) << superV[i].GetLastName()
            << setw(15) << superV[i].TotalPay() << endl;
    }

    cout << "There are " << (subMan) << " Tellers.\n";
    cout << setw(20) << "Teller's Name " << setw(20) << "Total Annual Pay\n" << endl;
    for (int i = 0; i< subMan+2;  i++)
    {
        cout << setw(20) << workers[i].GetLastName()
            << setw(20) << workers[i].TotalPay() << endl;
    }

    cout << "Enter the subscripts for two managers you would like to compare ";
    cin >> findMsub2 >> findMsub1;
    cout << CompareM1andM2(superV[findMsub2], superV[findMsub1]) << " Is the manager with the higher annual pay.\n";
    cout <<   "\nEnter the subscripts for a manager and a teller you would like to compare ";
    cin >> findMsub1 >> findTsub1;

    cout << CompareM1andT1(superV[findMsub1], workers[findTsub1]) << " is the person with the higher annual pay\n";

    inputM.close();
    inputM.close();
    return 0;
}
