//�ɮצW�١Gd:\C++12\C1206.cpp
#include <iostream>
#include <cmath>
using namespace std;

class Fracpri	// �ŧi Fracpri ���O
{
private:
	int whole;	// ���
	int numer;	// ���l
	int denom;	// ����
public:
	int getgcd();	// �ŧi getgcd ���
	Fracpri operator + (Fracpri);
	friend istream & operator >> (istream& in, Fracpri& obj); 
	friend ostream & operator << (ostream& out, Fracpri& obj); 
};

int Fracpri::getgcd()	//�D G.C.D ���
{
	int n = numer<denom ? numer : denom;
	for( ; n>=1; n--)
		if(denom%n==0 && numer%n==0)	//�G�ư��Hn�ҵ���0
			break;	//���_�j��
	return n;
}

Fracpri Fracpri::operator + (Fracpri obj)	//�h�� + �B��Ÿ�
{
	Fracpri temp;
	int t = (numer * obj.denom + obj.numer * denom);
	temp.denom = denom * obj.denom;
	temp.numer = t % temp.denom;
	temp.whole = whole + obj.whole + (t / temp.denom);
	return temp;
}

istream & operator >> (istream & in, Fracpri & obj)
{					//�h�� >> �B��Ÿ�
	in >> obj.whole >> obj.numer >> obj.denom;
	obj.whole = abs(obj.whole);
	obj.numer = abs(obj.numer);
	obj.denom = abs(obj.denom);
	return in;
}

ostream & operator << (ostream& out, Fracpri& obj)
{					//�h�� << �B��Ÿ�
	int gcd = obj.getgcd();
	obj.numer = obj.numer / gcd;
	obj.denom = obj.denom / gcd;
	out << obj.whole << ' ' << obj.numer << '/' << obj.denom;
	return out;
}

int main(int argc, char** argv)
{
	Fracpri s1, s2, s3;
	cout << "�п�J�a����1 (��� ���l ����): ";
	cin >> s1;
	cout << "�п�J�a����2 (��� ���l ����): ";
	cin >> s2;
	s3 = s1 + s2;	//�I�s + �P = �����
	cout << "�a����1 + �a����2 = " << s1 << " + " 
		 << s2 << " = " << s3 << endl;
	return 0;
}
