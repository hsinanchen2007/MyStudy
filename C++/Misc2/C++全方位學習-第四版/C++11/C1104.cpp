//檔案名稱：d:\C++11\C1104.cpp
#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.141593f

class Cuboid	//宣告長方體類別
{
private:
	int length;	//Cuboid的資料成員1
	int width;	//Cuboid的資料成員2
	int height;	//Cuboid的資料成員3
public:
	void setCuboid(int l, int w, int h)	//設定Cuboid資料成員
	{
		length = l;
		width = w;
		height = h;
	}
	int getLength()	//取得length資料函數
	{
		return length;
	}
	int getWidth()	//取得width資料函數
	{
		return width;
	}
	int getHeight()	//取得height資料函數
	{
		return height;
	}
	int area()	//計算長方體表面積函數
	{
		return 2 * (length * width 
			+ width * height 
			+ height * length);
	}
	int volumn()	//計算長方體體積函數
	{
		return length * width * height;
	}
};

class Cylinder	//宣告圓柱體類別
{
	float radius;	//Cylinder的資料成員1
	float height;	//Cylinder的資料成員2
public:
	void setCylinder(float r, float h)	//設定Cylinder資料成員
	{
		radius = r;
		height = h;
	}
	float getRadius()	//取得radius資料函數
	{
		return radius;
	}
	float getHeight()	//取得height資料函數
	{
		return height;
	}
	float area()	//計算圓柱體表面積函數
	{
		return 2 * PI * radius * height;
	}
	float volumn()	//計算圓柱體體積函數
	{
		return PI * float(pow(radius, 2)) * height;
	}
};

int main(int argc, char** argv)
{
	Cuboid rt;	//建立Cuboid物件
	rt.setCuboid(6, 8, 10);	//起始rt物件資料
	cout << "長方體：\n";
	cout << "長 = " << rt.getLength() << endl;	//輸出長方體的長
	cout << "寬 = " << rt.getWidth() << endl;	//輸出長方體的寬
	cout << "高 = " << rt.getHeight() << endl;	//輸出長方體的高
	cout << "表面積 = " << rt.area() << "平方公分\n";	//輸出長方體表面積
	cout << "體積 = " << rt.volumn() << "立方公分\n\n";	//輸出長方體體積

	Cylinder cl;	//建立Cylinder物件
	cl.setCylinder(5.0, 10.0);	//起始cl物件資料
	cout << "圓柱體：\n";
	cout << "半徑 = " << cl.getRadius() << endl;	//輸出圓柱體半徑
	cout << "高 = " << cl.getHeight() << endl;	//輸出長方體的高
	cout << "表面積 = " << cl.area() << "平方公分\n";	//輸出圓柱體表面積
	cout << "體積 = " << cl.volumn() << "立方公分\n";	//輸出圓柱體體積
	return 0;
}
