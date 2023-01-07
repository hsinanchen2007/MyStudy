//檔案名稱：d:\C++11\C1111.cpp
#include <iostream>
using namespace std;

class Oddsum
{
	static int sum;	//宣告靜態資料成員
public:
	static void addition(int n);	//宣告靜態成員函數
	void display();	//宣告輸出資料函數
};

int Oddsum::sum = 0;	//起始靜態資料成員

void Oddsum::addition(int n) {	//定義靜態成員函數
	sum += n;	//sum(n+1)=sum(n)+n
}

void Oddsum::display() {	//定義輸出資料成員函數
	cout << "sum = " << sum << endl;
}

int main(int argc, char** argv)
{
	Oddsum a;
	for (int count = 1; count <= 100; count += 2)	//呼叫函數迴圈
		a.addition(count);	//呼叫addition函數
	a.display();	//呼叫display函數
	return 0;
}
