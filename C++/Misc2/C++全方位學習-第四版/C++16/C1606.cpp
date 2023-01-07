//檔案名稱：d:\C++16\C1606.cpp
#include <iostream>
using namespace std;

template <class X>	//宣告範本
void sort(X *items, int max)	//定義排序函數
{
	register int si, di;	//定義索引暫存器
	X temp;		//定義資料對調區

	for(si=0; si<max-1; si++)	//資料對調外迴圈
		for(di=si; di<max; di++)	//資料對調內迴圈
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

	cout << "排序前：";
	for(i=0; i<7; i++)
		cout << iArray[i] << ' ';
	cout << endl;

	sort(iArray, 7);	//整數排序
	
	cout << "排序後：";
	for(i=0; i<7; i++)
		cout << iArray[i] << ' ';
	cout << endl << endl;

	cout << "排序前：";
	for(i=0; i<5; i++)
		cout << dArray[i] << ' ';
	cout << endl;

	sort(dArray, 5);	//倍精數排序

	cout << "排序後：";
	for(i=0; i<5; i++)
		cout << dArray[i] << ' ';
	cout << endl;
	return 0;
}
