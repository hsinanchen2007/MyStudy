//�ɮצW�١Gd:\C++13\C1306.cpp
#include <iostream>
using namespace std;

class Base		//�w�q��¦���OBase
{
public:
	Base() {cout << "�إ߰�¦���O\n";}
	~Base() {cout << "�}�a��¦���O\n";}
};

class Derived1: public Base	//Derived1�~��Base
{
public:
	Derived1() {cout << "�إ߭l�����O\n";}
	~Derived1() {cout << "�}�a�l�����O\n";}
};

class Derived2: public Derived1                    //Derived2�~��Derived1
{
public:
	Derived2() {cout << "�إ߭l�����O2\n";}
	~Derived2() {cout << "�}�a�l�����O2\n";}
};

int main(int argc, char** argv)
{
	Derived2 d; 	//�إ�Derived2����
	system("PAUSE");
	return 0;
}
