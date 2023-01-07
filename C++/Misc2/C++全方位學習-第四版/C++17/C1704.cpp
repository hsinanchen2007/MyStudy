//檔案名稱：d:\C++17\C1704.cpp
#include <iostream>
#include <string>
using namespace std;

class Student	//自定Student資料類別
{
	int student_id;
	char student_name[40];
public:
	friend istream &operator>> (istream &in, Student &obj) {
		in >> obj.student_id >> obj.student_name;
		return in;
	}
	friend ostream &operator<< (ostream &out, Student &obj) {
		out << obj.student_id << '\t' << obj.student_name;
		return out;
	}
};

struct link	//定義link資料結構
{
	Student data;
	link *next;
};

class Queue	//定義佇列資料類別
{
	link *headPtr;	//佇列起始指標
	link *tailPtr;	//佇列結束指標
public:
	Queue() { headPtr = tailPtr = NULL; }	//建立者
	void push (Student obj);	//宣告推入資料原型
	Student pop();	//宣告取回資料原型
};

void Queue::push (Student obj)	//定義推入資料原型
{
	link *newPtr = new link;
	newPtr->data = obj;
	if (headPtr == NULL) {
		headPtr = tailPtr = newPtr;
		tailPtr->next = NULL;
	}
	else {
		newPtr->next = headPtr;
		headPtr = newPtr;
	}
}

Student Queue::pop()	//定義取回資料原型
{
	link *tempPtr = tailPtr;
	Student tempData;
	string error = "佇列空了！\n";
	if (headPtr == NULL) {
		throw error;
	}
	else {
		if (headPtr == tailPtr)
			headPtr = tailPtr = NULL;
		else {
			link *currentPtr = headPtr;
			while(currentPtr->next != tailPtr)
				currentPtr = currentPtr->next;
			tailPtr = currentPtr;
			tailPtr->next = NULL;
		}
		tempData = tempPtr->data;
		delete tempPtr;
	}
	return tempData;
}

int main(int argc, char** argv)
{
	Student studata;	//定義Student物件
	Queue ls;	//定義Queue物件
	char n;

	try {
		while(true) {
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
					exit(1);
			}
			cout << endl;
		}
	} catch (string error) {
		cout << error;
	}
	return 0;
}
