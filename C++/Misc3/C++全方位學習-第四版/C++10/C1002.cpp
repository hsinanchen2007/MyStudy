//�ɮצW�١Gd:\C++10\C1002.cpp
#include <iostream>
#include <cstring>	//���J�r����D��
using namespace std;

struct Booklist	//�ŧiBooklist��Ƶ��c
{
	char title[25];	//Booklist��1�����ܼ�
	char auther[10];	//Booklist��2�����ܼ�
	char number[10];	//Booklist��3�����ܼ�
	float price;	//Booklist��4�����ܼ�
};

int main(int argc, char** argv)
{
	Booklist CPP;	//�إ�Booklist���A�ܼ�
	strcpy(CPP.title, "C++�����ǲ߲ĤT��");	//���wCPP��1�������
	strcpy(CPP.auther, "�j�[�d\t");	//���wCPP��2�������
	strcpy(CPP.number, "AEL014632");	//���wCPP��3�������
	CPP.price = 580.00;	//���wCPP��4�������

	Booklist DL;	//�إ�Booklist���A�ܼ�
	strcpy(DL.title, "�Ʀ��޿�]�p�ĤT��");	//���wVB��1�������
	strcpy(DL.auther, "�j�[�d\t");	//���wVB��2�������
	strcpy(DL.number, "AEE037000");	//���wVB��3�������
	DL.price = 420.00;	//���wVB��4�������

	cout.precision(2); cout.setf(ios::fixed);
	cout << "�ѦW\t\t\t�@��\t\t�Ѹ�\t\t�w��\n";
	cout << CPP.title << '\t';	//��XCPP��1�������
	cout << CPP.auther << '\t';	//��XCPP��2�������
	cout << CPP.number << '\t';	//��XCPP��3�������
	cout << CPP.price << '\n';	//��XCPP��4�������

	cout << DL.title << '\t';	//��XVB��1�������
	cout << DL.auther << '\t';	//��XVB��2�������
	cout << DL.number << '\t';	//��XVB��3�������
	cout << DL.price << '\n';	//��XVB��4�������
	return 0;
}
