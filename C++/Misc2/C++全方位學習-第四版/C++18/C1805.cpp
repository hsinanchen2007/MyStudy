//檔案名稱：d:\C++18\C1805.cpp
#include <iostream>
using namespace std;

void innerSort(int [], int);
void outerSort(int [], int);
void search(int [], int, int, int);
const int MAX = 5;	//MAX = 陣列最大範圍
int minimum, mindex;	//定義公用變數

int main(int argc, char** argv)
{
	int i, navigate;	//宣告整數變數
	int number[MAX] = {57, 19, 33, 92, 6};	//宣告整數陣列

	cout << "排序前：";	//顯示排序前之值
	for (i = 0; i < MAX; i++)
		cout << number[i] << '\0';

	cout << "\n請輸入要搜尋數值："; 
	cin >> navigate;	//輸入搜尋值
	outerSort(number, 0);

	cout << "\n排序後：";	//顯示排序後之值
	for (i = 0; i < MAX; i++)
		cout << number[i] << '\0';
	search(number, 0, MAX-1, navigate);
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

void search(int number[], int low, int high, int nav)
{
	int middle;	//宣告整數變數
	if (low <= high) {
		if ((low + high) % 2 > 0.5)	//計算搜尋位置
			middle = (low + high) / 2 + 1;
		else
			middle = (low + high) / 2;

		if (nav < number[middle])	//計算搜尋上限
			search(number, low, middle-1, nav);	//遞回呼叫
		else if (nav > number[middle])	//計算搜尋下限
			search(number, middle+1, high, nav);	//遞回呼叫
		else if (nav == number[middle])	//找到相符數值
			cout << "\n找到數值：" << nav << endl;
	} else {
		cout << "\n找不到數值：" << nav << endl;
	}
}
