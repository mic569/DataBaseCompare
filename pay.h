#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
class Teller;  // a forward reference, needed for one friend function header
class Manager
{
public:
	Manager();  // sets bonus at baseline $500.00
	int GetID();
	void SetLastName(string thename);
	void SetID(int theID);
	void SetDept(string thedept);
	void SetSalary(double thesalary);
	string GetLastName();
	double TotalPay();  // annual: salary plus bonus
	friend string CompareM1andM2(Manager m1, Manager m2); // send back last name of higher-paid
	friend string CompareM1andT1(Manager m1, Teller t1);  //send back last name of higher-paid
private:
	int ID;
	string lastname, dept;
	double salary, bonus;
};
class Teller
{
public:
	Teller();  // sets monthly pay rate at $3900.00

	void SetID(int theID);
	void SetLastName(string thename);
	void SetSuper(string thesuper);
	void SetStatus(int thestatus);
	int GetID();
	string GetLastName();
	int GetStatus();
	double TotalPay();  // annual, depends on status code; part-timers get one-half the full-time rate
	friend string CompareM1andT1(Manager m1, Teller t1);  //send back last name of higher-paid
private:
	int id, statuscode;  // 1 is full time,  2 is part time
	string lastname, supervisor;  // supervisor is the teller's manager's last name
	double monthly;
};
void ReadMData(ifstream &file, Manager arry[], int &nmbrm);
void ReadTData(ifstream &file, Teller ary[], int &nmbrt);
