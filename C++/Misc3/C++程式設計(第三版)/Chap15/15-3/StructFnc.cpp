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
	cout << "資料的詳細內容是:\n" 
		    << "姓名    : " << A.Name  << '\n'
		    << "電話號碼: " << A.Phone << '\n'
		    << "編號    : " << A.Id    << endl;
	return;
}
void ChangeName (Employee& A, char NewName[])
	{ strcpy(A.Name, NewName); return; }

// ----- 主程式 ----------------------------
int main()
{
	Employee Ea = {"Ann",    "02384125", 105};
	Employee Eb = {"Joanne", "03544132", 106};
	ShowMember(Ea);
	ShowMember(Eb);
	ChangeName(Ea, "Jackson");
	cout << "執行 ChangeName() 後:\n";
	ShowMember(Ea);
	system("pause");
	return 0;
}
