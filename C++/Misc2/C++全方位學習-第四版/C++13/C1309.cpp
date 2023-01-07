//檔案名稱：d:\C++13\C1309.cpp
#include <iostream>
using namespace std;

class TwoD		//定義TwoD類別
{
protected:
	int x, y;
public:
	TwoD(int m, int n) {
		x = m; y = n;
	}
	void showxy() {
		cout << "平面座標 : p(" << x << ", " 
			 << y << ") " << endl;
	}
};

class ThreeD: public TwoD	//以public繼承TwoD
{
protected:
	int z;
public:
	ThreeD(int m, int n, int o): TwoD(m, n)	{ //傳遞m, n參數到TwoD
		z = o;
	}
	void showxyz() {
		cout << "空間座標 : s(" << x << ", " << y 
			 << ", " << z << ") " << endl;
	}
};

int main(int argc, char** argv)
{
	TwoD p(3, 4);	//建立TwoD物件
	ThreeD s(3, 4, 5);	//建立ThreeD物件
	p.showxy();	//直接呼叫TwoD成員
	s.showxyz();	//直接呼叫ThreeD成員
	return 0;
}
