//檔案名稱：d:\C++17\C1702.cpp
#include <iostream>
using namespace std;

class Student	// 自定Student資料類別
{
	int student_id;
	char student_name[40];
public:
	friend istream& operator >> (istream& in, Student& obj)
	{
		in >> obj.student_id >> obj.student_name;
		return in;
	}
	friend ostream& operator << (ostream& out, Student& obj)
	{
		out << obj.student_id << '\t' << obj.student_name;
		return out;
	}
};

struct link	//定義link資料結構
{
	Student data;	//Student型態資料
	link *next;	//link型態指標
};

class linklist	//定義串列資料類別
{
	link *firstPtr;	//串列起始指標
	link *lastPtr;	//串列結束指標
public:
	linklist() { firstPtr = lastPtr = NULL; }	//建立者
	void addFront (Student obj);	//宣告插入第一項原型
	void addBack (Student obj);	//宣告插入最後項原型
	void delFront();	//宣告刪除第一項原型
	void delBack();	//宣告刪除最後項原型
	void showItem();	//宣告顯示串列原型
};

void linklist::addFront (Student obj)	//定義插入第一項函數
{
	link *newPtr = new link;
	newPtr->data = obj;
	if (firstPtr == NULL) {
		firstPtr = lastPtr = newPtr;
		lastPtr->next = NULL;
	}
	else {
		newPtr->next = firstPtr;
		firstPtr = newPtr;
	}
}

void linklist::addBack (Student obj)	//定義插入最後項函數
{
	link *newPtr = new link;
	newPtr->data = obj;
	if (firstPtr == NULL) {
		firstPtr = lastPtr = newPtr;
		lastPtr->next = NULL;
	}
	else {
		lastPtr->next = newPtr;
		lastPtr = newPtr;
		lastPtr->next = NULL;
	}
}

void linklist::delFront()	//定義刪除第一項函數
{
	link *tempPtr = firstPtr;
	if (firstPtr == NULL) 
		return;
	else {
		firstPtr = firstPtr->next;
		delete tempPtr;
	}
}

void linklist::delBack()	//定義刪除最後項函數
{
	link *tempPtr = lastPtr;
	if (firstPtr == NULL) 
		return;
	else {
		if (firstPtr == lastPtr)
			firstPtr = lastPtr = NULL;
		else {
			link *currentPtr = firstPtr;
			while(currentPtr->next != lastPtr)
				currentPtr = currentPtr->next;
			lastPtr = currentPtr;
			lastPtr->next = NULL;
		}
	}
	delete tempPtr;
}

void linklist::showItem()	//定義顯示串列資料函數
{
	link *currentPtr = firstPtr;
	while( currentPtr != NULL)
	{
		cout << currentPtr->data << endl;
		currentPtr = currentPtr->next;
	}
}

int main(int argc, char** argv)
{
	Student studata;	//定義Student物件
	linklist ls;	//定義linklist物件
	char n;

	cout << "1.插入第一項\n2.插入最後項\n"
		 << "3.刪除第一項\n4.刪除最後項\n"
		 << "0.結束\n";
	while(1) {
		cout << "請選擇(1-4 或 0): ";
		cin >> n;
		switch (n) {
			case '1':
				cout << "請輸入學號與姓名：" ;
				cin >> studata;
				ls.addFront(studata);
				ls.showItem();
				break;
			case '2':
				cout << "請輸入學號與姓名：" ;
				cin >> studata;
				ls.addBack(studata);
				ls.showItem();
				break;
			case '3':
				ls.delFront();
				ls.showItem();
				break;
			case '4':
				ls.delBack();
				ls.showItem();
				break;
			case '0':
				return 0;
		}
		cout << endl;
	}
	return 0;
}
