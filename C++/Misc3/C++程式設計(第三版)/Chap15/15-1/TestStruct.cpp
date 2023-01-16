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
// ----- 主程式 ----------------------------
int main()
{
	Employee Ea = {"Nicole", "02384125", 105};
	Employee Eb = {"Joanne", "03544132", 106};

	cout << "Ea 的資料是:\n" 
		    << "姓名    : " << Ea.Name  << endl
		    << "電話號碼: " << Ea.Phone  << endl
		    << "編號    : " << Ea.Id     << endl;
	cout << "Eb 的資料是:\n" 
		    << "姓名    : " << Eb.Name   << '\n'
		    << "電話號碼: " << Eb.Phone  << '\n'
		    << "編號    : " << Eb.Id      << endl;

	system("pause");
	return 0;
}
