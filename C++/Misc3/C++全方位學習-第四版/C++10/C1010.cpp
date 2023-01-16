//�ɮצW�١Gd:\C++10\C1010.cpp
#include <iostream>
#include <iomanip>	//���J�]�w�榡���D��
using namespace std;

struct Booklist	//�ŧiBooklist��Ƶ��c
{
	char title[25];	//Booklist��1�����ܼ�
	char auther[9];	//Booklist��2�����ܼ�
	char number[11];	//Booklist��3�����ܼ�
	float price;	//Booklist��4�����ܼ�
};

void getBook(Booklist *);	//�ŧigetBook��ƭ쫬
void showBook(const Booklist []);	//�ŧishowBook��ƭ쫬

int main(int argc, char** argv)
{
	Booklist book[2]; 	//�إ�Booklist���A�}�C

	for(int i=0; i<2; i++)	//��JBooklist��ưj��
	{
		getBook(&book[i]);	//book[i]=��J���c���
		cin.ignore();	//�����̫�@�ӿ�J�r��
	}

	cout << "�ѦW\t\t\t�@��\t\t�Ѹ�\t\t�w��\n";
	showBook(book);	//�ǻ����c�}�C��showBook���
	return 0;
}

void getBook(Booklist *bl) 	//��J�ϮѸ�ƨ��
{
	cout << "�п�J�ѦW�G";
	cin.getline(bl->title, 24);	//��J��1�������
	cout << "�п�J�@�̡G";
	cin.getline(bl->auther, 8);	//��J��2�������
	cout << "�п�J�Ѹ��G";
	cin.getline(bl->number, 10);	//��J��3�������
	cout << "�п�J�w���G";
	cin >> bl->price;	//��J��4�������
	cout << endl;
}

void showBook(const Booklist b[])	//��X�ϮѸ�ƨ��
{
	cout.precision(2);	//�]�w�ƭȪ����Ħ��
	cout.setf(ios::fixed|ios::left);	//�T�w�p��2���,�V�����
	for(int j=0; j<2; j++)	//��X�ϮѸ�ưj��
	{
		cout << setw(24) << b[j].title;	//��Xb��1�������
		cout << setw(16) << b[j].auther;	//��Xb��2�������
		cout << setw(16) << b[j].number;	//��Xb��3�������
		cout << b[j].price << '\n';	//��Xb��4�������
	}
}
