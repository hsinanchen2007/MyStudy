// DynStruct.cpp
// --------------------------------------
#include <iostream>
using namespace std;

struct Employee
{
	char  Name[20];
	char  Phone[10];
	int  Id;           
};

// --------- �D�{�� ------------------------
int main()
{
	int Size;
	cout << "�п�J Employee ���ƥ�:\n";
	cin >> Size;
	Employee* pE = new Employee[Size];
	delete [] pE;
	system("pause");
	return 0;
}
