//郎嘿d:\C++12\C1208.cpp
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
	Fracpri () {}	//礚把计ミ
	Fracpri (int, int, int);	//Τ把计ミ
	int getgcd();	// getgcd ㄧ计
	Fracpri operator ++();	//玡竚 ++x 腹
	Fracpri operator ++(int);	//竚 x++ 腹
	friend istream & operator >> (istream& in, Fracpri& obj);
	friend ostream & operator << (ostream& out, Fracpri& obj);
};

Fracpri::Fracpri(int a, int b, int c)	//﹚竡ミㄧ计
{
	whole = a; denom = b; numer = c;
}

int Fracpri::getgcd()	//― G.C.D ㄧ计
{
	int n = numer<denom ? numer : denom;
	for( ; n>=1; n--)
		if(denom%n==0 && numer%n==0)	//计埃n单0
			break;	//い耞癹伴
	return n;
}

Fracpri Fracpri::operator ++()	//更玡竚 ++x 腹
{
	return Fracpri(++whole, denom, numer);
}

Fracpri Fracpri::operator ++(int)	//更竚 x++ 腹
{
	return Fracpri(whole++, denom, numer);
}

istream & operator >> (istream & in, Fracpri & obj)
{					//更 >> 笲衡才腹
	in >> obj.whole >> obj.numer >> obj.denom;
	obj.whole = abs(obj.whole);
	obj.numer = abs(obj.numer);
	obj.denom = abs(obj.denom);
	return in;
}

ostream & operator << (ostream& out, Fracpri& obj) 
{					//更 << 笲衡才腹
	int gcd = obj.getgcd();
	obj.numer = obj.numer / gcd;
	obj.denom = obj.denom / gcd;
	out << obj.whole << ' ' << obj.numer << '/' << obj.denom;
	return out;
}

int main(int argc, char** argv)
{
	Fracpri s1, s2, s3, s4;
	cout << "叫块盿だ计1 (俱计 だ だダ): ";
	cin >> s1;
	cout << "叫块盿だ计2 (俱计 だ だダ): ";
	cin >> s2;
	s3 = ++s1;	// s1=s1+1, s3=s1
	cout << "\ns3 = ++s1 = " << s3;
	cout << "\n笲衡 s1 = " << s1 << endl;
	s4 = s2++;	// s4=s2, s2=s2+1
	cout << "\ns4 = s2++ = " << s4;
	cout << "\n笲衡 s2 = " << s2 << endl;
	return 0;
}
