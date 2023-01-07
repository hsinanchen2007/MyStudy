//檔案名稱：d:\C++15\C1505.cpp
#include <iostream>
#include <fstream>
using namespace std;

class Student	//定義Student類別
{
protected:		//保護區
	int student_id;
	char student_name[40];
public:			//公用區
	int getid()	//取得學號函數
	{
		return student_id;
	}
	void setdata()	//輸入並寫入緩衝區函數
	{
		cout << "請輸入學號與姓名 (輸入 0 0 則結束)：";
		cin >> student_id >> student_name;	//輸入學號與姓名
	}
};

int main(int argc, char** argv)
{
	Student stuData;	//建立類別物件
	ofstream filePtr;	//建立輸出檔案物件
	filePtr.open("d:\\C++15\\C1505.dat", ios::binary);	//開啟二進位檔

	if(!filePtr) {	//若檔案代號錯誤
		cout << "開啟檔案錯誤！\n";
		system("PAUSE");
		exit(1);	//非正常結束程式
	} else {		//則
		while(1) {	//輸入並寫入資料迴圈
			stuData.setdata();	//輸入資料到緩衝區
			if(stuData.getid() != 0)	//若學號不等於0則
				filePtr.write((char*)&stuData,	//緩衝區資料寫入檔案
				    sizeof(stuData));	//寫入長度=緩衝區大小
			else	//若學號等於0則
				break;	//結束輸入
		}
	}
	filePtr.close();
	return 0;
}
