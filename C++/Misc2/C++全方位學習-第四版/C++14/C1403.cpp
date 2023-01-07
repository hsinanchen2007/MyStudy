//�ɮצW�١Gd:\C++14\C1403.cpp
#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.1415926f

class InchArea	//�ŧi��¦���O
{
protected:
	double inch;
public:
	InchArea(double in) {	//��¦���O�إߪ�
		inch = in;
	}
	double getLength() {	//getLength���
		return inch;
	}
	double getArea() {
		return pow(getLength(), 2);
	}
};

class FeetArea: public InchArea	//�ŧi�l�����O
{
protected:
	double feet;
public:
	FeetArea(int ft): InchArea(ft*12) {	//��¦���O�إߪ�
		feet = ft;
	}
	int getLength() {	//�h��getLength���
		return feet;
	}
};

int main(int argc, char** argv)
{
	InchArea ia(5);	//�إ߰�¦���O����ia
	cout << "����Ϊ� 5 �^�T, ���n = " << ia.getArea()
			<< " ����^�T" << endl;	//�I�s��¦���O��k

	FeetArea fa(8);	//�إ߭l�����O����fa
	cout << "����Ϊ� 8 �^�`, ���n = " << fa.getArea()
			<< " ����^�T" << endl;	//�I�s��¦���O��k
	return 0;
}
