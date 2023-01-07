//儲存檔名：d:\C++18\C1802.cpp
#include <iostream>
using namespace std;

int gcd(int, int, int);

int main(int argc, char** argv)
{
	int a, b, n;	//宣告變數
	cout << "請輸入二個整數 (a b)：";	//輸出訊息
	cin >> a >> b;	//輸入a, b二數
	n = a;
	cout << "GCD = " << gcd(a, b, n) << endl;		//輸出GCD
	return 0;
}

int gcd(int a, int b, int n)
{
	if(a%n==0 && b%n==0)	//二數除以n皆等於0
		return n;
	else
		return gcd(a, b, n-1);
}
