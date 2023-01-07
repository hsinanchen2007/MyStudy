//檔案名稱：d:\C++12\C1201.cpp
#include <iostream>
using namespace std;

int area(int l, int w)	//計算長方形面積函數
{
	return l * w;
}

int area(int l, int w, int h)	//計算長方體表面積函數
{
	return 2 * ((l * w) + (w * h) + (h * l));
}

int main(int argc, char** argv)
{
	cout << "長方形面積 = " << area(6, 8);	//輸出長方形面積
	cout  << "平方公分\n";
	cout << "長方體表面積 = " << area(6, 8, 10);	//輸出長方體表面積
	cout  << "平方公分\n";
	return 0;
}
