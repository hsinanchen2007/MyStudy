//�ɮצW�١Gd:\C++13\C1305.cpp
#include <iostream>
using namespace std;

class Base		//�w�q��¦���OBase
{
public:
	Base() {cout << "�إ߰�¦���O\n";}
	~Base() {cout << "�}�a��¦���O\n";}
};

class Derived: public Base	//Derived�~��Base���O
{
public:
	Derived() {cout << "�إ߭l�����O\n";}
	~Derived() {cout << "�}�a�l�����O\n";}
};

int main(int argc, char** argv)
{
	Derived d;	//�إ�Derived����
	system("PAUSE");
	return 0;
}
