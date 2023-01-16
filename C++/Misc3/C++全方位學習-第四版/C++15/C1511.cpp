//檔案名稱：d:\C++15\C1511.cpp
#include <iostream>
#include <fstream>
using namespace std;

struct Student
{
	int student_id;
	char student_name[40];
};

int main(int argc, char** argv)
{
	Student stuData;
	ifstream filePtr;

	filePtr.open("d:\\C++15\\C1505.dat", ios::binary|ios::in);	//開啟輸入檔
	if(!filePtr) {
		cout << "開啟輸入檔錯誤！\n";
		exit(1);	//非正常結束程式
	} else {
		filePtr.seekg(0, ios::end);	//移動指標到檔尾
		int endpos = filePtr.tellg();	//取得檔案位元組數
		int n = endpos / sizeof(stuData);	//除以緩衝器大小
		cout << "d:\\C++15\\C1505.dat 共有 " << n << " 筆資料";	//顯示資料筆數
	}
	filePtr.close();
	cout << endl;
	return 0;
}
