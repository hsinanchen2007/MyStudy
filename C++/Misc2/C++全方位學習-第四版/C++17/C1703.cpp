//�ɮצW�١Gd:\C++17\C1703.cpp
#include <iostream>
#include <string>
using namespace std;

class Student	//�۩wStudent������O
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

struct link	//�w�qlink��Ƶ��c
{
	Student data;
	link *next;
};

class Stack	//�w�q���|������O
{
	link *stackPtr;	//���|����
public:
	Stack() { stackPtr = NULL; }	//�إߪ�
	void push (Student obj); 	//�ŧi���J��ƭ쫬
	Student pop();	//�ŧi���^��ƭ쫬
};

void Stack::push (Student obj) 	//�w�q���J��ƨ��
{
	link *newPtr = new link;
	newPtr->data = obj;
	newPtr->next = stackPtr;
	stackPtr = newPtr;
}

Student Stack::pop()	//�w�q���^��ƨ��
{
	link *tempPtr = stackPtr;
	Student tempData;
	string error = "���|�ŤF�I\n";
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
	Student studata;	//�w�qStudent����
	Stack ls;	//�w�qStack����
	char n;

	try {
		while(1) {
			cout << "1.���J��ƶ�  2.���X��ƶ�  0.����  �п��(1,2��0): ";
			cin >> n;
			switch (n) {
				case '1':
					cout << "�п�J�Ǹ��P�m�W�G" ;
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
