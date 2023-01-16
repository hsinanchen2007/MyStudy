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

// --------- 主程式 ------------------------
int main()
{
	int Size;
	cout << "請輸入 Employee 的數目:\n";
	cin >> Size;
	Employee* pE = new Employee[Size];
	delete [] pE;
	system("pause");
	return 0;
}
