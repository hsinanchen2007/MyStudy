//檔案名稱：d:\C++17\C1703.cpp
#include <iostream>
#include <string>
using namespace std;

class Student	//自定Student資料類別
{
	int student_id;
	char student_name[40];
public:
	friend istream& operator >> (istream& in, Student& obj) {
		in >> obj.student_id >> obj.student_name;
		return in;
	}
	friend ostream& operator << (ostream& out, Student& obj) {
		out << obj.student_id << '\t' << obj.student_name;
		return out;
	}
};

struct link	//定義link資料結構
{
	Student data;
	link *next;
};

class Stack	//定義堆疊資料類別
{
	link *stackPtr;	//堆疊指標
public:
	Stack() { stackPtr = NULL; }	//建立者
	void push (Student obj); 	//宣告推入資料原型
	Student pop();	//宣告取回資料原型
};

void Stack::push (Student obj) 	//定義推入資料函數
{
	link *newPtr = new link;
	newPtr->data = obj;
	newPtr->next = stackPtr;
	stackPtr = newPtr;
}

Student Stack::pop()	//定義取回資料函數
{
	link *tempPtr = stackPtr;
	Student tempData;
	string error = "堆疊空了！\n";
	if (stackPtr == NULL) {
		throw error;
	}
	else {
		tempData = tempPtr->data;
		stackPtr = stackPtr->next;
		delete tempPtr;
	}
	return tempData;
}

int main(int argc, char** argv)
{
	Student studata;	//定義Student物件
	Stack ls;	//定義Stack物件
	char n;

	try {
		while(1) {
			cout << "1.推入資料項  2.取出資料項  0.結束  請選擇(1,2或0): ";
			cin >> n;
			switch (n) {
				case '1':
					cout << "請輸入學號與姓名：" ;
					cin >> studata;
					ls.push(studata);
					break;
				case '2':
					studata = ls.pop();
					cout << studata << endl;
					break;
				case '0':
					exit(0);
			}
			cout << endl;
		}
	} catch (string error) {
		cout << error;
	}
	return 0;
}
