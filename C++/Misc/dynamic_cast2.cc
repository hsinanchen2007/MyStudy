/*
    2) 向下转型（Downcasting）
    向下转型是有风险的，dynamic_cast 会借助 RTTI 信息进行检测，确定安全的才能转换成功，否则就转换失败。那么，
    哪些向下转型是安全地呢，哪些又是不安全的呢？下面我们通过一个例子来演示：

    Downcasting failed: A* to B*
    Downcasting failed: A* to C*
    -------------------------
    Downcasting successfully: A* to B*
    Class D
    Downcasting successfully: A* to C*
    Class D

    这段代码中类的继承顺序为：A --> B --> C --> D。pa 是A*类型的指针，当 pa 指向 A 类型的对象时，向下转型失败，
    pa 不能转换为B*或C*类型。当 pa 指向 D 类型的对象时，向下转型成功，pa 可以转换为B*或C*类型。同样都是向下转型，
    为什么 pa 指向的对象不同，转换的结果就大相径庭呢？

    在《C++ RTTI机制下的对象内存模型（透彻）》一节中，我们讲到了有虚函数存在时对象的真实内存模型，并且也了解到，
    每个类都会在内存中保存一份类型信息，编译器会将存在继承关系的类的类型信息使用指针“连接”起来，从而形成一个继承链
    （Inheritance Chain），也就是如下图所示的样子：

    当使用 dynamic_cast 对指针进行类型转换时，程序会先找到该指针指向的对象，再根据对象找到当前类（指针指向的对象所属
    的类）的类型信息，并从此节点开始沿着继承链向上遍历，如果找到了要转化的目标类型，那么说明这种转换是安全的，就能够转换
    成功，如果没有找到要转换的目标类型，那么说明这种转换存在较大的风险，就不能转换。

    对于本例中的情况①，pa 指向 A 类对象，根据该对象找到的就是 A 的类型信息，当程序从这个节点开始向上遍历时，发现 A 
    的上方没有要转换的 B 类型或 C 类型（实际上 A 的上方没有任何类型了），所以就转换败了。对于情况②，pa 指向 D 类对象，
    根据该对象找到的就是 D 的类型信息，程序从这个节点向上遍历的过程中，发现了 C 类型和 B 类型，所以就转换成功了。

    总起来说，dynamic_cast 会在程序运行过程中遍历继承链，如果途中遇到了要转换的目标类型，那么就能够转换成功，如果直到
    继承链的顶点（最顶层的基类）还没有遇到要转换的目标类型，那么就转换失败。对于同一个指针（例如 pa），它指向的对象不同，
    会导致遍历继承链的起点不一样，途中能够匹配到的类型也不一样，所以相同的类型转换产生了不同的结果。

    从表面上看起来 dynamic_cast 确实能够向下转型，本例也很好地证明了这一点：B 和 C 都是 A 的派生类，我们成功地将 pa 
    从 A 类型指针转换成了 B 和 C 类型指针。但是从本质上讲，dynamic_cast 还是只允许向上转型，因为它只会向上遍历继承链。
    造成这种假象的根本原因在于，派生类对象可以用任何一个基类的指针指向它，这样做始终是安全的。本例中的情况②，pa 指向的
    对象是 D 类型的，pa、pb、pc 都是 D 的基类的指针，所以它们都可以指向 D 类型的对象，dynamic_cast 只是让不同的基类
    指针指向同一个派生类对象罢了。
*/

#include <iostream>

using namespace std;

class A{
public:
    virtual void func() const { cout<<"Class A"<<endl; }
private:
    int m_a;
};

class B: public A{
public:
    virtual void func() const { cout<<"Class B"<<endl; }
private:
    int m_b;
};

class C: public B{
public:
    virtual void func() const { cout<<"Class C"<<endl; }
private:
    int m_c;
};

class D: public C{
public:
    virtual void func() const { cout<<"Class D"<<endl; }
private:
    int m_d;
};

int main(){
    A *pa = new A();
    B *pb;
    C *pc;
   
    //情况①
    pb = dynamic_cast<B*>(pa);  //向下转型失败
    if(pb == NULL){
        cout<<"Downcasting failed: A* to B*"<<endl;
    }else{
        cout<<"Downcasting successfully: A* to B*"<<endl;
        pb -> func();
    }
    pc = dynamic_cast<C*>(pa);  //向下转型失败
    if(pc == NULL){
        cout<<"Downcasting failed: A* to C*"<<endl;
    }else{
        cout<<"Downcasting successfully: A* to C*"<<endl;
        pc -> func();
    }
   
    cout<<"-------------------------"<<endl;
   
    //情况②
    pa = new D();  //向上转型都是允许的
    pb = dynamic_cast<B*>(pa);  //向下转型成功
    if(pb == NULL){
        cout<<"Downcasting failed: A* to B*"<<endl;
    }else{
        cout<<"Downcasting successfully: A* to B*"<<endl;
        pb -> func();
    }
    pc = dynamic_cast<C*>(pa);  //向下转型成功
    if(pc == NULL){
        cout<<"Downcasting failed: A* to C*"<<endl;
    }else{
        cout<<"Downcasting successfully: A* to C*"<<endl;
        pc -> func();
    }
   
    return 0;
}

// Downcasting failed: A* to B*
// Downcasting failed: A* to C*
// -------------------------
// Downcasting successfully: A* to B*
// Class D
// Downcasting successfully: A* to C*
// Class D

