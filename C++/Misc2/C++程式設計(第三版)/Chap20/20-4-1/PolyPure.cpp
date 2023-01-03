// PolyPure.cpp
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
		virtual void Draw() =0;
		virtual void Erase()=0;
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
		void Draw()  {cout<<"畫一個圓形.\n";}
		void Erase() {cout<<"把圓形清除.\n";}
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
		void Draw()  {cout<<"畫一個圓柱形.\n";}
		void Erase() {cout<<"把圓柱形清除.\n";}
};

void Make(Shape &S1) {S1.Draw();}

// ----主程式---------------------------
int main()
{
	Circle   C1;
	Cylinder CyL;
	Shape    *pS;

	cout << "「Make(C1))」 : ";
	Make(C1);
	cout << "「Make(CyL))」: ";
	Make(CyL);

	pS = &C1;
	cout << "執行「pS=&C1」之後," << endl;
	cout << "「pS->Erase()」的結果是: ";
	pS->Erase();

	pS = &CyL;
	cout << "執行「pS=&CyL」之後," << endl;
	cout << "「pS->Erase()」的結果是: ";
	pS->Erase();

	system("pause");
	return 0;
}
