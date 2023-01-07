//檔案名稱：d:\C++13\C1311.cpp
#include <iostream>
using namespace std;

class TwoD	//定義TwoD類別
{
protected:
	int x, y;
public:
	TwoD() {}	//TwoD不含參數建立者
	TwoD(int m, int n) { x = m; y = n; }	//TwoD含參數建立者
	void setx(int m) { x = m; }	//設定x值public函數
	void sety(int n) { y = n; }	//設定y值public函數
	int getx() { return x; }	//取得x值public函數
	int gety() { return y; }	//取得y值public函數
	void showxy() {
		cout << "平面座標 : p(" << x << ", " 
			<< y << ") " << endl;
	}
};

class ThreeD	//定義ThreeD類別
{
protected:
	int z;
public:
	TwoD d;		//包含TwoD類別
	ThreeD(int m, int n, int o) {	//ThreeD 含參數建立者
		d.setx(m); 	//透過d.setx()設定x值
		d.sety(n);	//透過d.sety()設定y值
		z = o;
	}
	void showxyz() {
		cout << "空間座標 : s(" 
			 << d.getx() << ", " 	//透過d.getx()取得x
			 << d.gety() << ", " 	//透過d.gety()取得y
			 << z << ") " << endl;
	}
};

int main(int argc, char** argv)
{
	TwoD p(3, 4);	//建立TwoD類別物件p
	ThreeD s(3, 4, 5);	//建立ThreeD類別物件s
	p.showxy();	//直接呼叫TwoD成員
	s.showxyz();	//直接呼叫ThreeD成員
	return 0;
}
