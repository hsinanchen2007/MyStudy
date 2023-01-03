// Upcast.cpp
// -----------------------------------------------
#include <iostream>
using namespace std;

//---- 宣告類別 Shape ----------------------------
class Shape
{ 
	private:
		int i;
	public:
		Shape(): i(7){}
		~Shape(){}
		virtual void Draw()  {cout<<" 畫個圖.\n";}
		virtual void Area()  {cout<<" 圖的面積.\n";}
		virtual void Erase() {cout<<" 將圖清除.\n";}
		void ObjectSize()    { Area();}
};

//---- 宣告類別 Circle ---------------------------
class Circle : public Shape
{ 
	private:
		int r;
	public:
		Circle(): r(5)      {}
		Circle(int N): r(N) {}
		~Circle()           {}
		void Draw()  {cout<<" 畫一個圓形.\n";}
		void Area()  {cout<<" 圓形的面積為 PI*R*R.\n";}
		void Erase() {cout<<" 把圓形清除.\n";}
};

void Remove(Shape& S1) {S1.Erase();}

// ---- 主程式 -----------------------------------
int main()
{
	Circle C2;
	Shape* pS;

	pS = &C2;

	cout << "<1> 執行「pS->Draw();」之後:" << endl;
	pS->Draw();

	cout << "<2> 執行「pS->ObjectSize();」之後:" << endl;
	pS->ObjectSize();

	cout << "<3> 執行「Remove(C2);」之後:" << endl;
	Remove(C2);

	system("pause");
	return 0;
}
