// VOverload.cpp
// --------------------------------------
#include <iostream>
using namespace std;

//---- 宣告類別 Shape --------
class Shape
{
	private:
		int i;
	public:
		Shape(): i(7){}
		~Shape(){}
		virtual void Rotate()   {cout<<"將圖迴轉 \n";}
		virtual void Rotate(int N)
			{cout<<"將圖迴轉 "<< N << " 單位\n";}
		virtual void Erase()  {cout<<"將圖清除\n";}
};

//---- 宣告類別 Circle--------
class Circle : public Shape
{
	private:
		int r;
	public:
		Circle(): r(5)      {}
		Circle(int N): r(N) {}
		~Circle()           {}
		void Rotate()  {cout<<"將圓形迴轉\n";}
		void Erase()   {cout<<"把圓形清除 \n";}
};

//---- 宣告類別 Cylinder--------
class Cylinder : public Circle
{
	private:
		int r, h;	
	public:
		Cylinder(): r(5), h(1)    {}
		Cylinder(int M, int N): r(M), h(N) {}
		~Cylinder()         {}
		void Rotate(){cout<<"將圓柱形迴轉\n";}
		void Erase() {cout<<"把圓柱形清除 \n";}
};

// ----主程式---------------------------
int main()
{
	Circle C1;
	Cylinder CyL;
	Shape *pS = &C1;
	Shape &S1 = CyL;
	cout << "「pS->Rotate()」 : ";
	pS->Rotate();
	cout << "「pS->Rotate(2)」: ";
	pS->Rotate(2);
	cout << "「 S1.Rotate()」 : ";
	S1.Rotate();
	cout << "「 S1.Rotate(4)」: ";
	S1.Rotate(4);

	system("pause");
	return 0;
}
