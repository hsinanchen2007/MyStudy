//儲存檔名：d:\C++18\C1803.cpp
#include <iostream>
using namespace std;

int lcm(int, int, int);

int main(int argc, char** argv)
{
	int a, b, n;	//宣告變數
	cout << "請輸入二個整數 (a b)：";	//輸出訊息
	cin >> a >> b;	//輸入a, b二數
	n = a;
	cout << "LCM = " << lcm(a, b, n) << endl;		//輸出LCM
	return 0;
}

int lcm(int a, int b, int n)
{
	if(n%b==0)	//n除以b等於0
		return n;
	else
		return lcm(a, b, n+a);
}
