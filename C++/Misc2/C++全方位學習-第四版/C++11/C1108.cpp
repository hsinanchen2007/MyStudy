//�ɮצW�١Gd:\C++11\C1108.cpp
#include <iostream>
#include <iomanip>	//���J�]�w�榡���D��
using namespace std;

class Booklist	//�ŧiBooklist���O
{
	char title[80];	//Booklist��1�����ܼ�
	char auther[20];	//Booklist��2�����ܼ�
	char number[20];	//Booklist��3�����ܼ�
	float price;	//Booklist��4�����ܼ�
public:
	void setBook(void) 	//��J�ϮѸ�ƨ��
	{
		cout << "�п�J�ѦW�G";
		cin.getline(title, 79);	//��J��1�������
		cout << "�п�J�@�̡G";
		cin.getline(auther, 19);	//��J��2�������
		cout << "�п�J�Ѹ��G";
		cin.getline(number, 19);	//��J��3�������
		cout << "�п�J�w���G";
		cin >> price;	//��J��4�������
		cout << endl;
	}
	void showBook()	//��X�ϮѸ�ƨ��
	{
		cout.precision(2);	//�]�w�ƭȪ����Ħ��
		cout.setf(ios::fixed|ios::left);	//�T�w�p��2���,�V�����
		cout << setw(24) << title;	//��Xb��1�������
		cout << setw(16) << auther;	//��Xb��2�������
		cout << setw(16) << number;	//��Xb��3�������
		cout << price << '\n';	//��Xb��4�������
	}
};

int main(int argc, char** argv)
{
	Booklist book[2]; 	//�إ�Booklist���A�}�C

	for(int i=0; i<2; i++)	//��JBooklist��ưj��
	{
		book[i].setBook();	//�I�s����setBook���
		cin.ignore();	//�����̫�@�ӿ�J�r��
	}

	cout << "�ѦW\t\t\t�@��\t\t�Ѹ�\t\t�w��\n";
	for(int j=0; j<2; j++)	//��X�ϮѸ�ưj��
	{
		book[j].showBook();	//�I�s����showBook���
	}
	return 0;
}
