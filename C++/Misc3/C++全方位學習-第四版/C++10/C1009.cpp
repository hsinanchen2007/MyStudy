//�ɮצW�١Gd:\C++10\C1009.cpp
#include <iostream>
#include <iomanip>	//���J�榡���D��
using namespace std;


struct Date		//�ŧiDate���A��Ƶ��c
{
	int month;	//Date��1�����ܼ�
	int day;	//Date��2�����ܼ�
};

void printDate( Date * );	//�ŧi�����ƭ쫬

int main(int argc, char** argv)
{
	Date newyear = {1, 1};	//�w�q�ð_�lnewyear
	Date women = {3, 8};	//�w�q�ð_�lwomen
	Date children = {4, 4};	//�w�q�ð_�lchildren
	Date national = {10, 10};	//�w�q�ð_�lnational
	Date christmas = {12, 25};	//�w�q�ð_�lchristmas

	cout << "��  ���G";
	printDate(&newyear);	//�ǻ�newyear�ܼƦ�}
	cout << "���k�`�G";
	printDate(&women);	//�ǻ�women�ܼƦ�}
	cout << "�ൣ�`�G";
	printDate(&children);	//�ǻ�children�ܼƦ�}
	cout << "��y��G";
	printDate(&national);	//�ǻ�national�ܼƦ�}
	cout << "�t�ϸ`�G";
	printDate(&christmas);	//�ǻ�christmas�ܼƦ�}
	return 0;
}

void printDate( Date *d )	//��X������
{
	cout << setw(2) << d->month << " �� ";	//��Xd����1�Ӧ���
	cout << setw(2) << d->day << " ��";	//��Xd����2�Ӧ���
	cout << endl;
}
