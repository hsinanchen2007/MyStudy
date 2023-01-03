// Poly.cpp
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

	cout << "���� �upS=&C2�v����, " << endl;
	pS=&C2;
	cout << "�upS->Draw()�v�����G�O: ";
	pS->Draw();
	cout << "���� �upS=&CyL3�v����, " << endl;
	pS=&CyL3;
	cout << "�upS->Draw()�v�����G�O: ";
	pS->Draw();
	cout << "���� �upS=&T2�v����, " << endl;
	pS=&T2;
	cout << "�upS->Draw()�v�����G�O: ";
	pS->Draw();
	cout << "���� �upS=&Sq2�v����, " << endl;
	pS=&Sq2;
	cout << "�upS->Draw()�v�����G�O: ";
	pS->Draw();

	cout << endl;

	cout << "���� �uRemove(C2)�v�����G�O: " << endl;
	Remove(C2);

	cout << "���� �uRemove(CyL3)�v�����G�O: " << endl;
	Remove(CyL3);

	system("pause");
	return 0;
}
