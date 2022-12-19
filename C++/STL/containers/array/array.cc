// https://leetcode.com/problems/

// some often common headers and namespace
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>

/*

array 容器是 C++ 11 标准中新增的序列容器，简单地理解，它就是在 C++ 普通数组的基础上，添加了一些成员函数和全局函数。在使用上，它比普通数组更安全
（原因后续会讲），且效率并没有因此变差。

和其它容器不同，array 容器的大小是固定的，无法动态的扩展或收缩，这也就意味着，在使用该容器的过程无法借由增加或移除元素而改变其大小，它只允许访问
或者替换存储的元素。
STL 还提供有可动态扩展或收缩存储空间的 vector 容器，后续章节会对其做详细介绍。

array 容器以类模板的形式定义在 <array> 头文件，并位于命名空间 std 中，如下所示：
namespace std{
    template <typename T, size_t N>
    class array;
}
因此，在使用该容器之前，代码中需引入 <array> 头文件，并默认使用 std 命令空间，如下所示：
#include <array>
using namespace std;
在 array<T,N> 类模板中，T 用于指明容器中的存储的具体数据类型，N 用于指明容器的大小，需要注意的是，这里的 N 必须是常量，不能用变量表示。

array 容器有多种初始化方式，如下代码展示了如何创建具有 10 个 double 类型元素的 array 容器：
std::array<double, 10> values;
提示，如果程序中已经默认指定了 std 命令空间，这里可以省略 std::。

由此，就创建好了一个名为 values 的 array 容器，其包含 10 个浮点型元素。但是，由于未显式指定这 10 个元素的值，因此使用这种方式创建的容器中，各个
元素的值是不确定的（array 容器不会做默认初始化操作）。

通过如下创建 array 容器的方式，可以将所有的元素初始化为 0 或者和默认元素类型等效的值：
std::array<double, 10> values {};
使用该语句，容器中所有的元素都会被初始化为 0.0。

当然，在创建 array 容器的实例时，也可以像创建常规数组那样对元素进行初始化：
std::array<double, 10> values {0.5,1.0,1.5,,2.0};
可以看到，这里只初始化了前 4 个元素，剩余的元素都会被初始化为 0.0。图 1 说明了这一点。

初始化array容器
图 1 初始化 array 容器

除此之外，array 容器还提供有很多功能实用的成员函数，如表 2 所示。

表 2 array容器成员函数汇总
成员函数	功能
begin()	返回指向容器中第一个元素的随机访问迭代器。
end()	返回指向容器最后一个元素之后一个位置的随机访问迭代器，通常和 begin() 结合使用。
rbegin()	返回指向最后一个元素的随机访问迭代器。
rend()	返回指向第一个元素之前一个位置的随机访问迭代器。
cbegin()	和 begin() 功能相同，只不过在其基础上增加了 const 属性，不能用于修改元素。
cend()	和 end() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
crbegin()	和 rbegin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
crend()	和 rend() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
size()	返回容器中当前元素的数量，其值始终等于初始化 array 类的第二个模板参数 N。
max_size()	返回容器可容纳元素的最大数量，其值始终等于初始化 array 类的第二个模板参数 N。
empty()	判断容器是否为空，和通过 size()==0 的判断条件功能相同，但其效率可能更快。
at(n)	返回容器中 n 位置处元素的引用，该函数自动检查 n 是否在有效的范围内，如果不是则抛出 out_of_range 异常。
front()	返回容器中第一个元素的直接引用，该函数不适用于空的 array 容器。
back()	返回容器中最后一个元素的直接应用，该函数同样不适用于空的 array 容器。
data()	返回一个指向容器首个元素的指针。利用该指针，可实现复制容器中所有元素等类似功能。
fill(val)	将 val 这个值赋值给容器中的每个元素。
array1.swap(array2)	交换 array1 和 array2 容器中的所有元素，但前提是它们具有相同的长度和类型。

除此之外，C++ 11 标准库还新增加了 begin() 和 end() 这 2 个函数，和 array 容器包含的 begin() 和 end() 成员函数不同的是，标准库提供的这 2 个函数
的操作对象，既可以是容器，还可以是普通数组。当操作对象是容器时，它和容器包含的 begin() 和 end() 成员函数的功能完全相同；如果操作对象是普通数组，则 
begin() 函数返回的是指向数组第一个元素的指针，同样 end() 返回指向数组中最后一个元素之后一个位置的指针（注意不是最后一个元素）。

另外，在 <array> 头文件中还重载了 get() 全局函数，该重载函数的功能是访问容器中指定的元素，并返回该元素的引用。

正是由于 array 容器中包含了 at() 这样的成员函数，使得操作元素时比普通数组更安全。

例如代码演示了表 2 中一部分成员函数的用法和功能：
#include <iostream>
//需要引入 array 头文件
#include <array>
using namespace std;
int main()
{
    std::array<int, 4> values{};
    //初始化 values 容器为 {0,1,2,3}
    for (int i = 0; i < values.size(); i++) {
        values.at(i) = i;
    }
    //使用 get() 重载函数输出指定位置元素
    cout << get<3>(values) << endl;
    //如果容器不为空，则输出容器中所有的元素
    if (!values.empty()) {
        for (auto val = values.begin(); val < values.end(); val++) {
            cout << *val << " ";
        }
    }
}
注意，代码中的 auto 关键字，可以使编译器自动判定变量的类型。运行这段代码，输出结果为：
3
0 1 2 3

表 2 中其他成员函数的用法，这里不再给出具体实例，有兴趣的读者，可自行根据各个函数的功能描述编写实例代码进行测试。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业故事+学习历程+工作记录+
生活日常+编程资料。


在《C++ STL迭代器（iterator）》一节中，已经对迭代器做了详细的介绍，STL 为 array 容器配备了随机访问迭代器，该类迭代器是功能最强大的迭代器。本节将
详细介绍 array 容器的迭代器的用法。

在 array 容器的模板类中，和随机访问迭代器相关的成员函数如表 1 所示。

表 1 array 支持迭代器的成员函数
成员函数	功能
begin()	返回指向容器中第一个元素的正向迭代器；如果是 const 类型容器，在该函数返回的是常量正向迭代器。
end()	返回指向容器最后一个元素之后一个位置的正向迭代器；如果是 const 类型容器，在该函数返回的是常量正向迭代器。此函数通常和 begin() 搭配使用。
rbegin()	返回指向最后一个元素的反向迭代器；如果是 const 类型容器，在该函数返回的是常量反向迭代器。
rend()	返回指向第一个元素之前一个位置的反向迭代器。如果是 const 类型容器，在该函数返回的是常量反向迭代器。此函数通常和 rbegin() 搭配使用。
cbegin()	和 begin() 功能类似，只不过其返回的迭代器类型为常量正向迭代器，不能用于修改元素。
cend()	和 end() 功能相同，只不过其返回的迭代器类型为常量正向迭代器，不能用于修改元素。
crbegin()	和 rbegin() 功能相同，只不过其返回的迭代器类型为常量反向迭代器，不能用于修改元素。
crend()	和 rend() 功能相同，只不过其返回的迭代器类型为常量反向迭代器，不能用于修改元素。
除此之外，C++ 11 标准新增的 begin() 和 end() 函数，当操作对象为 array 容器时，也和迭代器有关，其功能分别和表 1 中的 begin()、end() 成员函数相同，
具有用法本节后续会做详细介绍。

这些成员函数的具体功能如图 2 所示。

迭代器的具体功能示意图
图 2 迭代器的具体功能示意图

可以看到，根据它们的功能并结合实际场景的需要，这些成员函数通常是成对使用的，即 begin()/end()、rbegin()/rend()、cbegin()/cend()、crbegin()/crend() 
各自成对搭配使用。不仅如此，这 4 对中 begin()/end() 和 cbegin()/cend()、rbegin()/rend() 和 crbegin()/crend() 的功能大致是相同的（如图 2 所示），
唯一的区别就在于其返回的迭代器能否用来修改元素值。值得一提的是，以上函数在实际使用时，其返回值类型都可以使用 auto 关键字代替，编译器可以自行判断出该迭
代器的类型。

begin()/end() 和 cbegin()/cend()
array 容器模板类中的 begin() 和 end() 成员函数返回的都是正向迭代器，它们分别指向「首元素」和「尾元素+1」 的位置。在实际使用时，我们可以利用它们实现初
始化容器或者遍历容器中元素的操作。

例如，可以在循环中显式地使用迭代器来初始化 values 容器的值：
#include <iostream>
//需要引入 array 头文件
#include <array>
using namespace std;
int main()
{
    array<int, 5>values;
    int h = 1;
    auto first = values.begin();
    auto last = values.end();
    //初始化 values 容器为{1,2,3,4,5}
    while (first != last)
    {
        *first = h;
        ++first;
        h++;
    }
  
    first = values.begin();
    while (first != last)
    {
        cout << *first << " ";
        ++first;
    }
    return 0; 
}
输出结果为：
1 2 3 4 5

可以看出，迭代器对象是由 array 对象的成员函数 begin() 和 end() 返回的。我们可以像使用普通指针那样上使用迭代器对象。比如代码中，在保存了元素值后，
使用前缀 ++ 运算符对 first 进行自增，当 first 等于 end 时，所有的元素都被设完值，循环结束。

与此同时，还可以使用全局的 begin() 和 end() 函数来从容器中获取迭代器，因为当操作对象为 array 容器时，它们和 begin()/end() 成员函数是通用的。
所以上面代码中，first 和 last 还可以像下面这样定义：
auto first = std::begin(values);
auto last = std::end (values);
这样，容器中的一段元素可以由迭代器指定，这让我们有了对它们使用算法的可能。
需要注意的是，STL 标准库，不是只有 array 容器，当迭代器指向容器中的一个特定元素时，它们不会保留任何关于容器本身的信息，所以我们无法从迭代器中判断，
它是指向array 容器还是指向 vector 容器（该容器后续会讲）。


除此之外，array 模板类还提供了 cbegin() 和 cend() 成员函数，它们和 begin()/end() 唯一不同的是，前者返回的是 const 类型的正向迭代器，这就意味着，
有 cbegin() 和 cend() 成员函数返回的迭代器，可以用来遍历容器内的元素，也可以访问元素，但是不能对所存储的元素进行修改。

举个例子：
#include <iostream>
//需要引入 array 头文件
#include <array>
using namespace std;
int main()
{
    array<int, 5>values{1,2,3,4,5};
    int h = 1;
    auto first = values.cbegin();
    auto last = values.cend();
   
    //由于 *first 为 const 类型，不能用来修改元素
    //*first = 10;
   
    //遍历容器并输出容器中所有元素
    while (first != last)
    {
        //可以使用 const 类型迭代器访问元素
        cout << *first << " ";
        ++first;
    }
    return 0;
}
此程序的第 14 行代码中，我们尝试使用 first 迭代器修改 values 容器中的值，如果取消注释并运行此程序，编译器会提示你“不能给常量赋值”，即 *first 
是 const 类型常量，所以这么做是不对的。但 17~22 行代码遍历并访问容器的行为，是允许的。rbegin()/rend() 和 crbegin()/crend()
array 模板类中还提供了 rbegin()/rend() 和 crbegin()/crend() 成员函数，它们每对都可以分别得到指向最一个元素和第一个元素前一个位置的随机访问
迭代器，又称它们为反向迭代器（如图 2 所示）。

需要注意的是，在使用反向迭代器进行 ++ 或 -- 运算时，++ 指的是迭代器向左移动一位，-- 指的是迭代器向右移动一位，即这两个运算符的功能也“互换”了。

反向迭代器用于以逆序的方式处理元素。例如：
#include <iostream>
//需要引入 array 头文件
#include <array>
using namespace std;
int main()
{
    array<int, 5>values;
    int h = 1;
    auto first = values.rbegin();
    auto last = values.rend(); 
    //初始化 values 容器为 {5,4,3,2,1}
    while (first != last)
    {
        *first = h;
        ++first;
        h++;
    }
    //重新遍历容器，并输入各个元素
    first = values.rbegin();
    while (first != last)
    {
        cout << *first << " ";
        ++first;
    }
    return 0;
}
运行结果为：
1 2 3 4 5

可以看到，从最后一个元素开始循环，不仅完成了容器的初始化，还遍历输出了容器中的所有元素。结束迭代器指向第一个元素之前的位置，所以当 first 
指向第一个元素并 +1 后，循环就结朿了。

在反向迭代器上使用 ++ 递增运算符，会让迭代器用一种和普通正向迭代器移动方向相反的方式移动。

当然，在上面程序中，我们也可以使用 for 循环：
for (auto first = values.rbegin(); first != values.rend(); ++first) {
    cout << *first << " ";
}

crbegin()/crend() 组合和 rbegin()/crend() 组合的功能唯一的区别在于，前者返回的迭代器为 const 类型，即不能用来修改容器中的元素，除此之外
在使用上和后者完全相同。有关 crbegin()/crend() 成员函数，这里不再给出具体实例，有兴趣的读者，可自行编写代码进行测试。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业故事+学习历程+
工作记录+生活日常+编程资料。


当 array 容器创建完成之后，最常做的操作就是获取其中的元素，甚至有时还会通过循环结构获取多个元素。本节就对获取容器中元素的方法做个汇总。
访问array容器中单个元素
首先，可以通过容器名[]的方式直接访问和使用容器中的元素，这和 C++ 标准数组访问元素的方式相同，例如：
values[4] = values[3] + 2.O*values[1];
此行代码中，第 5 个元素的值被赋值为右边表达式的值。需要注意的是，使用如上这样方式，由于没有做任何边界检查，所以即便使用越界的索引值去访问或
存储元素，也不会被检测到。

为了能够有效地避免越界访问的情况，可以使用 array 容器提供的 at() 成员函数，例如 :
values.at (4) = values.at(3) + 2.O*values.at(1);
这行代码和前一行语句实现的功能相同，其次当传给 at() 的索引是一个越界值时，程序会抛出 std::out_of_range 异常。因此当需要访问容器中某个指
定元素时，建议大家使用 at()，除非确定索引没有越界。读者可能有这样一个疑问，即为什么 array 容器在重载 [] 运算符时，没有实现边界检查的功能呢？
答案很简单，因为性能。如果每次访问元素，都去检查索引值，无疑会产生很多开销。当不存在越界访问的可能时，就能避免这种开销。

除此之外，array 容器还提供了 get<n> 模板函数，它是一个辅助函数，能够获取到容器的第 n 个元素。需要注意的是，该模板函数中，参数的实参必须是
一个在编译时可以确定的常量表达式，所以它不能是一个循环变量。也就是说，它只能访问模板参数指定的元素，编译器在编译时会对它进行检查。

下面代码展示了如何使用 get<n> 模板函数：
#include <iostream>
#include <array>
#include <string>
using namespace std;
int main()
{
    array<string, 5> words{ "one","two","three","four","five" };
    cout << get<3>(words) << endl; // Output words[3]
    //cout << get<6>(words) << std::endl; //越界，会发生编译错误
    return 0;
}
运行结果为：
four

另外，array 容器提供了 data() 成员函数，通过调用该函数可以得到指向容器首个元素的指针。通过该指针，我们可以获得容器中的各个元素，例如：
#include <iostream>
#include <array>
using namespace std;
int main()
{
    array<int, 5> words{1,2,3,4,5};
    cout << *( words.data()+1);
    return 0;
}
运行结果为：
2

访问array容器中多个元素
我们知道，array 容器提供的 size() 函数能够返回容器中元素的个数（函数返回值为 size_t 类型），所以能够像下面这样去逐个提取容器中的元素，
并计算它们的和：

double total = 0;
for(size_t i = 0 ; i < values.size() ; ++i)
{
    total += values[i];
}
size() 函数的存在，为 array 容器提供了标准数组所没有的优势，即能够知道它包含多少元素。

并且，接受数组容器作为参数的函数，只需要通过调用容器的成员函数 size()，就能得到元素的个数。除此之外，通过调用 array 容器的 empty() 
成员函数，即可知道容器中有没有元素（如果容器中没有元素，此函数返回 true），如下所示：
if(values.empty())
    std::cout << "The container has no elements.\n";
else
    std::cout << "The container has "<< values.size()<<"elements.\n";
然而，很少会创建空的 array 容器，因为当生成一个 array 容器时，它的元素个数就固定了，而且无法改变，所以生成空 array 容器的唯一方法是
将模板的第二个参数指定为 0，但这种情况基本不可能发生。array 容器之所以提供 empty() 成员函数的原因，对于其他元素可变或者元素可删除的容器
（例如 vector、deque 等）来说，它们使用 empty() 时的机制是一样的，因此为它们提供了一个一致性的操作。

除了借助 size() 外，对于任何可以使用迭代器的容器，都可以使用基于范围的循环，因此能够更加简便地计算容器中所有元素的和，比如：
double total = 0;
for(auto&& value : values)
    total += value;

下面是一个示例，展示了本节关于如何获取 array 容器中元素所讲到的知识：
#include <iostream>
#include <iomanip> 
#include <array>
using namespace std;
int main()
{
    array<int, 5> values1;
    array<int, 5> values2;
    //初始化 values1 为 {0,1,2,3,4}
    for (size_t i = 0; i < values1.size(); ++i)
    {
        values1.at(i) = i;
    }
    cout << "values1[0] is : " << values1[0] << endl;
    cout << "values1[1] is : " << values1.at(1) << endl;
    cout << "values1[2] is : " << get<2>(values1) << endl;
    //初始化 values2 为{10，11，12，13，14}
    int initvalue = 10;
    for (auto& value : values2)
    {
        value = initvalue;
        initvalue++;
    }
    cout <<  "Values1 is : ";
    for (auto i = values1.begin(); i < values1.end(); i++) {
        cout << *i << " ";
    }
    cout << endl << "Values2 is : ";
    for (auto i = values2.begin(); i < values2.end(); i++) {
        cout << *i << " ";
    }
    return 0;
}
运行结果为：
values1[0] is : 0
values1[1] is : 1
values1[2] is : 2
Values1 is : 0 1 2 3 4
Values2 is : 10 11 12 13 14

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业故事+
学习历程+工作记录+生活日常+编程资料。


和 C++ 普通数组存储数据的方式一样，C++ 标准库保证使用 array 容器存储的所有元素一定会位于连续且相邻的内存中，通过如下代码也可以验证这一点：
#include <iostream>
#include <array>
using namespace std;
int main()
{
    array<int, 5>a{1,2,3};
    cout << &a[2] << " " << &a[0] + 2 << endl;
    return 0;
}
输出结果为：
004FFD58 004FFD58

可以看到，a 容器中 &a[2] 和 &a[0] + 2 是相等的。因此在实际编程过程中，我们完全有理由去尝试，在原本使用普通数组的位置，改由 array 容器去实现。
用 array 容器替换普通数组的好处是，array 模板类中已经封装好了大量实用的方法，在提高开发效率的同时，代码的运行效率也会大幅提高。

举个例子，我们完全可以使用 array 容器去存储 char* 或 const char* 类型的字符串：
#include <iostream>
#include <array>
using namespace std;
int main()
{
    array<char, 50>a{1,2,3};
    strcpy(&a[0], "http://c.biancheng.net/stl");
    printf("%s", &a[0]);
    return 0;
}
输出结果为：
http://c.biancheng.net/stl

注意，array 容器的大小必须保证能够容纳复制进来的数据，而且如果是存储字符串的话，还要保证在存储整个字符串的同时，在其最后放置一个\0作为字符串
的结束符。此程序中，strcpy() 在拷贝字符串的同时，会自动在最后添加\0。

其实，代码中的 &a[0] 还可以用 array 模板类提供的 data() 成员函数来替换：
#include <iostream>
#include <array>
using namespace std;
int main()
{
    array<char, 50>a{1,2,3};
    strcpy(a.data(), "http://c.biancheng.net/stl");
    printf("%s", a.data());
    return 0;
}
此程序和上面程序的输出结果完全相同。
注意，容器的迭代器和指针是不能混用的，即上面代码中不能用 a.begin() 来代替 &a[0] 或者 a.data[]，这可能会引发错误。

文章前面提到，使用 array 容器代替普通数组，最直接的好处就是 array 模板类中已经为我们写好了很多实用的方法，可以大大提高我们编码效率。例如，
array 容器提供的 at() 成员函数，可以有效防止越界操纵数组的情况；fill() 函数可以实现数组的快速初始化；swap() 函数可以轻松实现两个相同数组
（类型相同，大小相同）中元素的互换。

#include <iostream>
#include <array>
using namespace std;
int main()
{
    array<char, 50>addr1{"http://c.biancheng.net"};
    array<char, 50>addr2{ "http://c.biancheng.net/stl" };
    addr1.swap(addr2);
    printf("addr1 is：%s\n", addr1.data());
    printf("addr2 is：%s\n", addr2.data());
    return 0;
}
运行结果为：
addr1 is：http://c.biancheng.net/stl
addr2 is：http://c.biancheng.net


另外，当两个 array 容器满足大小相同并且保存元素的类型相同时，两个 array 容器可以直接直接做赋值操作，即将一个容器中的元素赋值给另一个容器。
比如：

#include <iostream>
#include <array>
using namespace std;
int main()
{
    array<char, 50>addr1{ "http://c.biancheng.net" };
    array<char, 50>addr2{ "http://c.biancheng.net/stl" };
    addr1 = addr2;
    printf("%s", addr1.data());
    return 0;
}
运行结果为：
http://c.biancheng.net/stl


不仅如此，在满足以上 2 个条件的基础上，如果其保存的元素也支持比较运算符，就可以用任何比较运算符直接比较两个 array 容器。示例如下：
#include <iostream>
#include <array>
using namespace std;
int main()
{
    array<char, 50>addr1{ "http://c.biancheng.net" };
    array<char, 50>addr2{ "http://c.biancheng.net/stl" };
    if (addr1 == addr2) {
        std::cout << "addr1 == addr2" << std::endl;
    }
    if (addr1 < addr2) {
        std::cout << "addr1 < addr2" << std::endl;
    }
    if (addr1 > addr2) {
        std::cout << "addr1 > addr2" << std::endl;
    }
    return 0;
}
运行结果为：
addr1 < addr2

两个容器比较大小的原理，和两个字符串比较大小是一样的，即从头开始，逐个取两容器中的元素进行大小比较（根据 ASCII 码表），直到遇到两个不相同的元素，
那个元素的值大，则该容器就大。

总之，读者可以这样认为，array 容器就是普通数组的“升级版”，使用普通数组能实现的，使用 array 容器都可以实现，而且无论是代码功能的实现效率，还是
程序执行效率，都比普通数组更高。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业故事+学习历程+
工作记录+生活日常+编程资料。

*/

using namespace std;
static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();

// solution
void printMyArray(string element) {
    cout << element << " ";
}

template<class T>
void test(T) {
    int a[std::tuple_size<T>::value]; // can be used at compile time
    std::cout << std::size_t(a) << '\n';
}
 
// main
int main() {
    // STL array container study
    array<string, 10> myArray = {"Welcome", "to", "Hsinan", "STL", "study", "class", "at", "year", "2022", "!"};
    array<string, 10> orgMyArray = myArray;

    // show given string first
    cout << "Input string in array is : ";
    for (auto item : myArray) {
        cout << item << " ";
    }
    cout << endl;

    // at(), get a specific element from array by giving index number
    // STL: Returns a reference to the element at specified location pos, with bounds checking.
    // If pos is not within the range of the container, an exception of type std::out_of_range is thrown.
    string word = myArray.at(2);
    cout << "The STL array at(2) is " << word << endl;

    // at(), with out of bound check while by next operator[] way didn't have such check
    try {
        // size is 10, the index 100 is out of range here
        word = myArray.at(100);
    } catch (out_of_range const &exec) {
        // catch out of range error and show what happened in detail
        cout << "The STL array at() out of range check with index 100"<< endl;
        cout << exec.what() << endl;
    }

    // operator[], direct access element by array index way without out of range like at()
    // STL: Returns a reference to the element at specified location pos. No bounds checking is performed.
    word = myArray[0];
    cout << "The myArray[0] by using index 0 directly is : " << word << endl;

    // front(), get 1st element in array
    // STL: Returns a reference to the first element in the container.
    // Calling front on an empty container is undefined.
    word = myArray.front();
    cout << "The myArray front() returns: " << word << endl;

    // back(), get last element in array
    // STL: Returns a reference to the last element in the container. 
    // Calling back on an empty container causes undefined behavior.
    word = myArray.back();
    cout << "The myArray back() returns: " << word << endl;

    // data(), get array pointer, which is actually first element returned like array[0]
    // STL: Returns pointer to the underlying array serving as element storage. The pointer is such that range 
    // [data(); data() + size()) is always a valid range, even if the container is empty (data() is not 
    // dereferenceable in that case).
    word = *myArray.data();
    cout << "The myArray data() returns: " << word << endl;

    // iterators, by using "auto" to skip complicated declaration
    cout << "array iterator for each element: " << endl;
    for (auto it = myArray.begin(); it != myArray.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    // iterators, by using complete declaration
    for (array<string, 10>::iterator it = myArray.begin(); it != myArray.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    // iterators, by using complete declaration
    for_each(myArray.begin(), myArray.end(), printMyArray);
    cout << endl;
    // reverse iterators, it will do something reverse
    cout << "array reverse iterator for each element: " << endl;
    for_each(myArray.rbegin(), myArray.rend(), printMyArray);
    cout << endl;

    // empty(), see if the array now is empty or not
    // STL: Checks if the container has no elements, i.e. whether begin() == end().
    bool isEmpty = myArray.empty();
    cout << boolalpha;
    cout << "Is the arrary empty? " << isEmpty << endl;

    // will it become empty if I put all NULL into array?
    for (auto it = myArray.begin(); it != myArray.end(); it++) {
        *it = "";
    }    
    cout << "Is the arrary empty after assigning NULL into array? " << isEmpty << endl;

    // size(), return current size of array
    // STL: Returns the number of elements in the container, i.e. std::distance(begin(), end()).
    int arraySize = myArray.size();
    cout << "The arrary size is " << arraySize << endl;

    // max_size(), return max size of this array
    // STL: Returns the maximum number of elements the container is able to hold due to system or 
    // library implementation limitations, i.e. std::distance(begin(), end()) for the largest container.
    int maxArraySize = myArray.max_size();
    cout << "The max arrary size is " << maxArraySize << endl;

    // fill(), instead of applying value one by one into all elements, this fill() will apply 
    // one value into all elements
    // STL: Assigns the given value value to all elements in the container.
    myArray.fill("TEST");
    for_each(myArray.begin(), myArray.end(), printMyArray);
    cout << endl;

    // swap(), swap the specific element with current one
    // STL: Exchanges the contents of the container with those of other. Does not cause iterators 
    // and references to associate with the other container.
    myArray[0] = "FIRST";
    myArray[9] = "LAST";
    cout << "Before swap " << myArray[0] << " " << myArray[9] << endl;
    myArray[0].swap(myArray[9]);
    cout << "After swap " << myArray[0] << " " << myArray[9] << endl;

    // std::get(), get specific element by index
    // STL: Extracts the Ith element element from the array. It must be an integer value in range [0, N). 
    // This is enforced at compile time as opposed to at() or operator[].
    myArray = orgMyArray;
    string theWord = std::get<0>(myArray);
    cout << "The specific word from std::get() is: " << theWord << endl;

    // std::swap(), swap whole array from one to another
    // STL: Specializes the std::swap algorithm for std::array. Swaps the contents of lhs and rhs. Calls lhs.swap(rhs).
    // This overload participates in overload resolution only if N == 0 or std::is_swappable_v<T> is true. (since C++17)
    myArray.fill("TEST");
    array<string, 10> tmp = myArray;
    tmp.fill("TMP");
    cout << "Before swap " << tmp[0] << " " << myArray[0] << endl;
    std::swap(tmp, myArray);
    cout << "After swap " << tmp[0] << " " << myArray[0] << endl;

    // std::to_array(), create one array from existing one. Note that this is supported from C++ 20 only
    // STL: Creates a std::array from the one dimensional built-in array a. The elements of the std::array are copy-initialized 
    // from the corresponding element of a. Copying or moving multidimensional built-in array is not supported.
    // auto myNewArray = std::to_array("New string supported from C++ 20 or above version only");

    // std::tuple_size(std::array), get array size during compile time, without specifying the size from code
    // Note that below code run at my computer didn't return expected "3", but "140729639439684". Interesting, need to see why
    // STL: Provides access to the number of elements in an std::array as a compile-time constant expression.
    std::array<float, 3> arr;
    test(arr);

    // std::tuple_element<std::array>, get element type
    // Below code example is from https://en.cppreference.com/w/cpp/container/array/tuple_element
    // define array and get the type of the element at position 0
    std::array<int, 10> data {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    using T = std::tuple_element<0, decltype(data)>::type; // int
 
    std::cout << std::boolalpha;
    std::cout << std::is_same<T, int>::value << '\n';
 
    const auto const_data = data;
    using CT = std::tuple_element<0, decltype(const_data)>::type; // const int
 
    // the result of tuple_element depends on the cv-qualification of the tuple-like type
    std::cout << std::is_same<T, CT>::value << '\n';
    std::cout << std::is_same<CT, const int>::value << '\n';

    // STL: deduction guides for std::array
    // One deduction guide is provided for std::array to provide an equivalent of std::experimental::make_array 
    // for construction of std::array from a variadic parameter pack.
    // Below code example is from https://en.cppreference.com/w/cpp/container/array/deduction_guides
    // int const x = 10;
    // std::array a{1, 2, 3, 5, x}; // OK, creates std::array<int, 5>
    // assert(a.back() == x);
    //  std::array b{1, 2u}; // Error, all arguments must have same type
    //  std::array<short> c{3, 2, 1}; // Error, wrong number of template args
    // std::array c(std::to_array<short>({3, 2, 1})); // C++20 alternative, creates std::array<short, 3>

    return 0;
}
