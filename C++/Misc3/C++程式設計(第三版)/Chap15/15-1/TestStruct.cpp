// TestStruct.cpp
// --------------------------------------
#include <iostream>
using namespace std;

struct Employee
{
	char  Name[20];
	char  Phone[10];
	int  Id;           
};
// ----- �D�{�� ----------------------------
int main()
{
	Employee Ea = {"Nicole", "02384125", 105};
	Employee Eb = {"Joanne", "03544132", 106};

	cout << "Ea ����ƬO:\n" 
		    << "�m�W    : " << Ea.Name  << endl
		    << "�q�ܸ��X: " << Ea.Phone  << endl
		    << "�s��    : " << Ea.Id     << endl;
	cout << "Eb ����ƬO:\n" 
		    << "�m�W    : " << Eb.Name   << '\n'
		    << "�q�ܸ��X: " << Eb.Phone  << '\n'
		    << "�s��    : " << Eb.Id      << endl;

	system("pause");
	return 0;
}
