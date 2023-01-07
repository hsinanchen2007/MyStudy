//�ɮצW�١Gd:\C++17\C1704.cpp
#include <iostream>
#include <string>
using namespace std;

class Student	//�۩wStudent������O
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

struct link	//�w�qlink��Ƶ��c
{
	Student data;
	link *next;
};

class Queue	//�w�q��C������O
{
	link *headPtr;	//��C�_�l����
	link *tailPtr;	//��C��������
public:
	Queue() { headPtr = tailPtr = NULL; }	//�إߪ�
	void push (Student obj);	//�ŧi���J��ƭ쫬
	Student pop();	//�ŧi���^��ƭ쫬
};

void Queue::push (Student obj)	//�w�q���J��ƭ쫬
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

Student Queue::pop()	//�w�q���^��ƭ쫬
{
	link *tempPtr = tailPtr;
	Student tempData;
	string error = "��C�ŤF�I\n";
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
	Student studata;	//�w�qStudent����
	Queue ls;	//�w�qQueue����
	char n;

	try {
		while(true) {
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
					exit(1);
			}
			cout << endl;
		}
	} catch (string error) {
		cout << error;
	}
	return 0;
}
