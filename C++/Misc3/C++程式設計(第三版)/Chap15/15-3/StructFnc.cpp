// StructFnc.cpp
// --------------------------------------
#include <iostream>
#include <cstring>
using namespace std;

struct Employee
{
	char  Name[20];
	char  Phone[10];
	int  Id;           
};

void ShowMember(Employee A)
{
	cout << "��ƪ��ԲӤ��e�O:\n" 
		    << "�m�W    : " << A.Name  << '\n'
		    << "�q�ܸ��X: " << A.Phone << '\n'
		    << "�s��    : " << A.Id    << endl;
	return;
}
void ChangeName (Employee& A, char NewName[])
	{ strcpy(A.Name, NewName); return; }

// ----- �D�{�� ----------------------------
int main()
{
	Employee Ea = {"Ann",    "02384125", 105};
	Employee Eb = {"Joanne", "03544132", 106};
	ShowMember(Ea);
	ShowMember(Eb);
	ChangeName(Ea, "Jackson");
	cout << "���� ChangeName() ��:\n";
	ShowMember(Ea);
	system("pause");
	return 0;
}
