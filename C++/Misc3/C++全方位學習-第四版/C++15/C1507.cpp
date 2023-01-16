//檔案名稱：d:\C++15\C1507.cpp
#include <iostream>
#include <fstream>
using namespace std;

class Student	//定義 Student 類別
{
protected:		//保護區
	int student_id;
	char student_name[40];
public:			//公用區
	void showdata()	//顯示資料函數
	{
		cout << student_id << '\t' << student_name << endl;
	}
};

int main(int argc, char** argv)
{
	Student stuData;	//建立類別物件
	ifstream filePtr;	//建立輸入檔案物件
	filePtr.open("d:\\C++15\\C1505.dat", ios::in);	//開啟輸入檔
	if(!filePtr) {	//若檔案代號錯誤
		cout << "開啟輸入檔錯誤！\n";
		system("PAUSE");
		exit(1);	//非正常結束程式
	} else {		//則
		filePtr.read((char*) &stuData,	//讀取資料到緩衝區
			sizeof(stuData));	//讀取長度=緩衝區大小
		while(!filePtr.eof()) {	//讀取資料迴圈
				stuData.showdata();	//呼叫顯示資料函數
				filePtr.read((char*) &stuData,	//讀取資料到緩衝區
				    sizeof(stuData));	//讀取長度=緩衝區大小
		}
	}
	filePtr.close();
	return 0;
}
