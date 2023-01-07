//�ɮצW�١Gd:\C++12\C1209.cpp
#include <iostream>
using namespace std;

const float MTF = 3.280833f;

class Distance	//�ŧiDistance���O
{
	int feet;
	float inch;
public:
	Distance (int f, float in);	//�ŧi�G�Ѽƫإߪ�
	Distance (float meter);	//�ŧi�@�Ѽƫإߪ�
	friend ostream & operator << (ostream& out, Distance& obj);
};

Distance::Distance (int f, float in)	//�w�q�G�Ѽƫإߪ�
{
	feet = f; inch = in;
}

Distance::Distance(float meter)	//�w�q�@�Ѽƫإߪ�
{					//�򥻫��A�ഫ���O���A
	float fracfeet = MTF * meter;
	feet = (int)fracfeet;	//float�নint
	inch = 12 * (fracfeet - feet);
}

ostream & operator << (ostream& out, Distance& obj)
{					//�h�� << �B��Ÿ�
	out  << obj.feet << " �^�` " 
		<< obj.inch << " �^�T ";
	return out;
}

int main(int argc, char** argv)
{
	Distance d(0, 0);	//�I�s�G�ӰѼƪ��إߪ�
	float m = 3.5f;
	d = m;		//�I�s�@�ӰѼƪ��إߪ�
	cout << m << " ���� = " << d;
	cout << endl;
	return 0;
}
