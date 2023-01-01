/*
    上节讲到，隐式类型转换是安全的，显式类型转换是有风险的，C语言之所以增加强制类型转换的语法，
    就是为了强调风险，让程序员意识到自己在做什么。

    但是，这种强调风险的方式还是比较粗放，粒度比较大，它并没有表明存在什么风险，风险程度如何。
    再者，C风格的强制类型转换统一使用( )，而( )在代码中随处可见，所以也不利于使用文本检索工具
    （例如 Windows 下的 Ctrl+F、Linux 下的 grep 命令、Mac 下的 Command+F）定位关键代码。

    为了使潜在风险更加细化，使问题追溯更加方便，使书写格式更加规范，C++ 对类型转换进行了分类，
    并新增了四个关键字来予以支持，它们分别是：

    关键字	说明
    static_cast	用于良性转换，一般不会导致意外发生，风险很低。
    const_cast	用于 const 与非 const、volatile 与非 volatile 之间的转换。
    reinterpret_cast	高度危险的转换，这种转换仅仅是对二进制位的重新解释，不会借助已有的转换规则对数据进行调整，
    但是可以实现最灵活的 C++ 类型转换。
    dynamic_cast	借助 RTTI，用于类型安全的向下转型（Downcasting）。

    这四个关键字的语法格式都是一样的，具体为：
    xxx_cast<newType>(data)

    newType 是要转换成的新类型，data 是被转换的数据。例如，老式的C风格的 double 转 int 的写法为：
        double scores = 95.5;
        int n = (int)scores;

    C++ 新风格的写法为：
        double scores = 95.5;
        int n = static_cast<int>(scores);

    static_cast 关键字
    static_cast 只能用于良性转换，这样的转换风险较低，一般不会发生什么意外，例如：
    原有的自动类型转换，例如 short 转 int、int 转 double、const 转非 const、向上转型等；
    void 指针和具体类型指针之间的转换，例如void *转int *、char *转void *等；
    有转换构造函数或者类型转换函数的类与其它类型之间的转换，例如 double 转 Complex（调用转换构造函数）、
    Complex 转 double（调用类型转换函数）。

    需要注意的是，static_cast 不能用于无关类型之间的转换，因为这些转换都是有风险的，例如：
    两个具体类型指针之间的转换，例如int *转double *、Student *转int *等。不同类型的数据存储格式不一样，
    长度也不一样，用 A 类型的指针指向 B 类型的数据后，会按照 A 类型的方式来处理数据：如果是读取操作，可能会
    得到一堆没有意义的值；如果是写入操作，可能会使 B 类型的数据遭到破坏，当再次以 B 类型的方式读取数据时会
    得到一堆没有意义的值。

    int 和指针之间的转换。将一个具体的地址赋值给指针变量是非常危险的，因为该地址上的内存可能没有分配，
    也可能没有读写权限，恰好是可用内存反而是小概率事件。

    static_cast 也不能用来去掉表达式的 const 修饰和 volatile 修饰。换句话说，不能将 const/volatile 
    类型转换为非 const/volatile 类型。

    static_cast 是“静态转换”的意思，也就是在编译期间转换，转换失败的话会抛出一个编译错误。

    下面的代码演示了 static_cast 的正确用法和错误用法：
*/

#include <iostream>
#include <cstdlib>

using namespace std;

class Complex{
    public:
        Complex(double real = 0.0, double imag = 0.0): m_real(real), m_imag(imag){ }
    public:
        operator double() const { return m_real; }  //类型转换函数
    private:
        double m_real;
        double m_imag;
};

int main(){
    //下面是正确的用法
    int m = 100;
    Complex c(12.5, 23.8);

    long n = static_cast<long>(m);  //宽转换，没有信息丢失
    char ch = static_cast<char>(m);  //窄转换，可能会丢失信息
    int *p1 = static_cast<int*>( malloc(10 * sizeof(int)) );  //将void指针转换为具体类型指针
    void *p2 = static_cast<void*>(p1);  //将具体类型指针，转换为void指针
    double real= static_cast<double>(c);  //调用类型转换函数
   
    //下面的用法是错误的
    // float *p3 = static_cast<float*>(p1);  //不能在两个具体类型的指针之间进行转换
    // p3 = static_cast<float*>(0X2DF9);  //不能将整数转换为指针类型

    return 0;
}
