//檔案名稱：d:\C++15\C1508.cpp
#include <iostream>
#include <fstream>
using namespace std;

const char filename[] = "d:\\C++15\\C1508.dat";

class Student	//定義Student類別
{
protected:
	int student_id;
	char student_name[40];
public:
	int getId();	//宣告getId函數原型
	void setData();	//宣告setData函數原型
	void showData();	//宣告showData函數原型
	void write();	//宣告write函數原型
	void append();	//宣告append函數原型
	void read();	//宣告read函數原型
};

int Student::getId()	//定義getId函數
{
	return student_id;
}

void Student::setData()	//定義setData函數
{
	cout << "請輸入學號與姓名 (輸入 0 0 則結束)：";
	cin >> student_id >> student_name;
}

void Student::showData()	//定義showData函數
{
	cout << student_id << '\t' << student_name << endl;
}

void Student::write()	//定義write函數
{
	ofstream filePtr;
	filePtr.open(filename, ios::binary | ios::out);
	if(!filePtr) {
		cout << "開啟輸出檔錯誤！\n";
		system("PAUSE");
		exit(1);	//非正常結束程式
	} else {
		while(1) {
			setData();
			if(getId() != 0)
				filePtr.write((char*) this, sizeof(*this));
			else
				break;
		}
	}
	filePtr.close();
}

void Student::append()	//定義append函數
{
	ofstream filePtr;
	filePtr.open(filename, ios::binary | ios::app);
	if(!filePtr) {
		cout << "開啟附加檔錯誤！\n";
		system("PAUSE");
		exit(1);	//非正常結束程式
	} else {
		while(1) {
			setData();
			if(getId() != 0)
				filePtr.write((char*) this, sizeof(*this));
			else
				break;
		}
	}
	filePtr.close();
}

void Student::read()	//定義read函數
{
	ifstream filePtr;
	filePtr.open(filename, ios::binary | ios::in);
	if(!filePtr) {
		cout << "開啟輸入檔錯誤！\n";
		system("PAUSE");
		exit(1);	//非正常結束程式
	} else {
		filePtr.read((char*) this, sizeof(*this));
		while(!filePtr.eof()) {
			showData();
			filePtr.read((char*) this, sizeof(*this));
		}
	}
	filePtr.close();
}

int main(int argc, char** argv)
{
	Student pupil;
	char n;

	while(1)
	{
		cout << "1.寫入  2.附加  3.讀取  "	//Menu
			 << "0.結束  請選擇 (0-3): ";
		cin >> n;
		switch (n)	//比較輸入值
		{
			case '1':	//若輸入值為 1
				pupil.write();	//呼叫寫入二進位檔函數
				break;
			case '2':	//若輸入值為 2
				pupil.append();	//呼叫附加二進位檔函數
				break;
			case '3':	//若輸入值為 3
				pupil.read();	//呼叫讀取二進位檔函數
				break;
			case '0':	//若輸入值為 0
				exit(0);	//結束程式
		}
	}
	return 0;
}
