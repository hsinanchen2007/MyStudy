// PureDef.cpp
// --------------------------------------
#include <iostream>
using namespace std;

//---- �ŧi���O Shape --------
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

//---�w�q�µ������ Center() -----------
void Shape::Center()
{cout << "Center point\n";}

//---- �ŧi���O Circle--------
class Circle : public Shape
{
	private:
		int r;
	public:
		Circle(): r(5)      {}
		Circle(int N): r(N) {}
		~Circle()           {}
		void Rotate()  {cout<<"�N��ΰj��\n";}
		void Erase() {cout<<"���βM��\n";}
		void Center(){Shape::Center();}
};

//---- �ŧi���O Cylinder--------
class Cylinder : public Circle
{
	private:
		int r, h;
	public:
		Cylinder(): r(5), h(1)    {}
		Cylinder(int M, int N): r(M), h(N) {}
		~Cylinder()         {}
		void Rotate()  {cout<<"�N��W�ΰj��\n";}
		void Erase() {cout<<"���W�βM��\n";}
};

//---�w�q��� MakeCenter() -----------
void MakeCenter(Shape &S1) {S1.Center();}

// ----�D�{��---------------------------
int main()
{
	Circle   C1;
	Cylinder CyL;
	Shape* pS;
	pS = &C1;
	cout << "���� �upS=&C1�v����, " << endl;
	cout << "�upS->Center()�v�����G�O: ";
	pS->Center();

	pS = &CyL;
	cout << "���� �upS=&CyL�v����, " << endl;
	cout << "�upS->Center()�v�����G�O: ";
	pS->Center();

	cout << "�uMakeCenter(C1)�v : ";
	MakeCenter(C1);
	cout << "�uMakeCenter(CyL)�v: ";
	MakeCenter(CyL);

	system("pause");
	return 0;
}
