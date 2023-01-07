//儲存檔名：d:\C++18\C1801.cpp
#include <iostream>
#include <iomanip>
using namespace std;

long factorial(int);

int main(int argc, char** argv)
{
	int count = 1;	//while 迴圈初值
	cout << "計數\t" << setw(8) << "階乘\n";	//輸出字串
	do {
		cout << setw(3) << count << '\t';	//輸出計數值
		cout << setw(7) << factorial(count) << endl;	//輸出階乘
	} while(++count<=10);
	return 0;
}

long factorial(int n)
{
	if(n>1)
		return n * factorial(n-1);
	else
		return 1;
}
