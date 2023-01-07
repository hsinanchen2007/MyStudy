//郎嘿d:\C++12\C1205.cpp
#include <iostream>
#include <cmath>
using namespace std;

class Fracpri	// Fracpri 摸
{
private:
	int whole;	//俱计
	int numer;	//だ
	int denom;	//だダ
public:
	int getgcd();	// getgcd ㄧ计
	friend istream & operator >> (istream& in, Fracpri& obj); 
	friend ostream & operator << (ostream& out, Fracpri& obj);
};

int Fracpri::getgcd()	//― G.C.D ㄧ计
{
	int n = numer<denom ? numer : denom;
	for( ; n>=1; n--)
		if(denom%n==0 && numer%n==0)	//计埃n单0
			break;	//い耞癹伴
	return n;
}

istream & operator >> (istream & in, Fracpri & obj)	//更>>才腹ㄧ计
{
	in >> obj.whole >> obj.numer >> obj.denom;
	obj.whole = abs(obj.whole);
	obj.numer = abs(obj.numer);
	obj.denom = abs(obj.denom);
	return in;
}

ostream & operator << (ostream& out, Fracpri& obj)	//更<<才腹ㄧ计
{ 
	int gcd = obj.getgcd();
	obj.numer = obj.numer / gcd;
	obj.denom = obj.denom / gcd;
	out << obj.whole << ' ' << obj.numer << '/' << obj.denom;
	return out;
}

int main(int argc, char** argv)
{
	Fracpri s1;
	cout << "叫块盿だ计 (俱计 だ だダ): ";
	cin >> s1;
	cout << "て虏盿だ计" << s1 << endl;
	return 0;
}
