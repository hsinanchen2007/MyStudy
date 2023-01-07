//�ɮצW�١Gd:\C++12\C1207.cpp
#include <iostream>
#include <cmath>
using namespace std;

class Fracpri	//�ŧi Fracpri ���O
{
private:
	int whole;	//���
	int numer;	//���l
	int denom;	//����
public:
	int getgcd();	//�ŧi getgcd ���
	bool operator > (Fracpri);	//�ŧi > �B��Ÿ�
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

bool Fracpri::operator > (Fracpri obj)	//�h�� > �B��Ÿ�
{
	int numer1, numer2;
	numer1 = whole * denom + numer;
	numer2 = obj.whole * obj.denom + obj.numer;
	if((numer1*obj.denom) > (numer2*denom))
		return true;
	else
		return false;
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
	Fracpri s1, s2;
	cout << "�п�J�a����1 (��� ���l ����): ";
	cin >> s1;
	cout << "�п�J�a����2 (��� ���l ����): ";
	cin >> s2;
	if (s1 > s2)	//�I�s ! �P > ���
		cout << "�a����1 (" << s1 << ") > " 
			<< "�a����2 (" << s2 << ')' << endl;
	else
		cout << "�a����1 (" << s1 << ") <= " 
			<< "�a����2 (" << s2 << ')' << endl;
	return 0;
}
