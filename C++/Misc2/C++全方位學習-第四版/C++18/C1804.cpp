//�ɮצW�١Gd:\C++18\C1804.cpp
#include <iostream>
using namespace std;

void innerSort(int [], int);
void outerSort(int [], int);
const int MAX = 5;	//MAX = �}�C�̤j�d��
int minimum, mindex;	//�w�q�����ܼ�

int main(int argc, char** argv)
{
	int i;	//�ŧi����ܼ�
	int number[MAX] = {57, 19, 33, 92, 6};	//�ŧi�@���}�C

	cout << "�Ƨǫe�G";	//��ܱƧǫe���
	for(i = 0; i < MAX; i++)
		cout << number[i] << '\0';
	cout << "\n�Ƨǫ�G";	//��ܱƧǫ���
	outerSort(number, 0);
	for (i = 0; i < MAX; i++)
		cout << number[i] << '\0';
	cout << endl;
	return 0;
}

void outerSort(int number[], int i)
{
	if(i < MAX) {
		mindex = i;	//mindex=�̤p�ȯ���
		minimum = number[i];	//minimum=�̤p��
		innerSort(number, i+1);	//�I�sinnerSort
		number[mindex] = number[i];	//number[�̤p�ȯ���]=���j��
		number[i] = minimum;	//number[i]=�̤p��
		outerSort(number, i+1);	//���^�I�souterSort
	}
}

void innerSort(int number[], int j)
{
	if(j < MAX) {
		if(number[j] < minimum) {	//�Ynumber[j]<�̤p��
			minimum = number[j];	//minimum=�s�̤p��
			mindex = j;	//mindex=�s�̤p�ȯ���
		}
		innerSort(number, j+1);	//���^�I�sinnerSort
	}
}
