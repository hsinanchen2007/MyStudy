//�ɮצW�١Gd:\C++16\C1606.cpp
#include <iostream>
using namespace std;

template <class X>	//�ŧi�d��
void sort(X *items, int max)	//�w�q�ƧǨ��
{
	register int si, di;	//�w�q���޼Ȧs��
	X temp;		//�w�q��ƹ�հ�

	for(si=0; si<max-1; si++)	//��ƹ�ե~�j��
		for(di=si; di<max; di++)	//��ƹ�դ��j��
			if(items[si] > items[di]) {
				temp = items[si];
				items[si] = items[di];
				items[di] = temp;
			}
}

int main(int argc, char** argv)
{
	int iArray[7] = {57, 19, 33, 92, 6, 48, 65};
	double dArray[5] = {3.5, 11.2, 100.7, 58.3, 66.7};
	int i;

	cout << "�Ƨǫe�G";
	for(i=0; i<7; i++)
		cout << iArray[i] << ' ';
	cout << endl;

	sort(iArray, 7);	//��ƱƧ�
	
	cout << "�Ƨǫ�G";
	for(i=0; i<7; i++)
		cout << iArray[i] << ' ';
	cout << endl << endl;

	cout << "�Ƨǫe�G";
	for(i=0; i<5; i++)
		cout << dArray[i] << ' ';
	cout << endl;

	sort(dArray, 5);	//����ƱƧ�

	cout << "�Ƨǫ�G";
	for(i=0; i<5; i++)
		cout << dArray[i] << ' ';
	cout << endl;
	return 0;
}
