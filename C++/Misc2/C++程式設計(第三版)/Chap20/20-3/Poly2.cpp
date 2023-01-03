// Poly2.cpp
// --------------------------------------
#include <iostream>
using namespace std;

//---- �ŧi���O Shape -------------------
class Shape
{
	private:
		int i;
	public:
		Shape(): i(7){}
		~Shape(){}
		virtual void Draw()  {cout<<"�e�ӹ�\n";}
		virtual void Erase() {cout<<"�N�ϲM��\n";}
};

//---- �ŧi���O Circle -------------------
class Circle : public Shape
{
	private:
		int r;
	public:
		Circle(): r(5)      {}
		Circle(int N): r(N) {}
		~Circle()           {}
		void Draw()  {cout<<"�e�@�Ӷ��\n";}
		void Erase() {cout<<"���βM��\n";}
};

//---- �ŧi���O Square -------------------
class Square : public Shape
{
	private:
		int a;
	public:
		Square(): a(2)      {}
		Square(int N): a(N) {}
		~Square()           {}
		void Draw()  {cout<<"�e�@�ӥ����\n";}
		void Erase() {cout<<"�⥿��βM��\n";}
};

//---- �ŧi���O Triangle -----------------
class Triangle : public Shape
{
	private:
		int a, b, c;
	public:
		Triangle(): a(1), b(1), c(1)      {}
		Triangle(int L, int M, int N): a(L), b(M), c(N) {}
		~Triangle()           {}
		void Draw()  {cout<<"�e�@�ӤT����\n";}
		void Erase() {cout<<"��T���βM��\n";}
};

//---- �ŧi���O Cylinder ------------------
class Cylinder : public Circle
{
	private:
		int r, h;
	public:
		Cylinder(): r(5), h(1)    {}
		Cylinder(int M, int N): r(M), h(N) {}
		~Cylinder()         {}
		void Draw()  {cout<<"�e�@�Ӷ�W��\n";}
		void Erase() {cout<<"���W�βM��\n";}
};

void Remove(Shape& S1) {S1.Erase();}

// ----�D�{��---------------------------
int main()
{
	Circle   C2;
	Cylinder CyL3;
	Triangle T2;
	Square   Sq2;
	Shape* pS;
  
	cout << "T2 �� " << sizeof(T2)/sizeof(int)
			<< " �� int." << endl;
	cout << "CyL3 �� " << sizeof(CyL3)/sizeof(int)
			<< " �� int." << endl;

	system("pause");
	return 0;
}
	