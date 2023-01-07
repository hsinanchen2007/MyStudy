//�ɮצW�١Gd:\C++11\C1110.cpp
#include <iostream>
using namespace std;

class First
{
	int x;
public:
	void setx(int var) {
		x = var;
	}
	friend int getx(First obj) {	//�w�q friend ���
		return obj.x;
	}
};

class Second
{
	int y;
public:
	void sety(int var) {
		y = var;
	}
	void showxy(First obj) {
		cout << "x = " << getx(obj) << endl;	//�I�s friend ���
		cout << "y = " << y << endl;
	}
};

int main(int argc, char** argv)
{
	First A;
	Second B;
	A.setx(10);
	B.sety(20);
	B.showxy(A);
	return 0;
}
