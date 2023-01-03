// V-Destructor.cpp
// --------------------------------------
#include <iostream>
using namespace std;

//---- �ŧi���O Shape --------
class Shape
{
	private:
		int i;
	public:
		Shape(): i(7)  
			{cout << "  Shape    �غc���\n";}
		~Shape()
			{cout << "  Shape    �Ѻc���\n";}
		virtual void Rotate()   
			{cout << "�N�ϰj�� \n";}
		virtual void Erase()  
			{cout << "�N�ϲM��\n";}
};

//---- �ŧi���O Circle--------
class Circle : public Shape
{
	private:
		int r;
	public:
		Circle(): r(5)      
			{cout << "  Circle   �غc���\n";}
		Circle(int N): r(N) 
			{cout << "  Circle   �غc���\n";}
		~Circle()           
			{cout << "  Circle   �Ѻc���\n";}
		void Rotate()  {cout<<"�N��ΰj��\n";}
		void Erase()   {cout<<"���βM�� \n";}
};

//---- �ŧi���O Cylinder--------
class Cylinder : public Circle
{
	private:
		int r, h;
	public:
		Cylinder(): r(5), h(1)    
			{cout << "  Cylinder �غc���\n";}
		Cylinder(int M, int N): r(M), h(N)
			{cout << "  Cylinder �غc���\n";}
		~Cylinder()         
			{cout << "  Cylinder �Ѻc���\n";}
		void Rotate(){cout<<"�N��W�ΰj��\n";}
		void Erase() {cout<<"���W�βM�� \n";}
};

// ----�D�{��---------------------------
int main()
{
  cout << "(1) �w�q�@�� Circle:\n";
  Shape* pS1 = new Circle;
  cout << "(2) �w�q�@�� Cylinder:\n";
  Shape* pS2 = new Cylinder;
  cout << "(3) �M�� pS1:\n";
  delete pS1;
  cout << "(4) �M�� pS2:\n";
  delete pS2;

  system("pause");
  return 0;
}
	