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

// ----- 主程式 ----------------------------
int main()
{
	const int Size = 2;
	Employee Officer[Size];
	cout << "共 " << Size << " 個 Officers:\n";

	for (int i=0; i<Size; i++)
	{
		cout << "請輸入 Officer[" << i << "] 的姓名: ";
		cin.getline(Officer[i].Name, NameSize, '\n');
		cout << "電話號碼: ";
		cin.getline(Officer[i].Phone,PhoneSize, '\n');
	}

	for (int i=0; i<Size; i++)
	{
		cout << "Officer["   << i << "] 的資料是:\n"
			    << "姓名    : " << Officer[i].Name  << '\n'
			    << "電話號碼: " << Officer[i].Phone << '\n';
	}
	system("pause");
	return 0;
}
