// Poly.cpp
// --------------------------------------
#include <iostream>
using namespace std;

//---- 宣告類別 Shape -------------------
class Shape
{
	private:
		int i;
	public:
		Shape(): i(7){}
		~Shape(){}
		virtual void Draw()  {cout<<"畫個圖\n";}
		virtual void Erase() {cout<<"將圖清除\n";}
};

//---- 宣告類別 Circle -------------------
class Circle : public Shape
{
	private:
		int r;
	public:
		Circle(): r(5)      {}
		Circle(int N): r(N) {}
		~Circle()           {}
		void Draw()  {cout<<"畫一個圓形\n";}
		void Erase() {cout<<"把圓形清除\n";}
};

//---- 宣告類別 Square -------------------
class Square : public Shape
{
	private:
		int a;
	public:
		Square(): a(2)      {}
		Square(int N): a(N) {}
		~Square()           {}
		void Draw()  {cout<<"畫一個正方形\n";}
		void Erase() {cout<<"把正方形清除\n";}
};

//---- 宣告類別 Triangle -----------------
class Triangle : public Shape
{
	private:
		int a, b, c;
	public:
		Triangle(): a(1), b(1), c(1)      {}
		Triangle(int L, int M, int N): a(L), b(M), c(N) {}
		~Triangle()           {}
		void Draw()  {cout<<"畫一個三角形\n";}
		void Erase() {cout<<"把三角形清除\n";}
};

//---- 宣告類別 Cylinder ------------------
class Cylinder : public Circle
{
	private:
		int r, h;
	public:
		Cylinder(): r(5), h(1)    {}
		Cylinder(int M, int N): r(M), h(N) {}
		~Cylinder()         {}
		void Draw()  {cout<<"畫一個圓柱形\n";}
		void Erase() {cout<<"把圓柱形清除\n";}
};

void Remove(Shape& S1) {S1.Erase();}

// ----主程式---------------------------
int main()
{
	Circle   C2;
	Cylinder CyL3;
	Triangle T2;
	Square   Sq2;
	Shape* pS;

	cout << "執行 「pS=&C2」之後, " << endl;
	pS=&C2;
	cout << "「pS->Draw()」的結果是: ";
	pS->Draw();
	cout << "執行 「pS=&CyL3」之後, " << endl;
	pS=&CyL3;
	cout << "「pS->Draw()」的結果是: ";
	pS->Draw();
	cout << "執行 「pS=&T2」之後, " << endl;
	pS=&T2;
	cout << "「pS->Draw()」的結果是: ";
	pS->Draw();
	cout << "執行 「pS=&Sq2」之後, " << endl;
	pS=&Sq2;
	cout << "「pS->Draw()」的結果是: ";
	pS->Draw();

	cout << endl;

	cout << "執行 「Remove(C2)」的結果是: " << endl;
	Remove(C2);

	cout << "執行 「Remove(CyL3)」的結果是: " << endl;
	Remove(CyL3);

	system("pause");
	return 0;
}
