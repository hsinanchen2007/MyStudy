//郎嘿d:\C++12\C1210.cpp
#include <iostream>
using namespace std;

const float MTF = 3.280833f;

class Distance	//Distance摸
{
private:
	int feet;
	float inch;
public:
	Distance (int f, float in); 	//Distance摸ミ
	operator float();	//更float篈
	friend ostream & operator << (ostream& out, Distance& obj);
};

Distance::Distance (int f, float in)
{
	feet = f; inch = in;
}
Distance::operator float()	//﹚竡更float篈ㄧ计
{
	float fracfeet = inch / 12;
	fracfeet += float(feet);
	return fracfeet / MTF;
}

ostream & operator << (ostream& out, Distance& obj) 	//更<<笲衡才腹
{
	out  << obj.feet << " 璣 "
		<< obj.inch << " 璣";
	return out;
}

int main(int argc, char** argv)
{
	Distance d(11, 5.79499f);	//㊣Distanceミ
	float m; 	//疊翴计跑计m
	m = d;		//㊣更floatㄧ计
	cout << d << " = " << m << " そへ\n";
	return 0;
}
