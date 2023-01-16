//檔案名稱：d:\C++15\C1509.cpp
#include <iostream>
#include <fstream>
using namespace std;

class Student	//定義Student類別
{
protected:
	int student_id;
	char student_name[40];
public:
	void showdata()	//顯示資料函數
	{
		cout << student_id << '\t' << student_name << endl;
	}
};

int main(int argc, char** argv)
{
	Student stuData;
	ifstream filePtr;
	int n;

	filePtr.open("d:\\C++15\\C1505.dat", ios::binary|ios::in);	//開啟輸入檔
	if(!filePtr) {	//若開啟檔案錯誤
		cout << "開啟輸入檔錯誤！\n";
		system("PAUSE");
		exit(1);	//非正常結束程式
	} else {			//否則
		cout << "請輸入要讀取第幾筆資料：";
		cin >> n;
		int pos = (n-1) * sizeof(stuData);	//計算資料位置
		filePtr.seekg(pos, ios::beg);	//移動get指標
		filePtr.read((char*) &stuData, sizeof(stuData));	//讀取資料
		stuData.showdata();	//呼叫顯示資料函數
	}
	filePtr.close();
	return 0;
}
