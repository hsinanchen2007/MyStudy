// PureDef.cpp
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
		virtual void Rotate() =0;
		virtual void Erase()=0;
		virtual void Center()=0;
};

//---定義純虛擬函數 Center() -----------
void Shape::Center()
{cout << "Center point\n";}

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
		void Erase() {cout<<"把圓形清除\n";}
		void Center(){Shape::Center();}
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
		void Rotate()  {cout<<"將圓柱形迴轉\n";}
		void Erase() {cout<<"把圓柱形清除\n";}
};

//---定義函數 MakeCenter() -----------
void MakeCenter(Shape &S1) {S1.Center();}

// ----主程式---------------------------
int main()
{
	Circle   C1;
	Cylinder CyL;
	Shape* pS;
	pS = &C1;
	cout << "執行 「pS=&C1」之後, " << endl;
	cout << "「pS->Center()」的結果是: ";
	pS->Center();

	pS = &CyL;
	cout << "執行 「pS=&CyL」之後, " << endl;
	cout << "「pS->Center()」的結果是: ";
	pS->Center();

	cout << "「MakeCenter(C1)」 : ";
	MakeCenter(C1);
	cout << "「MakeCenter(CyL)」: ";
	MakeCenter(CyL);

	system("pause");
	return 0;
}
