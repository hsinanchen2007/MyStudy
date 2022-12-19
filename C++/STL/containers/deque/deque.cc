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

deque 是 double-ended queue 的缩写，又称双端队列容器。

前面章节中，我们已经系统学习了 vector 容器，值得一提的是，deque 容器和 vecotr 容器有很多相似之处，比如：
deque 容器也擅长在序列尾部添加或删除元素（时间复杂度为O(1)），而不擅长在序列中间添加或删除元素。
deque 容器也可以根据需要修改自身的容量和大小。

和 vector 不同的是，deque 还擅长在序列头部添加或删除元素，所耗费的时间复杂度也为常数阶O(1)。并且更重要的一点是，deque 容器中存储元素
并不能保证所有元素都存储到连续的内存空间中。当需要向序列两端频繁的添加或删除元素时，应首选 deque 容器。

deque 容器以模板类 deque<T>（T 为存储元素的类型）的形式在 <deque> 头文件中，并位于 std 命名空间中。因此，在使用该容器之前，代码中需要
包含下面两行代码：

#include <deque>
using namespace std;
注意，std 命名空间也可以在使用 deque 容器时额外注明，两种方式都可以。

创建deque容器的几种方式
创建 deque 容器，根据不同的实际场景，可选择使用如下几种方式。

1) 创建一个没有任何元素的空 deque 容器：
std::deque<int> d;
和空 array 容器不同，空的 deque 容器在创建之后可以做添加或删除元素的操作，因此这种简单创建 deque 容器的方式比较常见。

2) 创建一个具有 n 个元素的 deque 容器，其中每个元素都采用对应类型的默认值：
std::deque<int> d(10);
此行代码创建一个具有 10 个元素（默认都为 0）的 deque 容器。

3) 创建一个具有 n 个元素的 deque 容器，并为每个元素都指定初始值，例如：
std::deque<int> d(10, 5)
如此就创建了一个包含 10 个元素（值都为 5）的 deque 容器。

4) 在已有 deque 容器的情况下，可以通过拷贝该容器创建一个新的 deque 容器，例如：
std::deque<int> d1(5);
std::deque<int> d2(d1);
注意，采用此方式，必须保证新旧容器存储的元素类型一致。

5) 通过拷贝其他类型容器中指定区域内的元素（也可以是普通数组），可以创建一个新容器，例如：
//拷贝普通数组，创建deque容器
int a[] = { 1,2,3,4,5 };
std::deque<int>d(a, a + 5);
//适用于所有类型的容器
std::array<int, 5>arr{ 11,12,13,14,15 };
std::deque<int>d(arr.begin()+2, arr.end());//拷贝arr容器中的{13,14,15}
deque容器可利用的成员函数
基于 deque 双端队列的特点，该容器包含一些 array、vector 容器都没有的成员函数。

表 1 中罗列了 deque 容器提供的所有成员函数。

表 1 deque 容器的成员函数
函数成员	函数功能
begin()	返回指向容器中第一个元素的迭代器。
end()	返回指向容器最后一个元素所在位置后一个位置的迭代器，通常和 begin() 结合使用。
rbegin()	返回指向最后一个元素的迭代器。
rend()	返回指向第一个元素所在位置前一个位置的迭代器。
cbegin()	和 begin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
cend()	和 end() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
crbegin()	和 rbegin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
crend()	和 rend() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
size()	返回实际元素个数。
max_size()	返回容器所能容纳元素个数的最大值。这通常是一个很大的值，一般是 232-1，我们很少会用到这个函数。
resize()	改变实际元素的个数。
empty()	判断容器中是否有元素，若无元素，则返回 true；反之，返回 false。
shrink _to_fit()	将内存减少到等于当前元素实际所使用的大小。
at()	使用经过边界检查的索引访问元素。
front()	返回第一个元素的引用。
back()	返回最后一个元素的引用。
assign()	用新元素替换原有内容。
push_back()	在序列的尾部添加一个元素。
push_front()	在序列的头部添加一个元素。
pop_back()	移除容器尾部的元素。
pop_front()	移除容器头部的元素。
insert()	在指定的位置插入一个或多个元素。
erase()	移除一个元素或一段元素。
clear()	移出所有的元素，容器大小变为 0。
swap()	交换两个容器的所有元素。
emplace()	在指定的位置直接生成一个元素。
emplace_front()	在容器头部生成一个元素。和 push_front() 的区别是，该函数直接在容器头部构造元素，省去了复制移动元素的过程。
emplace_back()	在容器尾部生成一个元素。和 push_back() 的区别是，该函数直接在容器尾部构造元素，省去了复制移动元素的过程。
和 vector 相比，额外增加了实现在容器头部添加和删除元素的成员函数，同时删除了 capacity()、reserve() 和 data() 成员函数。

和 array、vector 相同，C++ 11 标准库新增的 begin() 和 end() 这 2 个全局函数也适用于 deque 容器。这 2 个函数的操作对象既可以是容器，
也可以是普通数组。当操作对象是容器时，它和容器包含的 begin() 和 end() 成员函数的功能完全相同；如果操作对象是普通数组，则 begin() 函数
返回的是指向数组第一个元素的指针，同样 end() 返回指向数组中最后一个元素之后一个位置的指针（注意不是最后一个元素）。

deque 容器还有一个std::swap(x , y) 非成员函数（其中 x 和 y 是存储相同类型元素的 deque 容器），它和 swap() 成员函数的功能完全相同，
仅使用语法上有差异。

如下代码演示了表 1 中部分成员函数的用法：

#include <iostream>
#include <deque>
using namespace std;
int main()
{
    //初始化一个空deque容量
    deque<int>d;
    //向d容器中的尾部依次添加 1，2,3
    d.push_back(1); //{1}
    d.push_back(2); //{1,2}
    d.push_back(3); //{1,2,3}
    //向d容器的头部添加 0 
    d.push_front(0); //{0,1,2,3}
    //调用 size() 成员函数输出该容器存储的字符个数。
    printf("元素个数为：%d\n", d.size());
   
    //使用迭代器遍历容器
    for (auto i = d.begin(); i < d.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
    return 0;
}
运行结果为：
元素个数为：4
0 1 2 3

表 1 中这些成员函数的具体用法，后续学习用到时会具体讲解，感兴趣的读者，也可以通过查阅 STL手册做详细了解。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业故事+学习历程+
工作记录+生活日常+编程资料。


deque 容器迭代器的类型为随机访问迭代器，deque 模板类提供了表 1 所示这些成员函数，通过调用这些函数，可以获得表示不同含义的随机访问迭代器。
有关迭代器及其类型的介绍，可以阅读《C++ STL迭代器（iterator）》一节，本节不再做具体介绍。

表 1 deque 支持迭代器的成员函数
成员函数	功能
begin()	返回指向容器中第一个元素的正向迭代器；如果是 const 类型容器，在该函数返回的是常量正向迭代器。
end()	返回指向容器最后一个元素之后一个位置的正向迭代器；如果是 const 类型容器，在该函数返回的是常量正向迭代器。此函数通常和 begin() 
搭配使用。
rbegin()	返回指向最后一个元素的反向迭代器；如果是 const 类型容器，在该函数返回的是常量反向迭代器。
rend()	返回指向第一个元素之前一个位置的反向迭代器。如果是 const 类型容器，在该函数返回的是常量反向迭代器。此函数通常和 rbegin() 搭配使用。
cbegin()	和 begin() 功能类似，只不过其返回的迭代器类型为常量正向迭代器，不能用于修改元素。
cend()	和 end() 功能相同，只不过其返回的迭代器类型为常量正向迭代器，不能用于修改元素。
crbegin()	和 rbegin() 功能相同，只不过其返回的迭代器类型为常量反向迭代器，不能用于修改元素。
crend()	和 rend() 功能相同，只不过其返回的迭代器类型为常量反向迭代器，不能用于修改元素。
C++ 11 新添加的 begin() 和 end() 全局函数也同样适用于 deque 容器。即当操作对象为 deque 容器时，其功能分别和表 1 中的 begin()、end() 
成员函数相同，具体用法本节后续会做详细介绍。


表 1 中这些成员函数的具体功能如图 2 所示。


图 2 迭代器的具体功能示意图

从图 2 可以看出，这些成员函数通常是成对使用的，即 begin()/end()、rbegin()/rend()、cbegin()/cend()、crbegin()/crend() 各自成对搭配使用。
其中，begin()/end() 和 cbegin/cend() 的功能是类似的，同样 rbegin()/rend() 和 crbegin()/crend() 的功能是类似的。

值得一提的是，以上函数在实际使用时，其返回值类型都可以使用 auto 关键字代替，编译器可以自行判断出该迭代器的类型。

deque容器迭代器的基本用法
deque 容器迭代器常用来遍历容器中存储的各个元素。

begin() 和 end() 分别用于指向「首元素」和「尾元素+1」 的位置，下面程序演示了如何使用 begin() 和 end() 遍历 deque 容器并输出其中的元素：
#include <iostream>
#include <deque>
using namespace std;
int main()
{
    deque<int>d{1,2,3,4,5};
    //从容器首元素，遍历至最后一个元素
    for (auto i = d.begin(); i < d.end(); i++) {
        cout << *i << " ";
    }
    return 0;
}
运行结果为：
1 2 3 4 5


前面提到，STL 还提供有全局的 begin() 和 end() 函数，当操作对象为容器时，它们的功能是上面的 begin()/end() 成员函数一样。例如，将上面程序
中的第 8~10 行代码可以用如下代码替换：

for (auto i = begin(d); i < end(d); i++) {
    cout << *i << " ";
}
重新编译运行程序，会发现输出结果和上面一致。

cbegin()/cend() 成员函数和 begin()/end() 唯一不同的是，前者返回的是 const 类型的正向迭代器，这就意味着，由 cbegin() 和 cend() 成员函数
返回的迭代器，可以用来遍历容器内的元素，也可以访问元素，但是不能对所存储的元素进行修改。

举个例子：
#include <iostream>
#include <deque>
using namespace std;
int main()
{
    deque<int>d{1,2,3,4,5};
    auto first = d.cbegin();
    auto end = d.cend();
    //常量迭代器不能用来修改容器中的元素值
    //*(first + 1) = 6;//尝试修改容器中元素 2 的值
    //*(end - 1) = 10;//尝试修改容器中元素 5 的值
    //常量迭代器可以用来遍历容器、访问容器中的元素
    while(first<end){
        cout << *first << " ";
        ++first;
    }
    return 0;
}
运行结果：
1 2 3 4 5

程序中，由于 first 和 end 都是常量迭代器，因此第 10、11 行修改容器内元素值的操作都是非法的。

deque 模板类中还提供了 rbegin() 和 rend() 成员函数，它们分别表示指向最后一个元素和第一个元素前一个位置的随机访问迭代器，又常称为反向迭代器
（如图 2 所示）。需要注意的是，在使用反向迭代器进行 ++ 或 -- 运算时，++ 指的是迭代器向左移动一位，-- 指的是迭代器向右移动一位，即这两个运算符
的功能也“互换”了。

反向迭代器用于以逆序的方式遍历容器中的元素。例如：
#include <iostream>
#include <deque>
using namespace std;
int main()
{
    deque<int>d{1,2,3,4,5};
    for (auto i = d.rbegin(); i < d.rend(); i++) {
        cout << *i << " ";
    }
    return 0;
}
运行结果为：
5 4 3 2 1


crbegin()/crend() 组合和 rbegin()/crend() 组合唯一的区别在于，前者返回的迭代器为 const 类型迭代器，不能用来修改容器中的元素，除此之外在
使用上和后者完全相同。deque容器迭代器的使用注意事项首先需要注意的一点是，迭代器的功能是遍历容器，在遍历的同时可以访问（甚至修改）容器中的元素，
但迭代器不能用来初始化空的 deque 容器。

例如，如下代码中注释部分是错误的用法：
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int>values;
    auto first = values.begin();
    //*first = 1;
    return 0;
}
对于空的 deque 容器来说，可以通过 push_back()、push_front() 或者 resize() 成员函数实现向（空）deque 容器中添加元素。


除此之外，当向 deque 容器添加元素时，deque 容器会申请更多的内存空间，同时其包含的所有元素可能会被复制或移动到新的内存地址（原来占用的内存会释放），
这会导致之前创建的迭代器失效。

举个例子：
#include <iostream>
#include <deque>
using namespace std;
int main()
{
    deque<int>d;
    d.push_back(1);
    auto first = d.begin();
    cout << *first << endl;
    //添加元素，会导致 first 失效
    d.push_back(1);
    cout << *first << endl;
    return 0;
}
程序中第 12 行代码，会导致程序运行崩溃，其原因就在于在创建 first 迭代器之后，deque 容器做了添加元素的操作，导致 first 失效。
在对容器做添加元素的操作之后，如果仍需要使用之前以创建好的迭代器，为了保险起见，一定要重新生成。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业故事+学习历程+工作记录+
生活日常+编程资料。


事实上，STL 中每个容器的特性，和它底层的实现机制密切相关，deque 自然也不例外。《C++ STL deque容器》一节中提到，deque 容器擅长在序列的头部和
尾部添加或删除元素。本节将介绍 deque 容器的底层实现机制，探究其拥有此特点的原因。

想搞清楚 deque 容器的实现机制，需要先了解 deque 容器的存储结构以及 deque 容器迭代器的实现原理。
deque容器的存储结构
和 vector 容器采用连续的线性空间不同，deque 容器存储数据的空间是由一段一段等长的连续空间构成，各段空间之间并不一定是连续的，可以位于在内存的
不同区域。

为了管理这些连续空间，deque 容器用数组（数组名假设为 map）存储着各个连续空间的首地址。也就是说，map 数组中存储的都是指针，指向那些真正用来
存储数据的各个连续空间（如图 1 所示）。

deque容器的底层存储机制
图 1 deque容器的底层存储机制

通过建立 map 数组，deque 容器申请的这些分段的连续空间就能实现“整体连续”的效果。换句话说，当 deque 容器需要在头部或尾部增加存储空间时，
它会申请一段新的连续空间，同时在 map 数组的开头或结尾添加指向该空间的指针，由此该空间就串接到了 deque 容器的头部或尾部。

有读者可能会问，如果 map 数组满了怎么办？很简单，再申请一块更大的连续空间供 map 数组使用，将原有数据（很多指针）拷贝到新的 map 数组中，
然后释放旧的空间。

deque 容器的分段存储结构，提高了在序列两端添加或删除元素的效率，但也使该容器迭代器的底层实现变得更复杂。
deque容器迭代器的底层实现
由于 deque 容器底层将序列中的元素分别存储到了不同段的连续空间中，因此要想实现迭代器的功能，必须先解决如下 2 个问题：
迭代器在遍历 deque 容器时，必须能够确认各个连续空间在 map 数组中的位置；
迭代器在遍历某个具体的连续空间时，必须能够判断自己是否已经处于空间的边缘位置。如果是，则一旦前进或者后退，就需要跳跃到上一个或者下一个连续空间中。

为了实现遍历 deque 容器的功能，deque 迭代器定义了如下的结构：
template<class T,...>
struct __deque_iterator{
    ...
    T* cur;
    T* first;
    T* last;
    map_pointer node;//map_pointer 等价于 T**
}
可以看到，迭代器内部包含 4 个指针，它们各自的作用为：
cur：指向当前正在遍历的元素；
first：指向当前连续空间的首地址；
last：指向当前连续空间的末尾地址；
node：它是一个二级指针，用于指向 map 数组中存储的指向当前连续空间的指针。

借助这 4 个指针，deque 迭代器对随机访问迭代器支持的各种运算符进行了重载，能够对 deque 分段连续空间中存储的元素进行遍历。例如：
//当迭代器处于当前连续空间边缘的位置时，如果继续遍历，就需要跳跃到其它的连续空间中，该函数可用来实现此功能
void set_node(map_pointer new_node){
    node = new_node;//记录新的连续空间在 map 数组中的位置
    first = *new_node; //更新 first 指针
    //更新 last 指针，difference_type(buffer_size())表示每段连续空间的长度
    last = first + difference_type(buffer_size());
}
//重载 * 运算符
reference operator*() const{return *cur;}
pointer operator->() const{return &(operator *());}
//重载前置 ++ 运算符
self & operator++(){
    ++cur;
    //处理 cur 处于连续空间边缘的特殊情况
    if(cur == last){
        //调用该函数，将迭代器跳跃到下一个连续空间中
        set_node(node+1);
        //对 cur 重新赋值
        cur = first;
    }
    return *this;
}
//重置前置 -- 运算符
self& operator--(){
    //如果 cur 位于连续空间边缘，则先将迭代器跳跃到前一个连续空间中
    if(cur == first){
        set_node(node-1);
        cur == last;
    }
    --cur;
    return *this;
}
deque容器的底层实现
了解了 deque 容器底层存储序列的结构，以及 deque 容器迭代器的内部结构之后，接下来看看 deque 容器究竟是如何实现的。

deque 容器除了维护先前讲过的 map 数组，还需要维护 start、finish 这 2 个 deque 迭代器。以下为 deque 容器的定义：
//_Alloc为内存分配器
template<class _Ty,
    class _Alloc = allocator<_Ty>>
class deque{
    ...
protected:
    iterator start;
    iterator finish;
    map_pointer map;
...
}

其中，start 迭代器记录着 map 数组中首个连续空间的信息，finish 迭代器记录着 map 数组中最后一个连续空间的信息。另外需要注意的是，和普通 
deque 迭代器不同，start 迭代器中的 cur 指针指向的是连续空间中首个元素；而 finish 迭代器中的 cur 指针指向的是连续空间最后一个元素的下一
个位置。

因此，deque 容器的底层实现如图 2 所示。

deque容器的底层实现
图 3 deque容器的底层实现

借助 start 和 finish，以及 deque 迭代器中重载的诸多运算符，就可以实现 deque 容器提供的大部分成员函数，比如：
//begin() 成员函数
iterator begin() {return start;}
//end() 成员函数
iterator end() { return finish;}
//front() 成员函数
reference front(){return *start;}
//back() 成员函数
reference back(){
    iterator tmp = finish;
    --tmp;
    return *tmp;
}
//size() 成员函数
size_type size() const{return finish - start;}//deque迭代器重载了 - 运算符
//enpty() 成员函数
bool empty() const{return finish == start;}
关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业故事+学习历程+
工作记录+生活日常+编程资料。


通过《STL deque容器》一节，详细介绍了如何创建一个 deque 容器，本节继续讲解如何访问（甚至修改）deque 容器存储的元素。

和 array、vector 容器一样，可以采用普通数组访问存储元素的方式，访问 deque 容器中的元素，比如：
#include <iostream>
#include <deque>
using namespace std;
int main()
{
    deque<int>d{ 1,2,3,4 };
    cout << d[1] << endl;
    //修改指定下标位置处的元素
    d[1] = 5;
    cout << d[1] << endl;
    return 0;
}
运行结果为：
2
5

可以看到，容器名[n]的这种方式，不仅可以访问容器中的元素，还可以对其进行修改。但需要注意的是，使用此方法需确保下标 n 的值不会超过容器中
存储元素的个数，否则会发生越界访问的错误。

如果想有效地避免越界访问，可以使用 deque 模板类提供的 at() 成员函数，由于该函数会返回容器中指定位置处元素的引用形式，因此利用该函数的
返回值，既可以访问指定位置处的元素，如果需要还可以对其进行修改。

不仅如此，at() 成员函数会自行判定访问位置是否越界，如果越界则抛出std::out_of_range异常。例如：

#include <iostream>
#include <deque>
using namespace std;
int main()
{
    deque<int>d{ 1,2,3,4 };
    cout << d.at(1) << endl;
    d.at(1) = 5;
    cout << d.at(1) << endl;
    //下面这条语句会抛出 out_of_range 异常
    //cout << d.at(10) << endl;
    return 0;
}
运行结果为：
2
5

读者可能有这样一个疑问，即为什么 deque 容器在重载 [] 运算符时，没有实现边界检查的功能呢？答案很简单，因为性能。如果每次访问元素，
都去检查索引值，无疑会产生很多开销。当不存在越界访问的可能时，就能避免这种开销。


除此之外，deque 容器还提供了 2 个成员函数，即 front() 和 back()，它们分别返回 vector 容器中第一个和最后一个元素的引用，通过利用
它们的返回值，可以访问（甚至修改）容器中的首尾元素。

举个例子：
#include <iostream>
#include <deque>
using namespace std;
int main()
{
    deque<int> d{ 1,2,3,4,5 };
    cout << "deque 首元素为：" << d.front() << endl;
    cout << "deque 尾元素为：" << d.back() << endl;
    //修改首元素
    d.front() = 10;
    cout << "deque 新的首元素为：" << d.front() << endl;
    //修改尾元素
    d.back() = 20;
    cout << "deque 新的尾元素为：" << d.back() << endl;
    return 0;
}
运行结果为：
deque 首元素为：1
deque 尾元素为：5
deque 新的首元素为：10
deque 新的尾元素为：20


注意，和 vector 容器不同，deque 容器没有提供 data() 成员函数，同时 deque 容器在存储元素时，也无法保证其会将元素存储在连续的内存空间中，
因此尝试使用指针去访问 deque 容器中指定位置处的元素，是非常危险的。

另外，结合 deque 模板类中和迭代器相关的成员函数，可以实现遍历 deque 容器中指定区域元素的方法。例如：

#include <iostream>
#include <deque>
using namespace std;
int main()
{
    deque<int> d{ 1,2,3,4,5 };
    //从元素 2 开始遍历
    auto first = d.begin() + 1;
    //遍历至 5 结束（不包括 5）
    auto end = d.end() - 1;
    while (first < end) {
        cout << *first << " ";
        ++first;
    }
    return 0;
}
运行结果为：
2 3 4

当然，deque 模板类中和迭代器相关的成员函数，还有很多，大家可以阅读《STL deque容器迭代器》做详细了解。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业故事+学习历程+
工作记录+生活日常+编程资料。


deque 容器中，无论是添加元素还是删除元素，都只能借助 deque 模板类提供的成员函数。表 1 中罗列的是所有和添加或删除容器内元素相关的 deque 
模板类中的成员函数。

表 1 和添加或删除deque容器中元素相关的成员函数
成员函数	功能
push_back()	在容器现有元素的尾部添加一个元素，和 emplace_back() 不同，该函数添加新元素的过程是，先构造元素，然后再将该元素移动或复制到
容器的尾部。
pop_back()	移除容器尾部的一个元素。
push_front()	在容器现有元素的头部添加一个元素，和 emplace_back() 不同，该函数添加新元素的过程是，先构造元素，然后再将该元素移动或
复制到容器的头部。
pop_front()	移除容器尾部的一个元素。
emplace_back()	C++ 11 新添加的成员函数，其功能是在容器尾部生成一个元素。和 push_back() 不同，该函数直接在容器头部构造元素，省去了
复制或移动元素的过程。
emplace_front()	C++ 11 新添加的成员函数，其功能是在容器头部生成一个元素。和 push_front() 不同，该函数直接在容器头部构造元素，省去了
复制或移动元素的过程。
insert()	在指定的位置直接生成一个元素。和 emplace() 不同的是，该函数添加新元素的过程是，先构造元素，然后再将该元素移动或复制到容器
的指定位置。
emplace()	C++ 11 新添加的成员函数，其功能是 insert() 相同，即在指定的位置直接生成一个元素。和 insert() 不同的是，emplace() 直接
在容器指定位置构造元素，省去了复制或移动元素的过程。
erase()	移除一个元素或某一区域内的多个元素。
clear()	删除容器中所有的元素。
在实际应用中，常用 emplace()、emplace_front() 和 emplace_back() 分别代替 insert()、push_front() 和 push_back()，具体原因本节后续会讲。

以上这些成员函数中，除了 insert() 函数的语法格式比较多，其他函数都只有一种用法（erase() 有 2 种语法格式），下面这段程序演示了它们的具体用法：
#include <deque>
#include <iostream>
using namespace std;
int main()
{
    deque<int>d;
    //调用push_back()向容器尾部添加数据。
    d.push_back(2); //{2}
    //调用pop_back()移除容器尾部的一个数据。
    d.pop_back(); //{}
    //调用push_front()向容器头部添加数据。
    d.push_front(2);//{2}
    //调用pop_front()移除容器头部的一个数据。
    d.pop_front();//{}
    //调用 emplace 系列函数，向容器中直接生成数据。
    d.emplace_back(2); //{2}
    d.emplace_front(3); //{3,2}
    //emplace() 需要 2 个参数，第一个为指定插入位置的迭代器，第二个是插入的值。
    d.emplace(d.begin() + 1, 4);//{3,4,2}
    for (auto i : d) {
        cout << i << " ";
    }
    //erase()可以接受一个迭代器表示要删除元素所在位置
    //也可以接受 2 个迭代器，表示要删除元素所在的区域。
    d.erase(d.begin());//{4,2}
    d.erase(d.begin(), d.end());//{}，等同于 d.clear()
    return 0;
}
运行结果为：
3 4 2


这里重点讲一下 insert() 函数的用法。insert() 函数的功能是在 deque 容器的指定位置插入一个或多个元素。该函数的语法格式有多种，如表 2 所示。

表 2 insert() 成员函数语法格式
语法格式	功能
iterator insert(pos,elem)	在迭代器 pos 指定的位置之前插入一个新元素elem，并返回表示新插入元素位置的迭代器。
iterator insert(pos,n,elem)	在迭代器 pos 指定的位置之前插入 n 个元素 elem，并返回表示第一个新插入元素位置的迭代器。
iterator insert(pos,first,last) 	在迭代器 pos 指定的位置之前，插入其他容器（不仅限于vector）中位于 [first,last) 区域的所有元素，
并返回表示第一个新插入元素位置的迭代器。
iterator insert(pos,initlist)	在迭代器 pos 指定的位置之前，插入初始化列表（用大括号{}括起来的多个元素，中间有逗号隔开）中所有的元素，
并返回表示第一个新插入元素位置的迭代器。

下面的程序演示了 insert() 函数的这几种用法：
#include <iostream>
#include <deque>
#include <array>
using namespace std;
int main()
{
    std::deque<int> d{ 1,2 };
    //第一种格式用法
    d.insert(d.begin() + 1, 3);//{1,3,2}
    //第二种格式用法
    d.insert(d.end(), 2, 5);//{1,3,2,5,5}
    //第三种格式用法
    std::array<int, 3>test{ 7,8,9 };
    d.insert(d.end(), test.begin(), test.end());//{1,3,2,5,5,7,8,9}
    //第四种格式用法
    d.insert(d.end(), { 10,11 });//{1,3,2,5,5,7,8,9,10,11}
    for (int i = 0; i < d.size(); i++) {
        cout << d[i] << " ";
    }
    return 0;
}
运行结果为：
1,3,2,5,5,7,8,9,10,11

emplace系列函数的优势
有关 emplace()、emplace_front() 和 emplace_back() 分别和 insert()、push_front() 和 push_back() 在运行效率上的对比，可以通过下面的
程序体现出来：

#include <deque>
#include <iostream>
using namespace std;
class testDemo
{
public:
    testDemo(int num) :num(num) {
        std::cout << "调用构造函数" << endl;
    }
    testDemo(const testDemo& other) :num(other.num) {
        std::cout << "调用拷贝构造函数" << endl;
    }
    testDemo(testDemo&& other) :num(other.num) {
        std::cout << "调用移动构造函数" << endl;
    }
    testDemo& operator=(const testDemo& other);
private:
    int num;
};
testDemo& testDemo::operator=(const testDemo& other) {
    this->num = other.num;
    return *this;
}
int main()
{
    //emplace和insert
    cout << "emplace:" << endl;
    std::deque<testDemo> demo1;
    demo1.emplace(demo1.begin(), 2);
    cout << "insert:" << endl;
    std::deque<testDemo> demo2;
    demo2.insert(demo2.begin(), 2);
   
    //emplace_front和push_front
    cout << "emplace_front:" << endl;
    std::deque<testDemo> demo3;
    demo3.emplace_front(2);
    cout << "push_front:" << endl;
    std::deque<testDemo> demo4;
    demo4.push_front(2);
    //emplace_back()和push_back()
    cout << "emplace_back:" << endl;
    std::deque<testDemo> demo5;
    demo5.emplace_back(2);
    cout << "push_back:" << endl;
    std::deque<testDemo> demo6;
    demo6.push_back(2);
    return 0;
}
运行结果为：
emplace:
调用构造函数
insert:
调用构造函数
调用移动构造函数
emplace_front:
调用构造函数
push_front:
调用构造函数
调用移动构造函数
emplace_back:
调用构造函数
push_back:
调用构造函数
调用移动构造函数

可以看到，相比和它同功能的函数，emplace 系列函数都只调用了构造函数，而没有调用移动构造函数，这无疑提高了代码的运行效率。
关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业故事+学习历程+
工作记录+生活日常+编程资料。

*/

using namespace std;
static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();

// solution
void myprint(string element) {
    cout << element << " ";
}

// main
int main() {
    deque<string> myDeque = {"First", "Second", "Third", "Forth", "Fifth"};

    // constructor copy
    deque<string> myOrgDeque1 = myDeque;
    deque<string> myOrgDeque2(myDeque);
    deque<string> myOrgDeque3(myOrgDeque1.begin(), myOrgDeque1.end());

    // show all elements in deque
    for_each(myDeque.begin(), myDeque.end(), myprint);
    cout << endl;

    // assign(), similar to vector's assign(), assign either one single value to all elements, or 
    // multilpe elements by specifying individual value per index. The index here doesn't mean 
    // continuous locations, but as deque is similar to vector that it has several blocks of 
    // vector implemented
    // STL: Replaces the contents of the container.
    // 1) Replaces the contents with count copies of value value
    // 2) Replaces the contents with copies of those in the range [first, last). The behavior is undefined if either argument 
    // is an iterator into *this. This overload has the same effect as overload (1) if InputIt is an integral type. (until C++11)
    // This overload participates in overload resolution only if InputIt satisfies LegacyInputIterator. (since C++11)
    // 3) Replaces the contents with the elements from the initializer list ilist.
    // All iterators, pointers and references to the elements of the container are invalidated. The past-the-end iterator is also 
    // invalidated.
    cout << "Call assign() to update 5 elements to New" << endl;
    myDeque.assign(5, "New");
    for_each(myDeque.begin(), myDeque.end(), myprint);
    cout << endl;
    cout << "Call assign() with begin/end iterators to update 5 elements from myOrgDeque1" << endl;
    myDeque.assign(myOrgDeque1.begin(), myOrgDeque1.end());
    for_each(myDeque.begin(), myDeque.end(), myprint);
    cout << endl;
    cout << "Call assign() by specifying value one by one" << endl;
    myDeque.assign({"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"});
    for_each(myDeque.begin(), myDeque.end(), myprint);
    cout << endl;

    // get_allocator(), same as vector's get_allocator()
    // STL: Returns the allocator associated with the container.

    // at(), read/write specific index location in deque
    // STL: Returns a reference to the element at specified location pos, with bounds checking.
    // If pos is not within the range of the container, an exception of type std::out_of_range is thrown.
    for (int i=0; i < 10; i++) {
        myDeque.at(i) = "New";
    }
    for_each(myDeque.begin(), myDeque.end(), myprint);
    cout << endl;    

    // operator[], similar to vector's operator, and no bound check like at()
    // STL: Returns a reference to the element at specified location pos. No bounds checking is performed.
    try {
        myDeque.at(100) = "New";    
    } catch (out_of_range &exec) {
        cout << exec.what() << endl;
    }

    // front(), return the first element in deque
    // STL: Returns a reference to the first element in the container.
    // Calling front on an empty container is undefined.
    myDeque = myOrgDeque1;
    cout << "The first element in deque now is " << myDeque.front() << endl;

    // back(), similar to front(), return the last element in deque
    // STL: Returns a reference to the last element in the container.
    // Calling back on an empty container causes undefined behavior.
    cout << "The last element in deque now is " << myDeque.back() << endl;

    // iterator
    cout << "The reverse strings are ";
    for (auto it=myDeque.rbegin(); it!=myDeque.rend(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // empty(), return if the deque is empty or not
    // STL: Checks if the container has no elements, i.e. whether begin() == end().
    cout << boolalpha;
    cout << "Is the deque empty? " << myDeque.empty() << endl;

    // size(), return the size of deque
    // STL: Returns the number of elements in the container, i.e. std::distance(begin(), end()).
    cout << "Size of the deque is " << myDeque.size() << endl;

    // max_size(), return the max size of deque that the current system can provide
    // STL: Returns the maximum number of elements the container is able to hold due to system or library 
    // implementation limitations, i.e. std::distance(begin(), end()) for the largest container.
    cout << "Max size of the deque is " << myDeque.max_size() << endl;

    // shrink_to_fit(), adjust the size to current existing elements in deque
    // STL: Requests the removal of unused capacity.
    // It is a non-binding request to reduce the memory usage without changing the size of the sequence. 
    // It depends on the implementation whether the request is fulfilled.
    // All iterators and references are invalidated. Past-the-end iterator is also invalidated.
    // Note that std::queue has no capacity() function (like std::vector), because of this we use a custom 
    // allocator to show the working of shrink_to_fit.
    myDeque.push_back("TEST");
    myDeque.push_back("TEST");
    myDeque.push_back("TEST");
    myDeque.push_back("TEST");
    myDeque.push_back("TEST");
    myDeque.pop_back();
    myDeque.pop_back();
    myDeque.pop_back();
    myDeque.pop_back();
    myDeque.pop_back();
    cout << "Size before shrink_to_fit() call " << myDeque.size() << endl;
    myDeque.shrink_to_fit();
    cout << "Size after shrink_to_fit() call " << myDeque.size() << endl;
    for_each(myDeque.begin(), myDeque.end(), myprint);
    cout << endl;    

    // clear(), erase all elements in the deque
    // STL: Erases all elements from the container. After this call, size() returns zero.
    // Invalidates any references, pointers, or iterators referring to contained elements. Any past-the-end iterators 
    // are also invalidated.
    cout << "Size before clear() call " << myDeque.size() << endl;
    myDeque.clear();
    cout << "Size after clear() call " << myDeque.size() << endl;

    // insert(), insert a new element into deque by index
    // STL: Inserts elements at the specified location in the container.
    // 1-2) inserts value before pos
    // 3) inserts count copies of the value before pos
    // 4) inserts elements from range [first, last) before pos.
    // This overload has the same effect as overload (3) if InputIt is an integral type. (until C++11)
    // This overload participates in overload resolution only if InputIt qualifies as LegacyInputIterator, to avoid 
    // ambiguity with the overload (3). (since C++11)
    // The behavior is undefined if first and last are iterators into *this.
    // 5) inserts elements from initializer list ilist before pos.
    // All iterators, including the past-the-end iterator, are invalidated. References are invalidated too, unless 
    // pos == begin() or pos == end(), in which case they are not invalidated.
    myDeque.insert(myDeque.begin(), 10, "OLD");
    for_each(myDeque.begin(), myDeque.end(), myprint);  // insert 10 new elements by insert() and iterator
    cout << endl;
    myDeque.insert(myDeque.begin()+5, "NEW");   // insert one new element by insert() by specific index with iterator
    for_each(myDeque.begin(), myDeque.end(), myprint);
    cout << endl;

    // emplace(), similar to insert() but construct a new element instead of copy
    // STL: Inserts a new element into the container directly before pos.
    // The element is constructed through std::allocator_traits::construct, which typically uses placement-new to construct 
    // the element in-place at a location provided by the container. However, if the required location has been occupied 
    // by an existing element, the inserted element is constructed at another location at first, and then move assigned into 
    // the required location.
    // The arguments args... are forwarded to the constructor as std::forward<Args>(args).... args... may directly or indirectly 
    // refer to a value in the container.
    // All iterators, including the past-the-end iterator, are invalidated. References are invalidated too, unless pos == begin() 
    // or pos == end(), in which case they are not invalidated.
    myDeque.emplace(myDeque.begin(), "emplace1");   // insert one new element by emplace() by specific index with iterator
    myDeque.emplace(myDeque.begin()+5, "emplace2");   // insert one new element by emplace() by specific index with iterator
    myDeque.emplace(myDeque.end(), "emplace3");   // insert one new element by emplace() by specific index with iterator
    for_each(myDeque.begin(), myDeque.end(), myprint);
    cout << endl;

    // erase(), erase the specific one element by iterator
    // STL: Erases the specified elements from the container.
    // 1) Removes the element at pos.
    // 2) Removes the elements in the range [first, last).
    // All iterators and references are invalidated, unless the erased elements are at the end or the beginning of the container, 
    // in which case only the iterators and references to the erased elements are invalidated.
    // It is unspecified when the past-the-end iterator is invalidated.	(until C++11)
    // The past-the-end iterator is also invalidated unless the erased elements are at the beginning of the container and the last 
    // element is not erased.	(since C++11)
    // The iterator pos must be valid and dereferenceable. Thus the end() iterator (which is valid, but is not dereferenceable) 
    // cannot be used as a value for pos.
    // The iterator first does not need to be dereferenceable if first==last: erasing an empty range is a no-op.
    myDeque.erase(myDeque.begin()+7);
    for_each(myDeque.begin(), myDeque.end(), myprint);
    cout << endl;

    // push_back()/emplace_back(), add one new element into deque, by copy or contract way
    // STL: Appends the given element value to the end of the container.
    // 1) The new element is initialized as a copy of value.
    // 2) value is moved into the new element.
    // All iterators, including the past-the-end iterator, are invalidated. No references are invalidated.
    // STL: Appends a new element to the end of the container. The element is constructed through 
    // std::allocator_traits::construct, which typically uses placement-new to construct the element in-place at the location 
    // provided by the container. The arguments args... are forwarded to the constructor as std::forward<Args>(args)....
    // All iterators, including the past-the-end iterator, are invalidated. No references are invalidated.
    myDeque.push_back("LAST1");
    myDeque.emplace_back("LAST2");
    for_each(myDeque.begin(), myDeque.end(), myprint);
    cout << endl;

    // pop_back(), remove element from the end of deque
    // STL: Removes the last element of the container.
    // Calling pop_back on an empty container results in undefined behavior.
    // Iterators and references to the erased element are invalidated. It is unspecified whether the past-the-end iterator is 
    // invalidated. Other references and iterators are not affected.	(until C++11)
    // Iterators and references to the erased element are invalidated. The past-the-end iterator is also invalidated. Other 
    // references and iterators are not affected.	(since C++11)
    myDeque.pop_back();
    myDeque.pop_back();
    for_each(myDeque.begin(), myDeque.end(), myprint);
    cout << endl;

    // push_front()/pop_front(), add new element into deque from the beginning. Note that deque are two directions and allow adding new
    // element at front/back or remove element at front/back as well
    // STL: Prepends the given element value to the beginning of the container.
    // All iterators, including the past-the-end iterator, are invalidated. No references are invalidated.
    // STL: Removes the first element of the container. If there are no elements in the container, the behavior is undefined.
    // Iterators and references to the erased element are invalidated. It is unspecified whether the past-the-end iterator is invalidated 
    // if the element is the last element in the container. Other references and iterators are not affected.	(until C++11)
    // Iterators and references to the erased element are invalidated. If the element is the last element in the container, the 
    // past-the-end iterator is also invalidated. Other references and iterators are not affected.	(since C++11)
    myDeque.push_front("FIRST1");
    myDeque.push_front("FIRST2");
    for_each(myDeque.begin(), myDeque.end(), myprint);
    cout << endl;
    myDeque.pop_front();
    myDeque.pop_front();
    for_each(myDeque.begin(), myDeque.end(), myprint);
    cout << endl;

    // emplace_front(), similar to posh_front(), but by constract way
    // STL: Inserts a new element to the beginning of the container. The element is constructed through std::allocator_traits::construct, 
    // which typically uses placement-new to construct the element in-place at the location provided by the container. The arguments 
    // args... are forwarded to the constructor as std::forward<Args>(args)....
    // All iterators, including the past-the-end iterator, are invalidated. No references are invalidated.
    myDeque.emplace_front("emplace_front1");
    myDeque.emplace_front("emplace_front2");
    for_each(myDeque.begin(), myDeque.end(), myprint);
    cout << endl;

    // resize(), change deque size by specific size
    // STL: Resizes the container to contain count elements.
    // If the current size is greater than count, the container is reduced to its first count elements.
    // If the current size is less than count,
    // 1) additional default-inserted elements are appended
    // 2) additional copies of value are appended.
    myDeque.resize(1);
    for_each(myDeque.begin(), myDeque.end(), myprint);
    cout << endl;
    myDeque.resize(0);
    for_each(myDeque.begin(), myDeque.end(), myprint);
    cout << endl;

    // swap(), swap elements in deque
    // STL: Exchanges the contents of the container with those of other. Does not invoke any move, copy, or swap operations on individual 
    // elements. All iterators and references remain valid. The past-the-end iterator is invalidated.
    // If std::allocator_traits<allocator_type>::propagate_on_container_swap::value is true, then the allocators are exchanged using an 
    // unqualified call to non-member swap. Otherwise, they are not swapped (and if get_allocator() != other.get_allocator(), the behavior 
    // is undefined). (since C++11)
    myDeque = myOrgDeque1;
    int i=0, j=myDeque.size();
    while (i<=j) {
        myDeque[i].swap(myDeque[j-1]);
        i++;
        j--;
    }
    for_each(myDeque.begin(), myDeque.end(), myprint);
    cout << endl;
    std::reverse(myDeque.begin(), myDeque.end());    // use std::reverse to reverse the elements back
    for_each(myDeque.begin(), myDeque.end(), myprint);
    cout << endl;

    // std::swap(), std::erase(), std::erase_of() are all similar to vector container, but they are supported from C++ 20 or above

    return 0;
}
