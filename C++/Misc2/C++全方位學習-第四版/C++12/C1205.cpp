//�ɮצW�١Gd:\C++12\C1205.cpp
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

istream & operator >> (istream & in, Fracpri & obj)	//�h��>>�Ÿ����
{
	in >> obj.whole >> obj.numer >> obj.denom;
	obj.whole = abs(obj.whole);
	obj.numer = abs(obj.numer);
	obj.denom = abs(obj.denom);
	return in;
}

ostream & operator << (ostream& out, Fracpri& obj)	//�h��<<�Ÿ����
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
	cout << "�п�J�a���� (��� ���l ����): ";
	cin >> s1;
	cout << "��²�᪺�a���Ƭ��G" << s1 << endl;
	return 0;
}
