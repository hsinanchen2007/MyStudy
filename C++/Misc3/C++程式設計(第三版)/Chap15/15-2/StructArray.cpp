// StructArray.cpp
// --------------------------------------
#include <iostream>
using namespace std;

const int NameSize  = 20;
const int PhoneSize = 11;

struct Employee
{
	char  Name[NameSize];
	char  Phone[PhoneSize];
};

// ----- �D�{�� ----------------------------
int main()
{
	const int Size = 2;
	Employee Officer[Size];
	cout << "�@ " << Size << " �� Officers:\n";

	for (int i=0; i<Size; i++)
	{
		cout << "�п�J Officer[" << i << "] ���m�W: ";
		cin.getline(Officer[i].Name, NameSize, '\n');
		cout << "�q�ܸ��X: ";
		cin.getline(Officer[i].Phone,PhoneSize, '\n');
	}

	for (int i=0; i<Size; i++)
	{
		cout << "Officer["   << i << "] ����ƬO:\n"
			    << "�m�W    : " << Officer[i].Name  << '\n'
			    << "�q�ܸ��X: " << Officer[i].Phone << '\n';
	}
	system("pause");
	return 0;
}
