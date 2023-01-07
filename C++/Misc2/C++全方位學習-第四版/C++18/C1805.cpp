//�ɮצW�١Gd:\C++18\C1805.cpp
#include <iostream>
using namespace std;

void innerSort(int [], int);
void outerSort(int [], int);
void search(int [], int, int, int);
const int MAX = 5;	//MAX = �}�C�̤j�d��
int minimum, mindex;	//�w�q�����ܼ�

int main(int argc, char** argv)
{
	int i, navigate;	//�ŧi����ܼ�
	int number[MAX] = {57, 19, 33, 92, 6};	//�ŧi��ư}�C

	cout << "�Ƨǫe�G";	//��ܱƧǫe����
	for (i = 0; i < MAX; i++)
		cout << number[i] << '\0';

	cout << "\n�п�J�n�j�M�ƭȡG"; 
	cin >> navigate;	//��J�j�M��
	outerSort(number, 0);

	cout << "\n�Ƨǫ�G";	//��ܱƧǫᤧ��
	for (i = 0; i < MAX; i++)
		cout << number[i] << '\0';
	search(number, 0, MAX-1, navigate);
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

void search(int number[], int low, int high, int nav)
{
	int middle;	//�ŧi����ܼ�
	if (low <= high) {
		if ((low + high) % 2 > 0.5)	//�p��j�M��m
			middle = (low + high) / 2 + 1;
		else
			middle = (low + high) / 2;

		if (nav < number[middle])	//�p��j�M�W��
			search(number, low, middle-1, nav);	//���^�I�s
		else if (nav > number[middle])	//�p��j�M�U��
			search(number, middle+1, high, nav);	//���^�I�s
		else if (nav == number[middle])	//���۲żƭ�
			cout << "\n���ƭȡG" << nav << endl;
	} else {
		cout << "\n�䤣��ƭȡG" << nav << endl;
	}
}
