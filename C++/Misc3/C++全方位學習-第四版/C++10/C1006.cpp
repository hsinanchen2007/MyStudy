//�ɮצW�١Gd:\C++10\C1006.cpp
#include <iostream>
#include <iomanip>	//���J�]�w�榡���D��
using namespace std;

struct Booklist	//�ŧiBooklist��Ƶ��c
{
	char title[24];	//Booklist��1�����ܼ�
	char auther[9];	//Booklist��2�����ܼ�
	char number[11];	//Booklist��3�����ܼ�
	float price;	//Booklist��4�����ܼ�
};

Booklist getBook(void);	//�ŧigetBook��ƭ쫬
void showBook(const Booklist &);	//�ŧishowBook��ƭ쫬

int main(int argc, char** argv)
{
	Booklist CPP; 	//�إ�Booklist���A�ܼ�
	Booklist DL; 	//�إ�Booklist���A�ܼ�

	CPP = getBook();	//CPP=��J���c���A���
	cin.ignore();	//�����̫�@�ӿ�J�r��
	DL = getBook();	//CPP=��J���c���A���

	cout << "�ѦW\t\t\t�@��\t\t�Ѹ�\t\t�w��\n";
	showBook(CPP);
	showBook(DL);
	return 0;
}

Booklist getBook(void) 	//��J�ϮѸ�ƨ��
{
	Booklist bl;	//�إ�Booklist���A�ܼ�

	cout << "�п�J�ѦW�G";
	cin.getline(bl.title, 24);	//��J��1�������
	cout << "�п�J�@�̡G";
	cin.getline(bl.auther, 8);	//��J��2�������
	cout << "�п�J�Ѹ��G";
	cin.getline(bl.number, 10);	//��J��3�������
	cout << "�п�J�w���G";
	cin >> bl.price;	//��J��4�������
	cout << endl;
	return bl;	//�Ǧ^Booklist���A���
}

void showBook(const Booklist &b)	//��X�ϮѸ�ƨ��
{
	cout.precision(2);	//�]�w�ƭȪ����Ħ��
	cout.setf(ios::fixed|ios::left);	//�T�w�p��2���,�V�����
	cout << setw(24) << b.title;	//��XCPP��1�������
	cout << setw(16) << b.auther;	//��XCPP��2�������
	cout << setw(16) << b.number;	//��XCPP��3�������
	cout << b.price << '\n';	//��XCPP��4�������
}
