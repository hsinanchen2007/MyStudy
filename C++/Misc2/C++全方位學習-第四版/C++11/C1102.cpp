//檔案名稱：d:\C++11\C1102.cpp
#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.141593f

struct Cuboid	//宣告Cuboid資料結構
{
	int length;	//Cuboid的資料成員1
	int width;	//Cuboid的資料成員2
	int height;	//Cuboid的資料成員3
};

struct Cylinder	//宣告Cylinder資料結構
{
	float radius;	//Cylinder的資料成員1
	float height;	//Cylinder的資料成員2
};

int area(Cuboid r)	//計算長方體表面積函數
{
	return 2 * (r.length * r.width 
		+ r.width * r.height 
		+ r.height * r.length);
}

int volumn(Cuboid r)	//計算長方體體積函數
{
	return r.length * r.width * r.height;
}

float area(Cylinder c)	//計算圓柱體表面積函數
{
	return 2 * PI * c.radius * c.height;
}

float volumn(Cylinder c)	//計算圓柱體體積函數
{
	return PI * float(pow(c.radius, 2)) * c.height;
}

int main(int argc, char** argv)
{
	Cuboid rt = {6, 8, 10};	//建立Cuboid結構資料
	cout << "長方體：\n";
	cout << "長 = " << rt.length << endl;	//輸出長方體的長
	cout << "寬 = " << rt.width << endl;	//輸出長方體的寬
	cout << "高 = " << rt.height << endl;	//輸出長方體的高
	cout << "表面積 = " << area(rt) << "平方公分\n";	//輸出長方體表面積
	cout << "體積 = " << volumn(rt) << "立方公分\n\n";	//輸出長方體體積

	Cylinder cl = {5.0, 10.0};	//建立Cylinder結構資料
	cout << "圓柱體：\n";
	cout << "半徑 = " << cl.radius << endl;	//輸出圓柱體半徑
	cout << "高 = " << cl.height << endl;	//輸出長方體的高
	cout << "表面積 = " << area(cl) << "平方公分\n";	//輸出圓柱體表面積
	cout << "體積 = " << volumn(cl) << "立方公分\n";	//輸出圓柱體體積
	return 0;
}
