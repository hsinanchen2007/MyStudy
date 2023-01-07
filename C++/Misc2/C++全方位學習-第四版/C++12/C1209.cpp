//郎嘿d:\C++12\C1209.cpp
#include <iostream>
using namespace std;

const float MTF = 3.280833f;

class Distance	//Distance摸
{
	int feet;
	float inch;
public:
	Distance (int f, float in);	//把计ミ
	Distance (float meter);	//把计ミ
	friend ostream & operator << (ostream& out, Distance& obj);
};

Distance::Distance (int f, float in)	//﹚竡把计ミ
{
	feet = f; inch = in;
}

Distance::Distance(float meter)	//﹚竡把计ミ
{					//膀セ篈锣传摸篈
	float fracfeet = MTF * meter;
	feet = (int)fracfeet;	//float锣Θint
	inch = 12 * (fracfeet - feet);
}

ostream & operator << (ostream& out, Distance& obj)
{					//更 << 笲衡才腹
	out  << obj.feet << " 璣 " 
		<< obj.inch << " 璣 ";
	return out;
}

int main(int argc, char** argv)
{
	Distance d(0, 0);	//㊣把计ミ
	float m = 3.5f;
	d = m;		//㊣把计ミ
	cout << m << " そへ = " << d;
	cout << endl;
	return 0;
}
