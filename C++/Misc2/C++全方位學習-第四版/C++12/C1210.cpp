//�ɮצW�١Gd:\C++12\C1210.cpp
#include <iostream>
using namespace std;

const float MTF = 3.280833f;

class Distance	//�ŧiDistance���O
{
private:
	int feet;
	float inch;
public:
	Distance (int f, float in); 	//Distance���O�إߪ�
	operator float();	//�ŧi�h��float���A�쫬
	friend ostream & operator << (ostream& out, Distance& obj);
};

Distance::Distance (int f, float in)
{
	feet = f; inch = in;
}
Distance::operator float()	//�w�q�h��float���A���
{
	float fracfeet = inch / 12;
	fracfeet += float(feet);
	return fracfeet / MTF;
}

ostream & operator << (ostream& out, Distance& obj) 	//�h��<<�B��Ÿ�
{
	out  << obj.feet << " �^�` "
		<< obj.inch << " �^�T";
	return out;
}

int main(int argc, char** argv)
{
	Distance d(11, 5.79499f);	//�I�sDistance�إߪ�
	float m; 	//�ŧi�B�I���ܼ�m
	m = d;		//�I�s�h��float���
	cout << d << " = " << m << " ����\n";
	return 0;
}
