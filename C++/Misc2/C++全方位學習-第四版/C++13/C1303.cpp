//檔案名稱：d:\C++13\C1303.cpp
#include <iostream>
using namespace std;

class TwoD		//定義TwoD類別
{
protected:
	int x, y;
public:
	void setxy(int n, int m) {
		x = n; y = m;
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
	void setz(int o) {
		z = o;
	}
	void showxyz() {
		cout << "空間座標 : s(" << x << ", " << y 
			<< ", " << z << ") " << endl;
	}
};

class Cube: public ThreeD	//以public繼承ThreeD
{					//間接繼承TwoD類別
public:
	void showarea() {
		cout << "面積 = " << x * y << endl;	//間接存取x, y值
	}
	void showcube() {
		cout << "體積 = " << x * y * z	//間接存取x y,直接存取z
			<< endl;
	}
};

int main(int argc, char** argv)
{
	Cube p;		//建立Cube類別物件
	p.setxy(2,5);	//直接呼叫基礎類別成員
	p.showxy();	//直接呼叫基礎類別成員
	p.showarea();	//直接呼叫衍生類別2成員
	cout << endl;
	p.setz(8);	//直接呼叫衍生類別1成員
	p.showxyz();	//直接呼叫衍生類別1成員
	p.showcube();	//直接呼叫衍生類別2成員
	return 0;
}
