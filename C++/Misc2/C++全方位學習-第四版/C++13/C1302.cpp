//�ɮצW�١Gd:\C++13\C1302.cpp
#include <iostream>
using namespace std;

class Point		//�w�qPoint���O
{
protected:
	int x, y;
public:
	void set(int n, int m) {
		x = n; y = m;
	}
	void show() {
		cout << "��m = p(" << x << ", " << y << ")" << endl;
	}
};

class Area: private Point	//�Hprivate���A�~��
{
public:
	void setpoint(int n, int m) {	//���s�w�qset()���
		set(n, m);
	}
	void showpoint() {	//���s�w�qshow()���
		show();
	}
	void showarea() {
		cout << "���n = " << x * y << endl;
	}
};

int main(int argc, char** argv)
{
	Area p; 		//�إ߭l�����O����
	p.setpoint(2,5);	//�]�w x=2, y=5
	p.showpoint();	//��� x, y ��
	p.showarea();	//��� xy ���n
	return 0;
}
