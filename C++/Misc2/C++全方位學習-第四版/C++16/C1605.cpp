//�ɮצW�١Gd:\C++16\C1605.cpp
#include <iostream>
#include <cstring>
using namespace std;

class Distance	//�۩wDistance������O
{
	int feet;
	float inches;
public:
	class InError	//�^�T�ȿ��~�B�z���O
	{
		char str[80];
		float i;
	public:
		InError(char *s, float f)
		{
			strcpy(str, s);
			i = f;
		}
		char* get_str()
		{
			return str;
		}
		float get_i()
		{
			return i;
		}
	};
	Distance()	//�L�Ѽƫإߪ̨��
	{
		feet = 0; inches = 0.0;
	}
	Distance(int ft, float in)	//���Ѽƫإߪ̨��
	{
		char s1[] = "�إ߿��~�^�T�� ";
		if(in >= 12)	//�Yin�j�󵥩�12
			throw InError(s1, in);	//�h���Y�ҥ~
		feet = ft;	//�_�hfeet = ft
		inches = in;	//	inches = in
	}
	void getDist()	//��J��ƨ��
	{
		char s2[] = "��J���~�^�T�� ";
		cout << "�п�J�^�`�ȡG";
		cin >> feet;
		cout << "�п�J�^�T�ȡG";
		cin >> inches;
		if(inches >= 12)	//�Yinches�j�󵥩�12
			throw InError(s2, inches);	//�h���Y�ҥ~
	}
};

int main(int argc, char** argv)
{
	try {			//try�϶�
		Distance d1(10, (float)11.0);	//�Y�^�T>=12.0�h���~
		Distance d2;
		d2.getDist();	//��J���;
		cout << "��J�ȥ��T�C";
	}
	catch(Distance::InError ix) { //�����ҥ~�P�������~���O
		cout << ix.get_str() << '\t'	//�I�sInError::get_str
			 << ix.get_i() << endl;	//�I�sInError::get_i
	}
	return 0;
}
