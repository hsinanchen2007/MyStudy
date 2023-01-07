//檔案名稱：d:\C++13\C1301.cpp
#include <iostream>
using namespace std;

class Point	//定義Point類別
{
protected:
	int x, y;
public:
	void set(int n, int m) {
		x = n; y = m;
	}
	void show() {
		cout << "位置 = p(" << x << ", " << y << ") " << endl;
	}
};

class Area: public Point	//以public繼承Point
{
public:
	void showarea() {
		cout << "面積 = " << x * y << endl;
	}
};

int main(int argc, char** argv)
{
	Area p;		//建立衍生類別物件
	p.set(2,5);	//直接呼叫基礎類別成員
	p.show();	//直接呼叫基礎類別成員
	p.showarea();	//呼叫衍生類別成員函數
	return 0;
}
