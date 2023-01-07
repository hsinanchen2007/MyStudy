//檔案名稱：d:\C++13\C1304.cpp
#include <iostream>
using namespace std;

class PointXY	//宣告基礎類別1,PointXY
{
protected:
	int x, y;
public:
	void setxy(int n, int m) {
		x = n; y = m;
	}
};

class PointZ	//宣告基礎類別2,PointZ
{
protected:
	int z;
public:
	void setz(int o) {
		z = o;
	}
};

class Cube: public PointXY, public PointZ	//以public繼承PointXY
{					//以public繼承PointZ
public:
	void showxy() {
		cout << "平面座標 : p(" << x << ", " 	//存取x, y值
			 << y << ") " << endl;
	}
	void showxyz() {
		cout << "空間座標 : s(" << x << ", " << y	//存取x, y, z
			 << ", " << z << ") " << endl;
	}
	void showarea() {
		cout << "面積 = " << x * y << endl;	//存取x, y值
	}
	void showcube() {
		cout << "體積 = " << x * y * z << endl;	//存取x, y, z
	}
};

int main(int argc, char** argv)
{
	Cube p;		//建立衍生類別Cube物件
	p.setxy(2,5);	//直接呼叫基礎類別1成員
	p.showxy();	//直接呼叫衍生類別成員
	p.showarea();	//直接呼叫衍生類別成員
	cout << endl;
	p.setz(8);	//直接呼叫基礎類別2成員
	p.showxyz();	//直接呼叫衍生類別成員
	p.showcube();	//直接呼叫衍生類別成員
	return 0;
}
