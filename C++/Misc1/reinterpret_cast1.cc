/*
    reinterpret_cast 关键字
    reinterpret 是“重新解释”的意思，顾名思义，reinterpret_cast 这种转换仅仅是对二进制位的重新解释，
    不会借助已有的转换规则对数据进行调整，非常简单粗暴，所以风险很高。

    reinterpret_cast 可以认为是 static_cast 的一种补充，一些 static_cast 不能完成的转换，就可以用 
    reinterpret_cast 来完成，例如两个具体类型指针之间的转换、int 和指针之间的转换（有些编译器只允许 int 
    转指针，不允许反过来）。

    下面的代码代码演示了 reinterpret_cast 的使用：

    可以想象，用一个 float 指针来操作一个 char 数组是一件多么荒诞和危险的事情，这样的转换方式不到万不得已
    的时候不要使用。将A*转换为int*，使用指针直接访问 private 成员刺穿了一个类的封装性，更好的办法是让类提供
    get/set 函数，间接地访问成员变量。
*/

#include <iostream>

using namespace std;

class A{
public:
    A(int a = 0, int b = 0): m_a(a), m_b(b){}
private:
    int m_a;
    int m_b;
};

int main(){
    //将 char* 转换为 float*
    char str[]="http://c.biancheng.net";
    float *p1 = reinterpret_cast<float*>(str);
    cout<<*p1<<endl;    

    //将 int 转换为 int*, 
    int *p = reinterpret_cast<int*>(100);
    cout<<p<<endl;

    //将 A* 转换为 int*
    p = reinterpret_cast<int*>(new A(25, 96));
    cout<<*p<<endl;
   
    return 0;
}

// 3.0262e+29
// 0x64
// 25

