//儲存檔名：d:\C++18\C1806.cpp
#include <iostream>
using namespace std;

class Division
{
	int a, b, q;
public:
	Division(int a1, int b1)
	{
		a = a1;
		b = b1;
		q = 0;
	}
	int quotient()
	{
		if(a>=b) {	//a仍大於等於b
			a -= b;	//a = a - b
			q++;
			return quotient();	//遞回呼叫
		} else
			return q;	//傳回商數
	}
	int remainder()
	{
		if(a>=b) {	//a仍大於等於b
			a -= b;	//a = a - b
			return remainder();	//遞回呼叫
		} else
			return a;	//傳回餘數
	}
};

int main(int argc, char** argv)
{
	int a, b;	//宣告變數
	cout << "請輸入二個整數 (a b)：";	//輸出訊息
	cin >> a >> b;	//輸入a, b二數
	Division div(a, b);

	cout << a << " / " << b << " = " << div.quotient();		//輸出商
	cout << " R " << div.remainder() << endl;		//輸出餘數
	return 0;
}
