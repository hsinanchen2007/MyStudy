//�ɮצW�١Gd:\C++13\C1307.cpp
#include <iostream>
using namespace std;

class Base1		//�w�q��¦���OBase1
{
public:
	Base1() {cout << "�إ߰�¦���O1\n";}
	~Base1() {cout << "�}�a��¦���O1\n";}
};

class Base2		//�w�q��¦���OBase2
{
public:
	Base2() {cout << "�إ߰�¦���O2\n";}
	~Base2() {cout << "�}�a��¦���O2\n";}
};

class Derived: public Base1, public Base2	//�~��Base1�PBase2
{
public:
	Derived() {cout << "�إ߭l�����O\n";}
	~Derived() {cout << "�}�a�l�����O\n";}
};

int main(int argc, char** argv)
{
	Derived d;	//�إ�Derived����d
	system("PAUSE");
	return 0;
}
