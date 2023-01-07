//�ɮצW�١Gd:\C++17\C1701.cpp
#include <iostream>
using namespace std;

class Student	//�۩wStudent���
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
	Student data;	//Student���A���
	link *next;	//link���A����
};

class linklist	//��C������O
{
	link *firstPtr;	//��C�_�l����
	link *lastPtr;	//��C��������
public:
	linklist() { firstPtr = lastPtr = NULL; }	//�إߪ�
	void addFront (Student obj);	//�ŧi���J�Ĥ@���쫬
	void addBack (Student obj);	//�ŧi���J�̫ᶵ�쫬
	void showItem();	//�ŧi��ܦ�C�쫬
};

void linklist::addFront (Student obj)	//�w�q���J�Ĥ@�����
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

void linklist::addBack (Student obj)	//�w�q���J�̫ᶵ���
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

void linklist::showItem()	//�w�q��ܦ�C��ƨ��
{
	link *currentPtr = firstPtr;
	while( currentPtr != NULL) {
		cout << currentPtr->data << endl;
		currentPtr = currentPtr->next;
	}
}

int main(int argc, char** argv)
{
	Student studata;	//�w�qStudent����
	linklist ls;	//�w�qlinklist����
	char n;

	while(1) {
		cout << "1.���J�Ĥ@��  2.���J�̫ᶵ  0.����  �п��(1,2��0): ";
		cin >> n;
		switch (n) {
			case '1':
				cout << "�п�J�Ǹ��P�m�W�G" ;
				cin >> studata;
				ls.addFront(studata);
				ls.showItem();
				break;
			case '2':
				cout << "�п�J�Ǹ��P�m�W�G" ;
				cin >> studata;
				ls.addBack(studata);
				ls.showItem();
				break;
			case '0':
				return 0;
		}
		cout << endl;
	}
	return 0;
}
