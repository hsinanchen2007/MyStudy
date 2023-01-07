//檔案名稱：d:\C++11\C1101.cpp
#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.141593

struct Cuboid	//宣告Cuboid結構
{
	int length;	//Cuboid的資料成員1
	int width;	//Cuboid的資料成員2
	int height;	//Cuboid的資料成員3
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

int main(int argc, char** argv)
{
	Cuboid rt = {6, 8, 10};	//建立Cuboid結構變數
	cout << "長方體：\n";
	cout << "長 = " << rt.length << endl;	//輸出長方體的長
	cout << "寬 = " << rt.width << endl;	//輸出長方體的寬
	cout << "高 = " << rt.height << endl;	//輸出長方體的高
	cout << "表面積 = " << area(rt) << "平方公分\n";	//輸出長方體表面積
	cout << "體積 = " << volumn(rt) << "立方公分\n";	//輸出長方體體積
	return 0;
}
