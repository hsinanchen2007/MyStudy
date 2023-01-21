/*
    C++ inline内联函数详解
    < 上一节下一节 >

    函数是一个可以重复使用的代码块，CPU 会一条一条地挨着执行其中的代码。CPU 在执行主调函数代码时如果遇到了被调函数，
    主调函数就会暂停，CPU 转而执行被调函数的代码；被调函数执行完毕后再返回到主调函数，主调函数根据刚才的状态继续往下执行。

    一个 C/C++ 程序的执行过程可以认为是多个函数之间的相互调用过程，它们形成了一个或简单或复杂的调用链条，这个链条的起点是 
    main()，终点也是 main()。当 main() 调用完了所有的函数，它会返回一个值（例如return 0;）来结束自己的生命，从而结束
    整个程序。

    函数调用是有时间和空间开销的。程序在执行一个函数之前需要做一些准备工作，要将实参、局部变量、返回地址以及若干寄存器都
    压入栈中，然后才能执行函数体中的代码；函数体中的代码执行完毕后还要清理现场，将之前压入栈中的数据都出栈，才能接着执行函数
    调用位置以后的代码。关于函数调用的细节，我们已经在《C语言内存精讲》一章中的《一个函数在栈上到底是怎样的》《用一个实例来
    深入剖析函数进栈出栈的过程》两节中讲到。

    如果函数体代码比较多，需要较长的执行时间，那么函数调用机制占用的时间可以忽略；如果函数只有一两条语句，那么大部分的时间
    都会花费在函数调用机制上，这种时间开销就就不容忽视。

    为了消除函数调用的时空开销，C++ 提供一种提高效率的方法，即在编译时将函数调用处用函数体替换，类似于C语言中的宏展开。
    这种在函数调用处直接嵌入函数体的函数称为内联函数（Inline Function），又称内嵌函数或者内置函数。

    指定内联函数的方法很简单，只需要在函数定义处增加 inline 关键字。请看下面的例子：

    注意，要在函数定义处添加 inline 关键字，在函数声明处添加 inline 关键字虽然没有错，但这种做法是无效的，编译器会忽略函数
    声明处的 inline 关键字。

    当编译器遇到函数调用swap(&m, &n)时，会用 swap() 函数的代码替换swap(&m, &n)，同时用实参代替形参。这样，程序第 16 
    行就被置换成：

        int temp;
        temp = *(&m);
        *(&m) = *(&n);
        *(&n) = temp;

    编译器可能会将 *(&m)、*(&n) 分别优化为 m、n。

    当函数比较复杂时，函数调用的时空开销可以忽略，大部分的 CPU 时间都会花费在执行函数体代码上，所以我们一般是将非常短小的函数
    声明为内联函数。

    使用内联函数的缺点也是非常明显的，编译后的程序会存在多份相同的函数拷贝，如果被声明为内联函数的函数体非常大，那么编译后的程序
    体积也将会变得很大，所以再次强调，一般只将那些短小的、频繁调用的函数声明为内联函数。

    内联函数看起来简单，但是有很多细节要引起重视，我们将在后续两节《C++内联函数也可以用来代替宏》《如何规范地使用C++内联函数》
    对内联函数的本质以及使用规范进行深入的讲解。

    最后需要说明的是，对函数作 inline 声明只是程序员对编译器提出的一个建议，而不是强制性的，并非一经指定为 inline 编译器就
    必须这样做。编译器有自己的判断能力，它会根据具体情况决定是否这样做。
*/

#include <iostream>

using namespace std;

//内联函数，交换两个数的值
inline void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int m, n;
    cin>>m>>n;

    cout<<m<<", "<<n<<endl;

    // compiler will expand the real code in swap() here so it saves unnecessary runtime between main and 
    // other functions, so once it is compiled, the main function will have real code in swap to main
    swap(&m, &n);

    cout<<m<<", "<<n<<endl;

    return 0;
}

// 1
// 3
// 1, 3
// 3, 1