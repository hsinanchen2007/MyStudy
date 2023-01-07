//檔案名稱：d:\C++12\C1202.cpp
#include <iostream>
using namespace std;

class Cuboid	//宣告長方體類別
{
private:
	int length;	//Cuboid的資料成員1
	int width;	//Cuboid的資料成員2
	int height;	//Cuboid的資料成員3
public:
	void setSide(int l, int w)	//設定長方形邊長
	{
		length = l;
		width = w;
		height = 0;
	}
	void setSide(int l, int w, int h)	//設定長方體邊長
	{
		length = l;
		width = w;
		height = h;
	}
	int area()	//計算面積或表面積函數
	{
		if (height == 0)
			return length * width;
		else
			return 2*(length*width+width*height+height*length);
	}
};

int main(int argc, char** argv)
{
	Cuboid rt, cb;	//建立Cuboid物件
	rt.setSide(6, 8);	//起始rt物件資料
	cb.setSide(6, 8, 10);	//起始cb物件資料

	cout << "長方形面積 = " << rt.area();	//輸出長方形面積
	cout << "平方公分\n";
	cout << "長方體表面積 = " << cb.area();	//輸出長方體表面積
	cout << "平方公分\n";
	return 0;
}
