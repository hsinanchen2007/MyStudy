// VDestructor.cpp
// --------------------------------------
#include <iostream>
using namespace std;

//---- 宣告類別 Shape --------
class Shape
{
	private:
		int i;
	public:
		Shape(): i(7)  
			{cout << "  Shape    建構函數\n";}
		virtual ~Shape()
			{cout << "  Shape    解構函數\n";}
		virtual void Rotate()   
			{cout << "將圖迴轉 \n";}
		virtual void Erase()  
			{cout << "將圖清除\n";}
};

//---- 宣告類別 Circle--------
class Circle : public Shape
{
	private:
		int r;
	public:
		Circle(): r(5)      
			{cout << "  Circle   建構函數\n";}
		Circle(int N): r(N) 
			{cout << "  Circle   建構函數\n";}
		~Circle()           
			{cout << "  Circle   解構函數\n";}
		void Rotate()  {cout<<"將圓形迴轉\n";}
		void Erase()   {cout<<"把圓形清除 \n";}
};

//---- 宣告類別 Cylinder--------
class Cylinder : public Circle
{
	private:
		int r, h;
	public:
		Cylinder(): r(5), h(1)    
			{cout << "  Cylinder 建構函數\n";}
		Cylinder(int M, int N): r(M), h(N)
			{cout << "  Cylinder 建構函數\n";}
		~Cylinder()         
			{cout << "  Cylinder 解構函數\n";}
		void Rotate(){cout<<"將圓柱形迴轉\n";}
		void Erase() {cout<<"把圓柱形清除 \n";}
};

// ----主程式---------------------------
int main()
{
	cout << "(1) 定義一個 Circle:\n";
	Shape* pS1 = new Circle;
	cout << "(2) 定義一個 Cylinder:\n";
	Shape* pS2 = new Cylinder;
	cout << "(3) 清除 pS1:\n";
	delete pS1;
	cout << "(4) 清除 pS2:\n";
	delete pS2;

	system("pause");
	return 0;
}
