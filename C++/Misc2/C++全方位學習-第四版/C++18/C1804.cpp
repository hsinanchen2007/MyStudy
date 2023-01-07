//檔案名稱：d:\C++18\C1804.cpp
#include <iostream>
using namespace std;

void innerSort(int [], int);
void outerSort(int [], int);
const int MAX = 5;	//MAX = 陣列最大範圍
int minimum, mindex;	//定義公用變數

int main(int argc, char** argv)
{
	int i;	//宣告整數變數
	int number[MAX] = {57, 19, 33, 92, 6};	//宣告一維陣列

	cout << "排序前：";	//顯示排序前資料
	for(i = 0; i < MAX; i++)
		cout << number[i] << '\0';
	cout << "\n排序後：";	//顯示排序後資料
	outerSort(number, 0);
	for (i = 0; i < MAX; i++)
		cout << number[i] << '\0';
	cout << endl;
	return 0;
}

void outerSort(int number[], int i)
{
	if(i < MAX) {
		mindex = i;	//mindex=最小值索引
		minimum = number[i];	//minimum=最小值
		innerSort(number, i+1);	//呼叫innerSort
		number[mindex] = number[i];	//number[最小值索引]=較大值
		number[i] = minimum;	//number[i]=最小值
		outerSort(number, i+1);	//遞回呼叫outerSort
	}
}

void innerSort(int number[], int j)
{
	if(j < MAX) {
		if(number[j] < minimum) {	//若number[j]<最小值
			minimum = number[j];	//minimum=新最小值
			mindex = j;	//mindex=新最小值索引
		}
		innerSort(number, j+1);	//遞回呼叫innerSort
	}
}
