//檔案名稱：d:\C++13\C1302.cpp
#include <iostream>
using namespace std;

class Point		//定義Point類別
{
protected:
	int x, y;
public:
	void set(int n, int m) {
		x = n; y = m;
	}
	void show() {
		cout << "位置 = p(" << x << ", " << y << ")" << endl;
	}
};

class Area: private Point	//以private型態繼承
{
public:
	void setpoint(int n, int m) {	//重新定義set()函數
		set(n, m);
	}
	void showpoint() {	//重新定義show()函數
		show();
	}
	void showarea() {
		cout << "面積 = " << x * y << endl;
	}
};

int main(int argc, char** argv)
{
	Area p; 		//建立衍生類別物件
	p.setpoint(2,5);	//設定 x=2, y=5
	p.showpoint();	//顯示 x, y 值
	p.showarea();	//顯示 xy 面積
	return 0;
}
