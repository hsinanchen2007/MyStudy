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

和 stack 栈容器适配器不同，queue 容器适配器有 2 个开口，其中一个开口专门用来输入数据，另一个专门用来输出数据，如图 1 所示。

queue容器适配器
图 1 queue容器适配器

这种存储结构最大的特点是，最先进入 queue 的元素，也可以最先从 queue 中出来，即用此容器适配器存储数据具有“先进先出（简称 "FIFO" ）
”的特点，因此 queue 又称为队列适配器。其实，STL queue 容器适配器模拟的就是队列这种存储结构，因此对于任何需要用队列进行处理的
序列来说，使用 queue 容器适配器都是好的选择。

queue容器适配器的创建
queue 容器适配器以模板类 queue<T,Container=deque<T>>（其中 T 为存储元素的类型，Container 表示底层容器的类型）的形式位于
<queue>头文件中，并定义在 std 命名空间里。因此，在创建该容器之前，程序中应包含以下 2 行代码：

#include <queue>
using namespace std;
创建 queue 容器适配器的方式大致可分为以下几种。

1) 创建一个空的 queue 容器适配器，其底层使用的基础容器选择默认的 deque 容器：
std::queue<int> values;
通过此行代码，就可以成功创建一个可存储 int 类型元素，底层采用 deque 容器的 queue 容器适配器。

2) 当然，也可以手动指定 queue 容器适配器底层采用的基础容器类型。通过学习 《STL容器适配器详解》一节我们知道，queue 容器适配器
底层容器可以选择 deque 和 list。作为 queue 容器适配器的基础容器，其必须提供 front()、back()、push_back()、pop_front()、empty() 
和 size() 这几个成员函数，符合条件的序列式容器仅有 deque 和 list。

例如，下面创建了一个使用 list 容器作为基础容器的空 queue 容器适配器：
std::queue<int, std::list<int>> values;
注意，在手动指定基础容器的类型时，其存储的数据类型必须和 queue 容器适配器存储的元素类型保持一致。

3) 可以用基础容器来初始化 queue 容器适配器，只要该容器类型和 queue 底层使用的基础容器类型相同即可。例如：
std::deque<int> values{1,2,3};
std::queue<int> my_queue(values);
由于 my_queue 底层采用的是 deque 容器，和 values 类型一致，且存储的也都是 int 类型元素，因此可以用 values 对 my_queue 进行初始化。

4) 还可以直接通过 queue 容器适配器来初始化另一个 queue 容器适配器，只要它们存储的元素类型以及底层采用的基础容器类型相同即可。例如：
std::deque<int> values{1,2,3};
std::queue<int> my_queue1(values);
std::queue<int> my_queue(my_queue1);
//或者使用
//std::queue<int> my_queue = my_queue1;
注意，和使用基础容器不同，使用 queue 适配器给另一个 queue 进行初始化时，有 2 种方式，使用哪一种都可以。

值得一提的是，第 3、4 种初始化方法中 my_queue 容器适配器的数据是经过拷贝得来的，也就是说，操作 my_queue 容器适配器中的数据，并不会对 
values 容器以及 my_queue1 容器适配器有任何影响；反过来也是如此。

queue容器适配器支持的成员函数
queue 容器适配器和 stack 有一些成员函数相似，但在一些情况下，工作方式有些不同。表 2 罗列了 queue 容器支持的全部成员函数。

表 2 queue容器适配器支持的成员函数
成员函数	功能
empty()	如果 queue 中没有元素的话，返回 true。
size()	返回 queue 中元素的个数。
front()	返回 queue 中第一个元素的引用。如果 queue 是常量，就返回一个常引用；如果 queue 为空，返回值是未定义的。
back()	返回 queue 中最后一个元素的引用。如果 queue 是常量，就返回一个常引用；如果 queue 为空，返回值是未定义的。
push(const T& obj)	在 queue 的尾部添加一个元素的副本。这是通过调用底层容器的成员函数 push_back() 来完成的。
emplace()	在 queue 的尾部直接添加一个元素。
push(T&& obj)	以移动的方式在 queue 的尾部添加元素。这是通过调用底层容器的具有右值引用参数的成员函数 push_back() 来完成的。
pop()	删除 queue 中的第一个元素。
swap(queue<T> &other_queue)	将两个 queue 容器适配器中的元素进行互换，需要注意的是，进行互换的 2 个 queue 容器适配器中存储的元素类型
以及底层采用的基础容器类型，都必须相同。和 stack 一样，queue 也没有迭代器，因此访问元素的唯一方式是遍历容器，通过不断移除访问过的元素，
去访问下一个元素。

下面这个例子中演示了表 2 中部分成员函数的用法：
#include <iostream>
#include <queue>
#include <list>
using namespace std;
int main()
{
    //构建 queue 容器适配器
    std::deque<int> values{ 1,2,3 };
    std::queue<int> my_queue(values);//{1,2,3}
    //查看 my_queue 存储元素的个数
    cout << "size of my_queue: " << my_queue.size() << endl;
    //访问 my_queue 中的元素
    while (!my_queue.empty())
    {
        cout << my_queue.front() << endl;
        //访问过的元素出队列
        my_queue.pop();
    }
    return 0;
}
运行结果为：
size of my_queue: 3
1
2
3

表 2 中其它成员函数的用法也非常简单，这里不再给出具体示例，后续章节用法会做具体介绍。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业故事+学习历程+
工作记录+生活日常+编程资料。


前面章节介绍了 queue 容器适配器的具有用法，本节将利用 queue 模拟超市中结账环节运转的程序。

在超市营业过程中，结账队列的长度是超市运转的关键因素。它会影响超市可容纳的顾客数，因为太长的队伍会使顾客感到气馁，从而放弃排队，这和医院
可用病床数会严重影响应急处理设施的运转，是同样的道理。

首先，我们要在头文件 Customer.h 中定义一个类来模拟顾客：
#ifndef CUSTOMER_H
#define CUSTOMER_H
class Customer
{
protected:
    size_t service_t {}; //顾客结账需要的时间
public:
    explicit Customer(size_t st = 10) :service_t {st}{}
    //模拟随着时间的变化，顾客结账所需时间也会减短
    Customer& time_decrement()
    {
        if (service_t > 0)
            --service_t;
        return *this;
    }
    bool done() const { return service_t == 0; }
};
#endif
这里只有一个成员变量 service_t，用来记录顾客结账需要的时间。每个顾客的结账时间都不同。每过一分钟，会调用一次 time_decrement() 函数，
这个函数会减少 service_t 的值，它可以反映顾客结账所花费的时间。当 service_t 的值为 0 时，成员函数 done() 返回 true。

超市的每个结账柜台都有一队排队等待的顾客。Checkout.h 中定义的 Checkout 类如下：
#ifndef CHECKOUT_H
#define CHECKOUT_H
#include <queue> // For queue container
#include "Customer.h"
class Checkout
{
private:
    std::queue<Customer> customers; //该队列等到结账的顾客数量
public:
    void add(const Customer& customer) { customers.push(customer); }
    size_t qlength() const { return customers.size(); }
   
    void time_increment()
    {
        if (!customers.empty())
        { 
            //有顾客正在等待结账，如果顾客结账了，就出队列
            if (customers.front().time_decrement().done())
                customers.pop(); 
        }
    }
    bool operator<(const Checkout& other) const { return qlength() < other.qlength(); }
    bool operator>(const Checkout& other) const { return qlength() > other.qlength(); }
};
#endif
可以看到，queue 容器是 Checkout 唯一的成员变量，用来保存等待结账的 Customer 对象。成员函数 add() 可以向队列中添加新顾客。只能处理队列
中的第一个元素。 每过一分钟，调用一次 Checkout 对象的成员函数 time_increment(}，它会调用第一个 Customer 对象的成员函数 time_decrement() 
来减少剩余的等待时间，然后再调用成员函数 done()。如果 done() 返回 true，表明顾客结账完成，因此把他从队列中移除。Checkout 对象的比较运
算符可以比较队列的长度。

为了模拟超市结账，我们需要有随机数生成的功能。因此打算使用 <random> 头文件中的一个非常简单的工具，但不打算深入解释它。我们会在教程后面的
章节深入探讨 random 头文件中的内容。程序使用了一个 uniform_int_distribution() 类型的实例。顾名思义，它定义的整数值在最大值和最小值之间
均匀分布。在均匀分布中，所有这个范围内的值都可能相等。可以在 10 和 100 之间定义如下分布：

std::uniform_int_distribution<> d {10, 100};
这里只定义了分布对象 d，它指定了整数值分布的范围。为了获取这个范围内的随机数，我们需要使用一个随机数生成器，然后把它作为参数传给 d 的调用
运算符，从而返回一个随机整数。 random 头文件中定义了几种随机数生成器。这里我们使用最简单的一个，可以按如下方式定义：
std::random_device random_number_engine;

为了在 d 分布范围内生成随机数，我们可以这样写：
auto value = d(random_number_engine);
value 的值在 d 分布范围内。

完整模拟器的源文件如下：
#include <iostream> // For standard streams
#include <iomanip>  // For stream manipulators
#include <vector>   // For vector container
#include <string>   // For string class
#include <numeric>  // For accumulate()
#include <algorithm> // For min_element & max_element
#include <random> // For random number generation
#include "Customer.h"
#include "Checkout.h"
using std::string;
using distribution = std::uniform_int_distribution<>;
// 以横向柱形图的方式输出每个服务时间出现的次数
void histogram(const std::vector<int>& v, int min)
{
    string bar (60, '*');                       
    for (size_t i {}; i < v.size(); ++i)
    {
        std::cout << std::setw(3) << i+min << " "    //结账等待时间为 index + min
        << std::setw(4) << v[i] << " "             //输出出现的次数
        << bar.substr(0, v[i])                     
        << (v[i] > static_cast<int>(bar.size()) ? "...": "")
        << std::endl;
    }
}
int main()
{
    std::random_device random_n;
    //设置最大和最小的结账时间，以分钟为单位
    int service_t_min {2}, service_t_max {15};
    distribution service_t_d {service_t_min, service_t_max};
    //设置在超市开业时顾客的人数
    int min_customers {15}, max_customers {20};
    distribution n_1st_customers_d {min_customers, max_customers};
    // 设置顾客到达的最大和最小的时间间隔
    int min_arr_interval {1}, max_arr_interval {5};
    distribution arrival_interval_d {min_arr_interval, max_arr_interval};
    size_t n_checkouts {};
    std::cout << "输入超市中结账柜台的数量：";
    std::cin >> n_checkouts;
    if (!n_checkouts)
    {
        std::cout << "结账柜台的数量必须大于 0，这里将默认设置为 1" << std::endl;
        n_checkouts = 1;
    }
    std::vector<Checkout> checkouts {n_checkouts};
    std::vector<int> service_times(service_t_max-service_t_min+1);
    //等待超市营业的顾客人数
    int count {n_1st_customers_d(random_n)};
    std::cout << "等待超市营业的顾客人数：" << count << std::endl;
    int added {};
    int service_t {};
    while (added++ < count)
    {
        service_t = service_t_d(random_n);
        std::min_element(std::begin(checkouts), std::end(checkouts))->add(Customer(service_t));
        ++service_times[service_t - service_t_min];
    }
    size_t time {};
    const size_t total_time {600};                 // 设置超市持续营业的时间
    size_t longest_q {};                           // 等待结账最长队列的长度
    // 新顾客到达的时间
    int new_cust_interval {arrival_interval_d(random_n)};
    //模拟超市运转的过程
    while (time < total_time)                      
    {
        ++time; //时间增长
        // 新顾客到达
        if (--new_cust_interval == 0)
        {
            service_t = service_t_d(random_n);         // 设置顾客结账所需要的时间
            std::min_element(std::begin(checkouts), std::end(checkouts))->add(Customer(service_t));
            ++service_times[service_t - service_t_min];  // 记录结账需要等待的时间
            //记录最长队列的长度
            for (auto & checkout : checkouts)
                longest_q = std::max(longest_q, checkout.qlength());
            new_cust_interval = arrival_interval_d(random_n);
        }
        // 更新每个队列中第一个顾客的结账时间
        for (auto & checkout : checkouts)
            checkout.time_increment();
    }
    std::cout << "最大的队列长度为：" << longest_q << std::endl;
    std::cout << "\n各个结账时间出现的次数：:\n";
    histogram(service_times, service_t_min);
    std::cout << "\n总的顾客数："
            << std::accumulate(std::begin(service_times), std::end(service_times), 0)
            << std::endl;
    return 0;
}
直接使用 using 指令可以减少代码输入，简化代码。顾客结账信息记录在 vector 中。结账时间减去 service_times 的最小值可以用来索引需要
自增的 vector 元素，这导致 vector 的第一个元素会记录下最少结账时间出现的次数。histogram() 函数会以水平条形图的形式生成每个服务时间
出现次数的柱状图。

程序中 checkouts 的值为 600，意味着将模拟开业时间设置为 600 分钟，也可以用参数输入这个时间。main() 函数生成了顾客结账时间，超市开
门时等在门外的顾客数，以及顾客到达时间间隔的分布对象。我们可以轻松地将这个程序扩展为每次到达的顾客数是一个处于一定范围内的随机数。

通过调用 min_element() 算法可以找到最短的 Checkout 对象队列，因此顾客总是可以被分配到最短的结账队列。在这次模拟开始前，当超市开门
营业时，在门外等待的顾客的初始序列被添加到 Checkout 对象中，然后结账时间记录被更新。

模拟在 while 循环中进行，在每次循环中，time 都会增加 1 分钟。在下一个顾客到达期间，new_cust_interval 会在每次循环中减小，直到等于 
0。用新的随机结账时间生成新的顾客，然后把它加到最短的 Checkout 对象队列中。这个时候也会更新变量 longest_q，因为在添加新顾客后，
可能出现新的最长队列。然后调用每个 Checkout 对象的 time_increment() 函数来处理队列中的第一个顾客。

下面是一些示例输出：
输入超级中结账柜台的数量：2
等待超市营业的顾客人数：20
最大的队列长度为：43

各个结账时间出现的次数：
  2   13 *************
  3   20 ********************
  4   11 ***********
  5   16 ****************
  6   12 ************
  7   18 ******************
  8   17 *****************
  9   18 ******************
10   10 **********
11   22 **********************
12   19 *******************
13   13 *************
14   16 ****************
15   18 ******************

总的顾客数：223

这里有 2 个结账柜台，最长队列的长度达到 43，已经长到会让顾客放弃付款。

以上代码还可以做更多改进，让模拟更加真实，例如，均匀分配并不符合实际，顾客通常成群结队到来。可以增加一些其他的因素，比如收银员休息时间、
某个收银员生病工作状态不佳，这些都会导致顾客不选择这个柜台结账。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业故事+学习历程+
工作记录+生活日常+编程资料。


priority_queue 容器适配器模拟的也是队列这种存储结构，即使用此容器适配器存储元素只能“从一端进（称为队尾），从另一端出（称为队头）”，
且每次只能访问 priority_queue 中位于队头的元素。

但是，priority_queue 容器适配器中元素的存和取，遵循的并不是 “First in,First out”（先入先出）原则，而是“First in，Largest out”原则。
直白的翻译，指的就是先进队列的元素并不一定先出队列，而是优先级最大的元素最先出队列。

注意，“First in，Largest out”原则是笔者为了总结 priority_queue 存取元素的特性自创的一种称谓，仅为了方便读者理解。

那么，priority_queue 容器适配器中存储的元素，优先级是如何评定的呢？很简单，每个 priority_queue 容器适配器在创建时，都制定了一种排序
规则。根据此规则，该容器适配器中存储的元素就有了优先级高低之分。

举个例子，假设当前有一个 priority_queue 容器适配器，其制定的排序规则是按照元素值从大到小进行排序。根据此规则，自然是 priority_queue 
中值最大的元素的优先级最高。

priority_queue 容器适配器为了保证每次从队头移除的都是当前优先级最高的元素，每当有新元素进入，它都会根据既定的排序规则找到优先级最高的
元素，并将其移动到队列的队头；同样，当 priority_queue 从队头移除出一个元素之后，它也会再找到当前优先级最高的元素，并将其移动到队头。

基于 priority_queue 的这种特性，因此该容器适配器有被称为优先级队列。
priority_queue 容器适配器“First in，Largest out”的特性，和它底层采用堆结构存储数据是分不开的。有关该容器适配器的底层实现，后续章节
会进行深度剖析。

STL 中，priority_queue 容器适配器的定义如下：
template <typename T,
        typename Container=std::vector<T>,
        typename Compare=std::less<T> >
class priority_queue{
    //......
}
可以看到，priority_queue 容器适配器模板类最多可以传入 3 个参数，它们各自的含义如下：
typename T：指定存储元素的具体类型；
typename Container：指定 priority_queue 底层使用的基础容器，默认使用 vector 容器。
作为 priority_queue 容器适配器的底层容器，其必须包含 empty()、size()、front()、push_back()、pop_back() 这几个成员函数，STL 
序列式容器中只有 vector 和 deque 容器符合条件。

typename Compare：指定容器中评定元素优先级所遵循的排序规则，默认使用std::less<T>按照元素值从大到小进行排序，还可以使用std::greater<T>
按照元素值从小到大排序，但更多情况下是使用自定义的排序规则。
其中，std::less<T> 和 std::greater<T> 都是以函数对象的方式定义在 <function> 头文件中。关于如何自定义排序规则，后续章节会做详细介绍。

创建priority_queue的几种方式
由于 priority_queue 容器适配器模板位于<queue>头文件中，并定义在 std 命名空间里，因此在试图创建该类型容器之前，程序中需包含以下 2 行代码：
#include <queue>
using namespace std;

创建 priority_queue 容器适配器的方法，大致有以下几种。
1) 创建一个空的 priority_queue 容器适配器，第底层采用默认的 vector 容器，排序方式也采用默认的 std::less<T> 方法：
std::priority_queue<int> values;

2) 可以使用普通数组或其它容器中指定范围内的数据，对 priority_queue 容器适配器进行初始化：
//使用普通数组
int values[]{4,1,3,2};
std::priority_queue<int>copy_values(values,values+4);//{4,2,3,1}
//使用序列式容器
std::array<int,4>values{ 4,1,3,2 };
std::priority_queue<int>copy_values(values.begin(),values.end());//{4,2,3,1}
注意，以上 2 种方式必须保证数组或容器中存储的元素类型和 priority_queue 指定的存储类型相同。另外，用来初始化的数组或容器中的数据不需要有序，
priority_queue 会自动对它们进行排序。

3) 还可以手动指定 priority_queue 使用的底层容器以及排序规则，比如：
int values[]{ 4,1,2,3 };
std::priority_queue<int, std::deque<int>, std::greater<int> >copy_values(values, values+4);//{1,3,2,4}
事实上，std::less<T> 和 std::greater<T> 适用的场景是有限的，更多场景中我们会使用自定义的排序规则。
由于自定义排序规则的方式不只一种，因此这部分知识将在后续章节做详细介绍。

priority_queue提供的成员函数
priority_queue 容器适配器提供了表 2 所示的这些成员函数。

表 2 priority_queue 提供的成员函数
成员函数	功能
empty()	如果 priority_queue 为空的话，返回 true；反之，返回 false。
size()	返回 priority_queue 中存储元素的个数。
top()	返回 priority_queue 中第一个元素的引用形式。
push(const T& obj)	根据既定的排序规则，将元素 obj 的副本存储到 priority_queue 中适当的位置。
push(T&& obj)	根据既定的排序规则，将元素 obj 移动存储到 priority_queue 中适当的位置。
emplace(Args&&... args)	Args&&... args 表示构造一个存储类型的元素所需要的数据（对于类对象来说，可能需要多个数据构造出一个对象）。
此函数的功能是根据既定的排序规则，在容器适配器适当的位置直接生成该新元素。
pop()	移除 priority_queue 容器适配器中第一个元素。
swap(priority_queue<T>& other)	将两个 priority_queue 容器适配器中的元素进行互换，需要注意的是，进行互换的 2 个 priority_queue 
容器适配器中存储的元素类型以及底层采用的基础容器类型，都必须相同。
和 queue 一样，priority_queue 也没有迭代器，因此访问元素的唯一方式是遍历容器，通过不断移除访问过的元素，去访问下一个元素。

下面的程序演示了表 2 中部分成员函数的具体用法：
#include <iostream>
#include <queue>
#include <array>
#include <functional>
using namespace std;
int main()
{
    //创建一个空的priority_queue容器适配器
    std::priority_queue<int>values;
    //使用 push() 成员函数向适配器中添加元素
    values.push(3);//{3}
    values.push(1);//{3,1}
    values.push(4);//{4,1,3}
    values.push(2);//{4,2,3,1}
    //遍历整个容器适配器
    while (!values.empty())
    {
        //输出第一个元素并移除。
        std::cout << values.top()<<" ";
        values.pop();//移除队头元素的同时，将剩余元素中优先级最大的移至队头
    }
    return 0;
}
运行结果为：
4 3 2 1

表 2 中其它成员函数的用法也非常简单，这里不再给出具体示例，后续章节用法会做具体介绍。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业故事+
学习历程+工作记录+生活日常+编程资料

*/

using namespace std;
static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();

// solution


// main
int main() {
    // STL adaptor queue study
    queue<double> myQueue;

    myQueue.push(1.2);
    myQueue.push(2.3);
    myQueue.push(3.4);
    myQueue.push(4.5);
    myQueue.push(5.6);

    // front()/back(), queue is different from stack that it allows to access either front or back element directly
    // Queue is FIFO
    // STL: Returns reference to the first element in the queue. This element will be the first element to be removed 
    // on a call to pop(). Effectively calls c.front().
    // STL: Returns reference to the last element in the queue. This is the most recently pushed element. Effectively calls c.back().
    cout << "current myQueue front is " << myQueue.front() << endl;
    cout << "current myQueue back is " << myQueue.back() << endl;

    // empty()/size(), return queue status and its size
    // STL: Checks if the underlying container has no elements, i.e. whether c.empty().
    // STL: Returns the number of elements in the underlying container, that is, c.size().
    cout << boolalpha << "Is current queue empty? " << myQueue.empty() << " and its size is " << myQueue.size() << endl;

    // similar to stack, if we want to iterate all elements from front side in order, use while loop
    while (!myQueue.empty()) {
        cout << myQueue.front() << endl;
        myQueue.pop();
    }

    // push()/pop()/emplace()/swap()/std::swap(), there are all similar to stack, however, queue can only push new element at the end, and 
    // pop first element from the front. This is different from deque container, where it is actually implemented by vector internally
    // so it allows to push/pop elements from/to front/back
    // STL: Pushes the given element value to the end of the queue.
    // 1) Effectively calls c.push_back(value)
    // 2) Effectively calls c.push_back(std::move(value))
    // STL: Removes an element from the front of the queue. Effectively calls c.pop_front()
    // STL: Pushes a new element to the end of the queue. The element is constructed in-place, i.e. no copy or move operations are performed. 
    // The constructor of the element is called with exactly the same arguments as supplied to the function.
    // Effectively calls c.emplace_back(std::forward<Args>(args)...);
    // STL: Exchanges the contents of the container adaptor with those of other. Effectively calls using std::swap; swap(c, other.c);
    myQueue.emplace(1.2);
    myQueue.push(2.3);
    myQueue.emplace(3.4);
    myQueue.push(4.5);
    myQueue.emplace(5.6);

    queue<double> myQueue2;
    myQueue2.swap(myQueue);
    cout << "Size of myQueue is " << myQueue.size() << endl;
    cout << "Size of myQueue2 is " << myQueue2.size() << endl;

    std::swap(myQueue, myQueue2);
    cout << "Size of myQueue is " << myQueue.size() << endl;
    cout << "Size of myQueue2 is " << myQueue2.size() << endl;

    return 0;
}
