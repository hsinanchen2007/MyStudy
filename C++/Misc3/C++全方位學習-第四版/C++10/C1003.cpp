//�ɮצW�١Gd:\C++10\C1003.cpp
#include <iostream>
using namespace std;

struct Booklist	//�ŧiBooklist��Ƶ��c
{
	char title[21];	//Booklist��1�����ܼ�
	char auther[7];	//Booklist��2�����ܼ�
	char number[10];	//Booklist��3�����ܼ�
	float price;	//Booklist��4�����ܼ�
};

int main(int argc, char** argv)
{
	//�w�q�ð_�lCPP���
	Booklist CPP = {"C++�����ǲ߲ĤT��", "�j�[�d", "AEL014632", 580.00};
	//�w�q�ð_�lVB���
	Booklist DL = {"�Ʀ��޿�]�p�ĤT��  ", "�j�[�d", "AEE037000", 420.00};

	cout.precision(2); cout.setf(ios::fixed);
	cout << "�ѦW\t\t\t�@��\t\t�Ѹ�\t\t�w��\n";
	cout << CPP.title << '\t';	//��XCPP��1�������
	cout << CPP.auther << "\t\t";	//��XCPP��2�������
	cout << CPP.number << '\t';	//��XCPP��3�������
	cout << CPP.price << '\n';	//��XCPP��4�������

	cout << DL.title << '\t';	//��XDL��1�������
	cout << DL.auther << "\t\t";	//��XDL��2�������
	cout << DL.number << '\t';	//��XDL��3�������
	cout << DL.price << '\n';	//��XDL��4�������
	return 0;
}
