/*
    dynamic_cast 关键字
    dynamic_cast 用于在类的继承层次之间进行类型转换，它既允许向上转型（Upcasting），也允许向下转型（Downcasting）。
    向上转型是无条件的，不会进行任何检测，所以都能成功；向下转型的前提必须是安全的，要借助 RTTI 进行检测，所有只有一部分
    能成功。

    dynamic_cast 与 static_cast 是相对的，dynamic_cast 是“动态转换”的意思，static_cast 是“静态转换”的意思。
    dynamic_cast 会在程序运行期间借助 RTTI 进行类型转换，这就要求基类必须包含虚函数；static_cast 在编译期间完成类型
    转换，能够更加及时地发现错误。

    dynamic_cast 的语法格式为：
    dynamic_cast <newType> (expression)

    newType 和 expression 必须同时是指针类型或者引用类型。换句话说，dynamic_cast 只能转换指针类型和引用类型，其它类型
    （int、double、数组、类、结构体等）都不行。

    对于指针，如果转换失败将返回 NULL；对于引用，如果转换失败将抛出std::bad_cast异常。
    1) 向上转型（Upcasting）
    向上转型时，只要待转换的两个类型之间存在继承关系，并且基类包含了虚函数（这些信息在编译期间就能确定），就一定能转换成功。
    因为向上转型始终是安全的，所以 dynamic_cast 不会进行任何运行期间的检查，这个时候的 dynamic_cast 和 static_cast 
    就没有什么区别了。

    「向上转型时不执行运行期检测」虽然提高了效率，但也留下了安全隐患，请看下面的代码：

    情况①是正确的，没有任何问题。对于情况②，pd 指向的是整型变量 n，并没有指向一个 Derived 类的对象，在使用 dynamic_cast 
    进行类型转换时也没有检查这一点，而是将 pd 的值直接赋给了 pb（这里并不需要调整偏移量），最终导致 pb 也指向了 n。因为 pb 
    指向的不是一个对象，所以get_a()得不到 m_a 的值（实际上得到的是一个垃圾值），pb2->func()也得不到 func() 函数的正确地址。
    pb2->func()得不到 func() 的正确地址的原因在于，pb2 指向的是一个假的“对象”，它没有虚函数表，也没有虚函数表指针，而 func() 
    是虚函数，必须到虚函数表中才能找到它的地址。
*/

#include <iostream>
#include <iomanip>
using namespace std;
class Base{
public:
    Base(int a = 0): m_a(a){ }
    int get_a() const{ return m_a; }
    virtual void func() const { }
protected:
    int m_a;
};

class Derived: public Base{
public:
    Derived(int a = 0, int b = 0): Base(a), m_b(b){ }
    int get_b() const { return m_b; }
private:
    int m_b;
};

int main(){
    //情况①
    Derived *pd1 = new Derived(35, 78);
    Base *pb1 = dynamic_cast<Derived*>(pd1);
    cout<<"pd1 = "<<pd1<<", pb1 = "<<pb1<<endl;
    cout<<pb1->get_a()<<endl;
    pb1->func();

    //情况②
    int n = 100;
    Derived *pd2 = reinterpret_cast<Derived*>(&n);
    Base *pb2 = dynamic_cast<Base*>(pd2);
    cout<<"pd2 = "<<pd2<<", pb2 = "<<pb2<<endl;
    cout<<pb2->get_a()<<endl;  //输出一个垃圾值
    pb2->func();  //内存错误

    return 0;
}

// pd1 = 0x559ab2d4de70, pb1 = 0x559ab2d4de70
// 35
// pd2 = 0x7ffed557727c, pb2 = 0x7ffed557727c
// 32766
// Segmentation fault

