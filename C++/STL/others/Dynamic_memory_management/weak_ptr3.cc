/*
    在 C++98/03 的基础上，C++11 标准新引入了 shared_ptr、unique_ptr 以及 weak_ptr 
    这 3 个智能指针。其中，shared_ptr 和 unique_ptr 已经在前面章节做了详细地介绍，
    本节重点讲解 weak_ptr 智能指针的特性和用法。

    注意学习 weak_ptr 智能指针之前，读者必须对 shared_ptr 智能指针有一定的了解，可阅读
    《C++11 shared_ptr智能指针》一节；关于 unique_ptr 指针，读者可阅读《C++11 unique_ptr智能指针》
    一节做系统学习。

    C++11 weak_ptr智能指针
    和 shared_ptr、unique_ptr 类型指针一样，weak_ptr 智能指针也是以模板类的方式实现的。
    weak_ptr<T>（ T 为指针所指数据的类型）定义在<memory>头文件，并位于 std 命名空间中。
    因此，要想使用 weak_ptr 类型指针，程序中应首先包含如下 2 条语句：
    
    #include <memory>
    using namespace std;
    第 2 句并不是必须的，可以不添加，则后续在使用 unique_ptr 指针时，必须标注std::。

    需要注意的是，C++11标准虽然将 weak_ptr 定位为智能指针的一种，但该类型指针通常不单独使用
    （没有实际用处），只能和 shared_ptr 类型指针搭配使用。甚至于，我们可以将 weak_ptr 类型
    指针视为 shared_ptr 指针的一种辅助工具，借助 weak_ptr 类型指针， 我们可以获取 shared_ptr 
    指针的一些状态信息，比如有多少指向相同的 shared_ptr 指针、shared_ptr 指针指向的堆内存
    是否已经被释放等等。

    需要注意的是，当 weak_ptr 类型指针的指向和某一 shared_ptr 指针相同时，weak_ptr 指针并
    不会使所指堆内存的引用计数加 1；同样，当 weak_ptr 指针被释放时，之前所指堆内存的引用计数也
    不会因此而减 1。也就是说，weak_ptr 类型指针并不会影响所指堆内存空间的引用计数。

    除此之外，weak_ptr<T> 模板类中没有重载 * 和 -> 运算符，这也就意味着，weak_ptr 类型指针
    只能访问所指的堆内存，而无法修改它。
    1、weak_ptr指针的创建
    创建一个 weak_ptr 指针，有以下 3 种方式：
    1) 可以创建一个空 weak_ptr 指针，例如：
    std::weak_ptr<int> wp1;

    2) 凭借已有的 weak_ptr 指针，可以创建一个新的 weak_ptr 指针，例如：
    std::weak_ptr<int> wp2 (wp1);
    若 wp1 为空指针，则 wp2 也为空指针；反之，如果 wp1 指向某一 shared_ptr 指针拥有的堆内存，
    则 wp2 也指向该块存储空间（可以访问，但无所有权）。

    3) weak_ptr 指针更常用于指向某一 shared_ptr 指针拥有的堆内存，因为在构建 weak_ptr 
    指针对象时，可以利用已有的 shared_ptr 指针为其初始化。例如：
    std::shared_ptr<int> sp (new int);
    std::weak_ptr<int> wp3 (sp);
    由此，wp3 指针和 sp 指针有相同的指针。再次强调，weak_ptr 类型指针不会导致堆内存空间的引用
    计数增加或减少。
    2) weak_ptr模板类提供的成员方法
    和 shared_ptr<T>、unique_ptr<T> 相比，weak_ptr<T> 模板类提供的成员方法不多，表 1 罗列
    了常用的成员方法及各自的功能。

    表 1 weak_ptr指针可调用的成员方法
    成员方法	功 能
    operator=()	重载 = 赋值运算符，是的 weak_ptr 指针可以直接被 weak_ptr 或者 shared_ptr 
    类型指针赋值。
    swap(x)	其中 x 表示一个同类型的 weak_ptr 类型指针，该函数可以互换 2 个同类型 weak_ptr 
    指针的内容。
    reset()	将当前 weak_ptr 指针置为空指针。
    use_count()	查看指向和当前 weak_ptr 指针相同的 shared_ptr 指针的数量。
    expired()	判断当前 weak_ptr 指针为否过期（指针为空，或者指向的堆内存已经被释放）。
    lock()	如果当前 weak_ptr 已经过期，则该函数会返回一个空的 shared_ptr 指针；反之，该函数
    返回一个和当前 weak_ptr 指向相同的 shared_ptr 指针。
    再次强调，weak_ptr<T> 模板类没有重载 * 和 -> 运算符，因此 weak_ptr 类型指针只能访问某一 \
    shared_ptr 指针指向的堆内存空间，无法对其进行修改。

    下面的样例演示了 weak_ptr 指针以及表 1 中部分成员方法的基本用法：
*/

#include <iostream>
#include <memory>

using namespace std;

int main()
{
    std::shared_ptr<int> sp1(new int(10));
    std::shared_ptr<int> sp2(sp1);
    std::weak_ptr<int> wp(sp2);

    //输出和 wp 同指向的 shared_ptr 类型指针的数量
    cout << wp.use_count() << endl;

    //释放 sp2
    sp2.reset();
    cout << wp.use_count() << endl;

    //借助 lock() 函数，返回一个和 wp 同指向的 shared_ptr 类型指针，获取其存储的数据
    cout << *(wp.lock()) << endl;

    return 0;
}

// 2
// 1
// 10
