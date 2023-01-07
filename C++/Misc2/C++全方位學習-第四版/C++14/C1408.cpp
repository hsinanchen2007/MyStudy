//�ɮצW�١Gd:\C++14\C1408.cpp
#include <iostream>
using namespace std;

class Base	//�w�q��HBase���O
{
public:
	virtual void show() = 0;	//�ŧi�s�������show
};

class Derived1: public Base	//�~��Base��H���O
{
public:
	void show() {	//��{show���
		cout << "�l�����O1\n";
	}
};

class Derived2: public Base
{
public:
	void show() {	//��{show���
		cout << "�l�����O2\n";
	}
};

int main(int argc, char** argv)
{
	Base *list[2];
	Derived1 d1;
	Derived2 d2;
	list[0] = &d1;	//����[0]���Vd1
	list[1] = &d2; 	//����[1]���Vd2
	list[0]->show();	//���"�l�����O1"
	list[1]->show();	//���"�l�����O2"
	return 0;
}
