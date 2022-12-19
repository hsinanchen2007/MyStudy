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

前面章节讲解了 map 容器和 multimap 容器的用法，类似地，C++ STL 标准库中还提供有 set 和 multiset 这 2 个容器，它们也属于关联式容器。
不过，本节先讲解 set 容器，后续章节再讲解 multiset 容器。

和 map、multimap 容器不同，使用 set 容器存储的各个键值对，要求键 key 和值 value 必须相等。

举个例子，如下有 2 组键值对数据：
{<'a', 1>, <'b', 2>, <'c', 3>}
{<'a', 'a'>, <'b', 'b'>, <'c', 'c'>}

显然，第一组数据中各键值对的键和值不相等，而第二组中各键值对的键和值对应相等。对于 set 容器来说，只能存储第 2 组键值对，而无法存储
第一组键值对。

基于 set 容器的这种特性，当使用 set 容器存储键值对时，只需要为其提供各键值对中的 value 值（也就是 key 的值）即可。仍以存储上面第 
2 组键值对为例，只需要为 set 容器提供 {'a','b','c'} ，该容器即可成功将它们存储起来。

通过前面的学习我们知道，map、multimap 容器都会自行根据键的大小对存储的键值对进行排序，set 容器也会如此，只不过 set 容器中各键值对
的键 key 和值 value 是相等的，根据 key 排序，也就等价为根据 value 排序。

另外，使用 set 容器存储的各个元素的值必须各不相同。更重要的是，从语法上讲 set 容器并没有强制对存储元素的类型做 const 修饰，即 set 
容器中存储的元素的值是可以修改的。但是，C++ 标准为了防止用户修改容器中元素的值，对所有可能会实现此操作的行为做了限制，使得在正常情况下，
用户是无法做到修改 set 容器中元素的值的。
对于初学者来说，切勿尝试直接修改 set 容器中已存储元素的值，这很有可能破坏 set 容器中元素的有序性，最正确的修改 set 容器中元素值的
做法是：先删除该元素，然后再添加一个修改后的元素。

值得一提的是，set 容器定义于<set>头文件，并位于 std 命名空间中。因此如果想在程序中使用 set 容器，该程序代码应先包含如下语句：
#include <set>
using namespace std;
注意，第二行代码不是必需的，如果不用，则后续程序中在使用 set 容器时，需手动注明 std 命名空间（强烈建议初学者使用）。

set 容器的类模板定义如下：
template < class T,                        // 键 key 和值 value 的类型
           class Compare = less<T>,        // 指定 set 容器内部的排序规则
           class Alloc = allocator<T>      // 指定分配器对象的类型
           > class set;
注意，由于 set 容器存储的各个键值对，其键和值完全相同，也就意味着它们的类型相同，因此 set 容器类模板的定义中，仅有第 1 个参数用于设定
存储数据的类型。对于 set 类模板中的 3 个参数，后 2 个参数自带默认值，且几乎所有场景中只需使用前 2 个参数，第 3 个参数不会用到。

创建C++ set容器的几种方法
常见的创建 set 容器的方法，大致有以下 5 种。

1) 调用默认构造函数，创建空的 set 容器。比如：
std::set<std::string> myset;
如果程序中已经默认指定了 std 命令空间，这里可以省略 std::。

由此就创建好了一个 set 容器，该容器采用默认的std::less<T>规则，会对存储的 string 类型元素做升序排序。注意，由于 set 容器支持随时向
内部添加新的元素，因此创建空 set 容器的方法是经常使用的。

2) 除此之外，set 类模板还支持在创建 set 容器的同时，对其进行初始化。例如：
std::set<std::string> myset{"http://c.biancheng.net/java/",
                            "http://c.biancheng.net/stl/",
                            "http://c.biancheng.net/python/"};
由此即创建好了包含 3 个 string 元素的 myset 容器。由于其采用默认的 std::less<T> 规则，因此其内部存储 string 元素的顺序如下所示：
"http://c.biancheng.net/java/"
"http://c.biancheng.net/python/"
"http://c.biancheng.net/stl/"


3) set 类模板中还提供了拷贝（复制）构造函数，可以实现在创建新 set 容器的同时，将已有 set 容器中存储的所有元素全部复制到新 set 容器中。

例如，在第 2 种方式创建的 myset 容器的基础上，执行如下代码：
std::set<std::string> copyset(myset);
//等同于
//std::set<std::string> copyset = myset
该行代码在创建 copyset 容器的基础上，还会将 myset 容器中存储的所有元素，全部复制给 copyset 容器一份。

另外，C++ 11 标准还为 set 类模板新增了移动构造函数，其功能是实现创建新 set 容器的同时，利用临时的 set 容器为其初始化。比如：
set<string> retSet() {
    std::set<std::string> myset{ "http://c.biancheng.net/java/",
                            "http://c.biancheng.net/stl/",
                            "http://c.biancheng.net/python/" };
    return myset;
}
std::set<std::string> copyset(retSet());
//或者
//std::set<std::string> copyset = retSet();
注意，由于 retSet() 函数的返回值是一个临时 set 容器，因此在初始化 copyset 容器时，其内部调用的是 set 类模板中的移动构造函数，而非拷贝
构造函数。

显然，无论是调用复制构造函数还是调用拷贝构造函数，都必须保证这 2 个容器的类型完全一致。


4) 在第 3 种方式的基础上，set 类模板还支持取已有 set 容器中的部分元素，来初始化新 set 容器。例如：
std::set<std::string> myset{ "http://c.biancheng.net/java/",
                    "http://c.biancheng.net/stl/",
                    "http://c.biancheng.net/python/" };
std::set<std::string> copyset(++myset.begin(), myset.end());
由此初始化的 copyset 容器，其内部仅存有如下 2 个 string 字符串：
"http://c.biancheng.net/python/"
"http://c.biancheng.net/stl/"


5) 以上几种方式创建的 set 容器，都采用了默认的std::less<T>规则。其实，借助 set 类模板定义中第 2 个参数，我们完全可以手动修改 set 
容器中的排序规则。比如：
std::set<std::string,std::greater<string> > myset{
    "http://c.biancheng.net/java/",
    "http://c.biancheng.net/stl/",
    "http://c.biancheng.net/python/"};
通过选用 std::greater<string> 降序规则，myset 容器中元素的存储顺序为:
"http://c.biancheng.net/stl/"
"http://c.biancheng.net/python/"
"http://c.biancheng.net/java/"

C++ STL set容器包含的成员方法
表 1 列出了 set 容器提供的常用成员方法以及各自的功能。

表 1 C++ set 容器常用成员方法
成员方法	功能
begin()	返回指向容器中第一个（注意，是已排好序的第一个）元素的双向迭代器。如果 set 容器用 const 限定，则该方法返回的是 const 类型
的双向迭代器。
end()	返回指向容器最后一个元素（注意，是已排好序的最后一个）所在位置后一个位置的双向迭代器，通常和 begin() 结合使用。如果 set 
容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
rbegin()	返回指向最后一个（注意，是已排好序的最后一个）元素的反向双向迭代器。如果 set 容器用 const 限定，则该方法返回的是 const 
类型的反向双向迭代器。
rend()	返回指向第一个（注意，是已排好序的第一个）元素所在位置前一个位置的反向双向迭代器。如果 set 容器用 const 限定，则该方法返回
的是 const 类型的反向双向迭代器。
cbegin()	和 begin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的元素值。
cend()	和 end() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的元素值。
crbegin()	和 rbegin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的元素值。
crend()	和 rend() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的元素值。
find(val)	在 set 容器中查找值为 val 的元素，如果成功找到，则返回指向该元素的双向迭代器；反之，则返回和 end() 方法一样的迭代器。
另外，如果 set 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
lower_bound(val)	返回一个指向当前 set 容器中第一个大于或等于 val 的元素的双向迭代器。如果 set 容器用 const 限定，则该方法返回
的是 const 类型的双向迭代器。
upper_bound(val)	返回一个指向当前 set 容器中第一个大于 val 的元素的迭代器。如果 set 容器用 const 限定，则该方法返回的是 
const 类型的双向迭代器。
equal_range(val)	该方法返回一个 pair 对象（包含 2 个双向迭代器），其中 pair.first 和 lower_bound() 方法的返回值等价，
pair.second 和 upper_bound() 方法的返回值等价。也就是说，该方法将返回一个范围，该范围中包含的值为 val 的元素（set 容器中各个元素
是唯一的，因此该范围最多包含一个元素）。
empty()	若容器为空，则返回 true；否则 false。
size()	返回当前 set 容器中存有元素的个数。
max_size()	返回 set 容器所能容纳元素的最大个数，不同的操作系统，其返回值亦不相同。
insert()	向 set 容器中插入元素。
erase()	删除 set 容器中存储的元素。
swap()	交换 2 个 set 容器中存储的所有元素。这意味着，操作的 2 个 set 容器的类型必须相同。
clear()	清空 set 容器中所有的元素，即令 set 容器的 size() 为 0。
emplace()	在当前 set 容器中的指定位置直接构造新元素。其效果和 insert() 一样，但效率更高。
emplace_hint()	在本质上和 emplace() 在 set 容器中构造新元素的方式是一样的，不同之处在于，使用者必须为该方法提供一个指示新元素
生成位置的迭代器，并作为该方法的第一个参数。
count(val)	在当前 set 容器中，查找值为 val 的元素的个数，并返回。注意，由于 set 容器中各元素的值是唯一的，因此该函数的返回值最
大为 1。

下面程序演示了表 1 中部分成员函数的用法：
#include <iostream>
#include <set>
#include <string>
using namespace std;
int main()
{
    //创建空set容器
    std::set<std::string> myset;
    //空set容器不存储任何元素
    cout << "1、myset size = " << myset.size() << endl;
    //向myset容器中插入新元素
    myset.insert("http://c.biancheng.net/java/");
    myset.insert("http://c.biancheng.net/stl/");
    myset.insert("http://c.biancheng.net/python/");
    cout << "2、myset size = " << myset.size() << endl;
    //利用双向迭代器，遍历myset
    for (auto iter = myset.begin(); iter != myset.end(); ++iter) {
        cout << *iter << endl;
    }
    return 0;
}
程序执行结果为：
1、myset size = 0
2、myset size = 3
http://c.biancheng.net/java/
http://c.biancheng.net/python/
http://c.biancheng.net/stl/

有关表 1 中其它成员方法的用法，后续章节会做详细讲解。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业故事+
学习历程+工作记录+生活日常+编程资料。


和 map 容器不同，C++ STL 中的 set 容器类模板中未提供 at() 成员函数，也未对 [] 运算符进行重载。因此，要想访问 set 容器中存储的
元素，只能借助 set 容器的迭代器。

值得一提的是，C++ STL 标准库为 set 容器配置的迭代器类型为双向迭代器。这意味着，假设 p 为此类型的迭代器，则其只能进行 ++p、p++、
--p、p--、*p 操作，并且 2 个双向迭代器之间做比较，也只能使用 == 或者 != 运算符。

在 set 容器类模板提供的所有成员函数中，返回迭代器的成员函数如表 1 所示。

表 1 C++ set 容器迭代器方法
成员方法	功能
begin()	返回指向容器中第一个（注意，是已排好序的第一个）元素的双向迭代器。如果 set 容器用 const 限定，则该方法返回的是 const 
类型的双向迭代器。
end()	返回指向容器最后一个元素（注意，是已排好序的最后一个）所在位置后一个位置的双向迭代器，通常和 begin() 结合使用。如果 
set 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
rbegin()	返回指向最后一个（注意，是已排好序的最后一个）元素的反向双向迭代器。如果 set 容器用 const 限定，则该方法返回的是 
const 类型的反向双向迭代器。
rend()	返回指向第一个（注意，是已排好序的第一个）元素所在位置前一个位置的反向双向迭代器。通常和 rbegin() 结合使用。如果 set 
容器用 const 限定，则该方法返回的是 const 类型的反向双向迭代器。
cbegin()	和 begin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的元素值。
cend()	和 end() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的元素值。
crbegin()	和 rbegin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的元素值。
crend()	和 rend() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的元素值。
find(val)	在 set 容器中查找值为 val 的元素，如果成功找到，则返回指向该元素的双向迭代器；反之，则返回和 end() 方法一样的迭代器。
另外，如果 set 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
lower_bound(val)	返回一个指向当前 set 容器中第一个大于或等于 val 的元素的双向迭代器。如果 set 容器用 const 限定，则该
方法返回的是 const 类型的双向迭代器。
upper_bound(val)	返回一个指向当前 set 容器中第一个大于 val 的元素的迭代器。如果 set 容器用 const 限定，则该方法返回的是 
const 类型的双向迭代器。
equal_range(val)	该方法返回一个 pair 对象（包含 2 个双向迭代器），其中 pair.first 和 lower_bound() 方法的返回值等价，
pair.second 和 upper_bound() 方法的返回值等价。也就是说，该方法将返回一个范围，该范围中包含的值为 val 的元素（set 容器中各个
元素是唯一的，因此该范围最多包含一个元素）。

注意，以上成员函数返回的迭代器，指向的只是 set 容器中存储的元素，而不再是键值对。另外，以上成员方法返回的迭代器，无论是 const 
类型还是非 const 类型，都不能用于修改 set 容器中的值。

图 2 演示了表 1 中除最后 4 个成员函数外，其它几个成员函数的具体功能。


图 2 set容器迭代器功能示意图
其中，Ei 表示 set 容器中存储的各个元素，它们的值各不相同。

下面程序以 begin()/end() 为例，演示了如何使用图 2 中相关迭代器遍历 set 容器：
#include <iostream>
#include <set>
#include <string>
using namespace std;
int main()
{
    //创建并初始化set容器
    std::set<std::string> myset{ "http://c.biancheng.net/java/",
                                 "http://c.biancheng.net/stl/",
                                 "http://c.biancheng.net/python/"
    };
    //利用双向迭代器，遍历myset
    for (auto iter = myset.begin(); iter != myset.end(); ++iter) {
        cout << *iter << endl;
    }
    return 0;
}
程序执行结果为：
http://c.biancheng.net/java/
http://c.biancheng.net/python/
http://c.biancheng.net/stl/

再次强调，正如程序第 15 行代码所示的那样，因为 iter 迭代器指向的是 set 容器存储的某个元素，而不是键值对，因此通过 *iter 可以
直接获取该迭代器指向的元素的值。


除此之外，如果只想遍历 set 容器中指定区域内的部分数据，则可以借助 find()、lower_bound() 以及 upper_bound() 实现。通过调用
它们，可以获取一个指向指定元素的迭代器。

需要特别指出的是，equal_range(val) 函数的返回值是一个 pair 类型数据，其包含 2 个迭代器，表示 set 容器中和指定参数 val 相等
的元素所在的区域，但由于 set 容器中存储的元素各不相等，因此该函数返回的这 2 个迭代器所表示的范围中，最多只会包含 1 个元素。

举个例子：
#include <iostream>
#include <set>
#include <string>
using namespace std;
int main()
{
    //创建并初始化set容器
    std::set<std::string> myset{ "http://c.biancheng.net/java/",
                                 "http://c.biancheng.net/stl/",
                                 "http://c.biancheng.net/python/"
    };
   
    set<string>::iterator iter = myset.find("http://c.biancheng.net/python/");
    for (;iter != myset.end();++iter)
    {
        cout << *iter << endl;
    }
    return 0;
}
程序执行结果为：
http://c.biancheng.net/python/
http://c.biancheng.net/stl/

值得一提的是，虽然 C++ STL 标准中，set 类模板中包含 lower_bound()、upper_bound()、equal_range() 这 3 个成员函数，但它们更
适用于 multiset 容器，几乎不会用于操作 set 容器。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业故事+
学习历程+工作记录+生活日常+编程资料。


通过前面的学习，我们已经学会如何创建一个 set 容器。在此基础上，如果想向 set 容器中继续添加元素，可以借助 set 类模板提供的 
insert() 方法。

为满足不同场景的需要，C++ 11 标准的 set 类模板中提供了多种不同语法格式的 insert() 成员方法，它们各自的功能和用法如下所示。

1) 只要给定目标元素的值，insert() 方法即可将该元素添加到 set 容器中，其语法格式如下：
//普通引用方式传参
pair<iterator,bool> insert (const value_type& val);
//右值引用方式传参
pair<iterator,bool> insert (value_type&& val);

其中，val 表示要添加的新元素，该方法的返回值为 pair 类型。
以上 2 种格式的区别仅在于传递参数的方式不同，即第一种采用普通引用的方式传参，而第二种采用右值引用的方式传参。右值引用为 C++ 11 
新添加的一种引用方式，可阅读《C++ 右值引用》一文做详细了解。

可以看到，以上 2 种语法格式的 insert() 方法，返回的都是 pair 类型的值，其包含 2 个数据，一个迭代器和一个 bool 值：
当向 set 容器添加元素成功时，该迭代器指向 set 容器新添加的元素，bool 类型的值为 true；
如果添加失败，即证明原 set 容器中已存有相同的元素，此时返回的迭代器就指向容器中相同的此元素，同时 bool 类型的值为 false。

举个例子：
#include <iostream>
#include <set>
#include <string>
using namespace std;
int main()
{
    //创建并初始化set容器
    std::set<std::string> myset;
    //准备接受 insert() 的返回值
    pair<set<string>::iterator, bool> retpair;
    //采用普通引用传值方式
    string str = "http://c.biancheng.net/stl/";
    retpair = myset.insert(str);
    cout << "iter->" << *(retpair.first) << " " << "bool = " << retpair.second << endl;
    //采用右值引用传值方式
    retpair = myset.insert("http://c.biancheng.net/python/");
    cout << "iter->" << *(retpair.first) << " " << "bool = " << retpair.second << endl;
    return 0;
}
程序执行结果为：
iter->http://c.biancheng.net/stl/ bool = 1
iter->http://c.biancheng.net/python/ bool = 1

通过观察输出结果不难看出，程序中两次借助 insert() 方法向 set 容器中添加元素，都成功了。

2) insert() 还可以指定将新元素插入到 set 容器中的具体位置，其语法格式如下：
//以普通引用的方式传递 val 值
iterator insert (const_iterator position, const value_type& val);
//以右值引用的方式传递 val 值
iterator insert (const_iterator position, value_type&& val);

以上 2 种语法格式中，insert() 函数的返回值为迭代器：
当向 set 容器添加元素成功时，该迭代器指向容器中新添加的元素；
当添加失败时，证明原 set 容器中已有相同的元素，该迭代器就指向 set 容器中相同的这个元素。

举个例子：
#include <iostream>
#include <set>
#include <string>
using namespace std;
int main()
{
    //创建并初始化set容器
    std::set<std::string> myset;
    //准备接受 insert() 的返回值
    set<string>::iterator iter;
    //采用普通引用传值方式
    string str = "http://c.biancheng.net/stl/";
    iter = myset.insert(myset.begin(),str);
    cout << "myset size =" << myset.size() << endl;
    //采用右值引用传值方式
    iter = myset.insert(myset.end(),"http://c.biancheng.net/python/");
    cout << "myset size =" << myset.size() << endl;
    return 0;
}
程序执行结果为：
myset size =1
myset size =2

注意，使用 insert() 方法将目标元素插入到 set 容器指定位置后，如果该元素破坏了容器内部的有序状态，set 容器还会自行对新元素
的位置做进一步调整。也就是说，insert() 方法中指定新元素插入的位置，并不一定就是该元素最终所处的位置。


3) insert() 方法支持向当前 set 容器中插入其它 set 容器指定区域内的所有元素，只要这 2 个 set 容器存储的元素类型相同即可。

insert() 方法的语法格式如下：
template <class InputIterator>
  void insert (InputIterator first, InputIterator last);

其中 first 和 last 都是迭代器，它们的组合 [first,last) 可以表示另一 set 容器中的一块区域，该区域包括 first 迭代器指向
的元素，但不包含 last 迭代器指向的元素。

举个例子：
#include <iostream>
#include <set>
#include <string>
using namespace std;
int main()
{
    //创建并初始化set容器
    std::set<std::string> myset{ "http://c.biancheng.net/stl/",
                                "http://c.biancheng.net/python/",
                                "http://c.biancheng.net/java/" };
    //创建一个同类型的空 set 容器
    std::set<std::string> otherset;
    //利用 myset 初始化 otherset
    otherset.insert(++myset.begin(), myset.end());
    //输出 otherset 容器中的元素
    for (auto iter = otherset.begin(); iter != otherset.end(); ++iter) {
        cout << *iter << endl;
    }
    return 0;
}
程序执行结果为：
http://c.biancheng.net/python/
http://c.biancheng.net/stl/

注意，程序第 15 行在初始化 otherset 容器时，选取的是 myset 容器中从第 2 个元素开始（包括此元素）直到容器末尾范围内的所有
元素，所以程序输出结果中只有 2 个字符串。

4) 采用如下格式的 insert() 方法，可实现一次向 set 容器中添加多个元素：
void insert ( {E1, E2,...,En} );

其中，Ei 表示新添加的元素。

举个例子：
#include <iostream>
#include <set>
#include <string>
using namespace std;
int main()
{
    //创建并初始化set容器
    std::set<std::string> myset;
    //向 myset 中添加多个元素
    myset.insert({ "http://c.biancheng.net/stl/",
        "http://c.biancheng.net/python/",
        "http://c.biancheng.net/java/" });
    for (auto iter = myset.begin(); iter != myset.end(); ++iter) {
        cout << *iter << endl;
    }
    return 0;
}
程序执行结果为：
http://c.biancheng.net/java/
http://c.biancheng.net/python/
http://c.biancheng.net/stl/

以上的讲解，即为 set 类模板中 insert() 成员方法的全部用法。指的一提的是，C++ 11 标准的 set 类模板中，还提供有另外 2 个成员
方法，分别为 implace() 和 implace_hint() 方法，借助它们不但能实现向 set 容器添加新元素的功能，其实现效率也比 insert() 
成员方法更高。

有关 set 类模板中 implace() 和 implace_hint() 方法的用法，后续章节会做详细介绍。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业故事+
学习历程+工作记录+生活日常+编程资料。


要知道，set 类模板提供的所有成员方法中，能实现向指定 set 容器中添加新元素的，只有 3 个成员方法，分别为 insert()、emplace() 
和 emplace_hint()。其中 insert() 成员方法的用法已在前面章节做了详细的讲解，本节重点介绍剩下的这 2 个成员方法。

emplace() 和 emplace_hint() 是 C++ 11 标准加入到 set 类模板中的，相比具有同样功能的 insert() 方法，完成同样的任务，
emplace() 和 emplace_hint() 的效率会更高。

emplace() 方法的语法格式如下：
template <class... Args>
  pair<iterator,bool> emplace (Args&&... args);

其中，参数 (Args&&... args) 指的是，只需要传入构建新元素所需的数据即可，该方法可以自行利用这些数据构建出要添加的元素。
比如，若 set 容器中存储的元素类型为自定义的结构体或者类，则在使用 emplace() 方法向容器中添加新元素时，构造新结构体变量
（或者类对象）需要多少个数据，就需要为该方法传入相应个数的数据。

另外，该方法的返回值类型为 pair 类型，其包含 2 个元素，一个迭代器和一个 bool 值：
当该方法将目标元素成功添加到 set 容器中时，其返回的迭代器指向新插入的元素，同时 bool 值为 true；
当添加失败时，则表明原 set 容器中已存在相同值的元素，此时返回的迭代器指向容器中具有相同键的这个元素，同时 bool 值为 false。

下面程序演示 emplace() 方法的具体用法：
#include <iostream>
#include <set>
#include <string>
using namespace std;
int main()
{
    //创建并初始化 set 容器
    std::set<string>myset;
    //向 myset 容器中添加元素
    pair<set<string, string>::iterator, bool> ret = myset.emplace("http://c.biancheng.net/stl/");
    cout << "myset size = " << myset.size() << endl;
    cout << "ret.iter = <" << *(ret.first) << ", " << ret.second << ">" << endl;
    return 0;
}
程序执行结果为：
myset size = 1
ret.iter = <http://c.biancheng.net/stl/, 1>

显然，从执行结果可以看出，通过调用 emplace() 方法，成功向空 myset 容器中添加了一个元素，并且该方法的返回值中就包含指向
新添加元素的迭代器。

emplace_hint() 方法的功能和 emplace() 类似，其语法格式如下：
template <class... Args>
  iterator emplace_hint (const_iterator position, Args&&... args);

和 emplace() 方法相比，有以下 2 点不同：
该方法需要额外传入一个迭代器，用来指明新元素添加到 set 容器的具体位置（新元素会添加到该迭代器指向元素的前面）；
返回值是一个迭代器，而不再是 pair 对象。当成功添加元素时，返回的迭代器指向新添加的元素；反之，如果添加失败，则迭代器就
指向 set 容器和要添加元素的值相同的元素。

下面程序演示 emplace_hint() 方法的用法：
#include <iostream>
#include <set>
#include <string>
using namespace std;
int main()
{
    //创建并初始化 set 容器
    std::set<string>myset;
    //在 set 容器的指定位置添加键值对
    set<string>::iterator iter = myset.emplace_hint(myset.begin(), "http://c.biancheng.net/stl/");
    cout << "myset size = " << myset.size() << endl;
    cout << *iter << endl;
    return 0;
}
程序执行结果为：
myset size = 1
http://c.biancheng.net/stl/

注意，和 insert() 方法一样，虽然 emplace_hint() 方法中指定了添加新元素的位置，但 set 容器为了保持数据的有序状态，
可能会移动其位置。

以上内容讲解了 emplace() 和 emplace_hint() 的用法，至于比 insert() 执行效率高的原因，可参照 map 容器 emplace() 
和 emplace_hint() 比 insert() 效率高的原因，它们是完全一样的，这里不再赘述。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享
创业故事+学习历程+工作记录+生活日常+编程资料。


如果想删除 set 容器存储的元素，可以选择用 erase() 或者 clear() 成员方法。

set 类模板中，erase() 方法有 3 种语法格式，分别如下：
//删除 set 容器中值为 val 的元素
size_type erase (const value_type& val);
//删除 position 迭代器指向的元素
iterator  erase (const_iterator position);
//删除 [first,last) 区间内的所有元素
iterator  erase (const_iterator first, const_iterator last);

其中，第 1 种格式的 erase() 方法，其返回值为一个整数，表示成功删除的元素个数；后 2 种格式的 erase() 方法，返回值都
是迭代器，其指向的是 set 容器中删除元素之后的第一个元素。
注意，如果要删除的元素就是 set 容器最后一个元素，则 erase() 方法返回的迭代器就指向新 set 容器中最后一个元素之后的
位置（等价于 end() 方法返回的迭代器）。

下面程序演示了以上 3 种 erase() 方法的用法：
#include <iostream>
#include <set>
#include <string>
using namespace std;
int main()
{
    //创建并初始化 set 容器
    std::set<int>myset{1,2,3,4,5};
    cout << "myset size = " << myset.size() << endl;
   
    //1) 调用第一种格式的 erase() 方法
    int num = myset.erase(2); //删除元素 2，myset={1,3,4,5}
    cout << "1、myset size = " << myset.size() << endl;
    cout << "num = " << num << endl;
    //2) 调用第二种格式的 erase() 方法
    set<int>::iterator iter = myset.erase(myset.begin()); //删除元素 1，myset={3,4,5}
    cout << "2、myset size = " << myset.size() << endl;
    cout << "iter->" << *iter << endl;
    //3) 调用第三种格式的 erase() 方法
    set<int>::iterator iter2 = myset.erase(myset.begin(), --myset.end());//删除元素 3,4，myset={5}
    cout << "3、myset size = " << myset.size() << endl;
    cout << "iter2->" << *iter2 << endl;
    return 0;
}
程序执行结果为：
myset size = 5
1、myset size = 4
num = 1
2、myset size = 3
iter->3
3、myset size = 1
iter2->5


如果需要删除 set 容器中存储的所有元素，可以使用 clear() 成员方法。该方法的语法格式如下：
void clear();

显然，该方法不需要传入任何参数，也没有任何返回值。

举个例子：
#include <iostream>
#include <set>
#include <string>
using namespace std;
int main()
{
    //创建并初始化 set 容器
    std::set<int>myset{1,2,3,4,5};
    cout << "1、myset size = " << myset.size() << endl;
    //清空 myset 容器
    myset.clear();
    cout << "2、myset size = " << myset.size() << endl;
    return 0;
}
程序执行结果为：
1、myset size = 5
2、myset size = 0

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，
专注于分享创业故事+学习历程+工作记录+生活日常+编程资料。

*/

using namespace std;
static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();

// solution
// Example module 97 key compare function
struct ModCmp {
    bool operator()(const int lhs, const int rhs) const
    {
        return (lhs % 97) < (rhs % 97);
    }
};

// main
int main() {
    // STL set, key is value and only unique key is allowed, key will be sorted automatically
    set<string> mySet1;
    set<string> mySet2;
    set<string> mySet3;

    // constructor, the input keys are with random order, but once it is built, key will be 
    // sorted automatically
    mySet1.insert("cat");
    mySet1.insert("dog");
    mySet1.insert("tiger");
    mySet1.insert("chicken");
    mySet1.insert("bird");
    mySet1.insert("elephant");
    mySet1.insert("flamingo");
    mySet1.insert("snake");

    // assign from one set to another set
    mySet2 = mySet1;

    // move from one set to another set
    mySet3 = std::move(mySet2);

    // from/begin way, but it needed to do it when it is first defined
    set<string> mySet4(mySet1.begin(), mySet1.end());

    // another way to define mySet5
    set<string> mySet5(mySet4);

    // iterator
    // note that in the for_each statement, the third parameter is "[](string a) {}", if it is 
    // not defined in seperate function
    cout << "mySet1 by for_each() way" << endl;
    for_each(mySet1.begin(), mySet1.end(), [] (string a) {
        cout << a << endl;
    });
    // like other containers, use for loop with ++ to iterate all elements
    cout << "All elements in all set for for loop way" << endl;
    cout << "mySet1" << endl;
    for (auto item=mySet1.begin(); item!=mySet1.end(); item++) {
        cout << *item << endl;
    }
    cout << "mySet2" << endl;
    for (auto item=mySet2.begin(); item!=mySet2.end(); item++) {
        cout << *item << endl;
    }
    cout << "mySet3" << endl;
    for (auto item=mySet3.begin(); item!=mySet3.end(); item++) {
        cout << *item << endl;
    }
    // get reference, which is true element in mySet4
    cout << "mySet4" << endl;
    for (auto &item : mySet4) {
        cout << item << endl;
    }
    cout << "mySet5" << endl;
    for (auto item : mySet5) {
        cout << item << endl;
    }

    // empty(), check if the given set is empty or not
    // STL: Checks if the container has no elements, i.e. whether begin() == end()
    cout << boolalpha;
    cout << "Is mySet5 empty? " << mySet5.empty() << endl;

    // size(), check how many elements in the set
    // STL: Returns the number of elements in the container, i.e. std::distance(begin(), end())
    cout << "How many elements in mySet4? " << mySet4.size() << endl;
    mySet4.clear();
    cout << "How many elements in mySet4 after clear() call? " << mySet4.size() << endl;

    // max_size(), return the max size that the current system can hold
    // STL: Returns the maximum number of elements the container is able to hold due to system or 
    // library implementation limitations, i.e. std::distance(begin(), end()) for the largest container.
    cout << "Max size of the mySet1 in system " << mySet1.max_size() << endl;

    // clear(), erase all elements in the set
    // STL: Erases all elements from the container. After this call, size() returns zero.
    // Invalidates any references, pointers, or iterators referring to contained elements. Any past-the-end 
    // iterator remains valid.
    cout << "How many elements in mySet5? " << mySet5.size() << endl;
    mySet5.clear();
    cout << "How many elements in mySet5 after clear() call? " << mySet5.size() << endl;

    // insert(), add a new element into set
    // STL: Inserts element(s) into the container, if the container doesn't already contain an element with 
    // an equivalent key.
    // 1-2) inserts value.
    // 3-4) inserts value in the position as close as possible, just prior(since C++11), to hint.
    // 5) Inserts elements from range [first, last). If multiple elements in the range have keys that compare 
    // equivalent, it is unspecified which element is inserted (pending LWG2844).
    // 6) Inserts elements from initializer list ilist. If multiple elements in the range have keys that compare 
    // equivalent, it is unspecified which element is inserted (pending LWG2844).
    // 7) If nh is an empty node handle, does nothing. Otherwise, inserts the element owned by nh into the container 
    // , if the container doesn't already contain an element with a key equivalent to nh.key(). The behavior is 
    // undefined if nh is not empty and get_allocator() != nh.get_allocator().
    // 8) If nh is an empty node handle, does nothing and returns the end iterator. Otherwise, inserts the element 
    // owned by nh into the container, if the container doesn't already contain an element with a key equivalent to 
    // nh.key(), and returns the iterator pointing to the element with key equivalent to nh.key() (regardless of whether 
    // the insert succeeded or failed). If the insertion succeeds, nh is moved from, otherwise it retains ownership 
    // of the element. The element is inserted as close as possible to the position just prior to hint. The behavior 
    // is undefined if nh is not empty and get_allocator() != nh.get_allocator().
    // No iterators or references are invalidated. If the insertion is successful, pointers and references to the 
    // element obtained while it is held in the node handle are invalidated, and pointers and references obtained to 
    // that element before it was extracted become valid. (since C++17)
    mySet1.insert("xyz");
    cout << "After inserting xyz intio mySet1, this one should be added into last one if we iterate all elements" << endl;
    for_each(mySet1.begin(), mySet1.end(), [] (string a) {
        cout << a << endl;
    });

    // emplace(), construct a new element into set. This operation should be faster
    // STL: Inserts a new element into the container constructed in-place with the given args if there is no element 
    // with the key in the container.
    // Careful use of emplace allows the new element to be constructed while avoiding unnecessary copy or move operations. 
    // The constructor of the new element is called with exactly the same arguments as supplied to emplace, forwarded via 
    // std::forward<Args>(args).... The element may be constructed even if there already is an element with the key in the 
    // container, in which case the newly constructed element will be destroyed immediately.
    // No iterators or references are invalidated.
    mySet1.emplace("zyx");
    cout << "After inserting zyx intio mySet1, this one should be added into last one if we iterate all elements" << endl;
    for_each(mySet1.begin(), mySet1.end(), [] (string a) {
        cout << a << endl;
    });

    // emplace_hint(), by giving a hint to construct new element into set, however, it is still be sorted and added based on
    // the key, the hint is just a hint
    // STL: Inserts a new element into the container as close as possible to the position just before hint. The element 
    // is constructed in-place, i.e. no copy or move operations are performed.
    // The constructor of the element is called with exactly the same arguments as supplied to the function, forwarded 
    // with std::forward<Args>(args)....
    // No iterators or references are invalidated.
    mySet1.emplace_hint(mySet1.begin(), "zyx2");
    cout << "After inserting zyx2 intio mySet1 by hint, this one should be still added into last one if we iterate all elements" << endl;
    for_each(mySet1.begin(), mySet1.end(), [] (string a) {
        cout << a << endl;
    });

    // erase(), remove one specific element from set
    // STL: Removes specified elements from the container.
    // 1) Removes the element at pos. Only one overload is provided if iterator and const_iterator are the same type. 
    // (since C++11)
    // 2) Removes the elements in the range [first; last), which must be a valid range in *this.
    // 3) Removes the element (if one exists) with the key equivalent to key.
    // 4) Removes the element (if one exists) with key that compares equivalent to the value x. This overload participates 
    // in overload resolution only if the qualified-id Compare::is_transparent is valid and denotes a type, and neither iterator 
    // nor const_iterator is implicitly convertible from K. It allows calling this function without constructing an instance of Key.
    // References and iterators to the erased elements are invalidated. Other references and iterators are not affected.
    // The iterator pos must be valid and dereferenceable. Thus the end() iterator (which is valid, but is not dereferenceable) 
    // cannot be used as a value for pos.
    mySet1.erase("xyz");
    mySet1.erase("zyx");
    mySet1.erase("zyx2");
    cout << "After removing all xyz elements, the updated mySet1" << endl;
    for_each(mySet1.begin(), mySet1.end(), [] (string a) {
        cout << a << endl;
    });    

    // erase elements based on begin/end iterators
    mySet5 = mySet1;
    mySet5.erase(mySet5.begin(), mySet5.end());
    cout << "After removing all elements, the updated mySet5" << endl;
    for_each(mySet5.begin(), mySet5.end(), [] (string a) {
        cout << a << endl;
    });

    // swap(), swap elements from one set to another set. Note that the swapped elements are from different sets, 
    // not within same set
    // STL: Exchanges the contents of the container with those of other. Does not invoke any move, copy, or swap operations on 
    // individual elements.
    // All iterators and references remain valid. The past-the-end iterator is invalidated.
    // The Compare objects must be Swappable, and they are exchanged using unqualified call to non-member swap.
    // If std::allocator_traits<allocator_type>::propagate_on_container_swap::value is true, then the allocators are exchanged 
    // using an unqualified call to non-member swap. Otherwise, they are not swapped (and if get_allocator() != other.get_allocator(), 
    // the behavior is undefined). (since C++11)
    set<int> myIntSet1={1,3,5,7,9};
    set<int> myIntSet2={2,4,6,8,10};
    cout << "Before swap, myIntSet1" << endl;
    for_each(myIntSet1.begin(), myIntSet1.end(), [] (int a) {
        cout << a << endl;
    });
    cout << "Before swap, myIntSet2" << endl;
    for_each(myIntSet2.begin(), myIntSet2.end(), [] (int a) {
        cout << a << endl;
    });
    myIntSet2.swap(myIntSet1);
    cout << "After swap, myIntSet1" << endl;
    for_each(myIntSet1.begin(), myIntSet1.end(), [] (int a) {
        cout << a << endl;
    });
    cout << "After swap, myIntSet2" << endl;
    for_each(myIntSet2.begin(), myIntSet2.end(), [] (int a) {
        cout << a << endl;
    });
    myIntSet2.swap(myIntSet1);

    // extract(), get the key from set, and can change it accordingly. Note that the value() should be used
    // STL: 1) Unlinks the node that contains the element pointed to by position and returns a node handle that owns it.
    // 2) If the container has an element with key equivalent to k, unlinks the node that contains that element from the 
    // container and returns a node handle that owns it. Otherwise, returns an empty node handle.
    // 3) Same as (2). This overload participates in overload resolution only if the qualified-id Compare::is_transparent 
    // is valid and denotes a type, and neither iterator nor const_iterator is implicitly convertible from K. It allows 
    // calling this function without constructing an instance of Key.
    // In either case, no elements are copied or moved, only the internal pointers of the container nodes are repointed 
    // (rebalancing may occur, as with erase())
    // Extracting a node invalidates only the iterators to the extracted element. Pointers and references to the extracted 
    // element remain valid, but cannot be used while element is owned by a node handle: they become usable if the element 
    // is inserted into a container.  
    //
    // auto key=myIntSet2.extract(1);
    // key.value() = 2;

    // merge(), merge elements from one set to another set
    // STL: Attempts to extract ("splice") each element in source and insert it into *this using the comparison object of 
    // *this. If there is an element in *this with key equivalent to the key of an element from source, then that element 
    // is not extracted from source. No elements are copied or moved, only the internal pointers of the container nodes are 
    // repointed. All pointers and references to the transferred elements remain valid, but now refer into *this, not into 
    // source.
    // The behavior is undefined if get_allocator() != source.get_allocator().
    // 
    // myIntSet1.merge(myIntSet2);

    // count(), return number of elements of that specific key. In general, this should be either 0 or 1 as set only allows
    // one key
    // STL: Returns the number of elements with key that compares equivalent to the specified argument, which is either 1 or 0 
    // since this container does not allow duplicates.
    // 1) Returns the number of elements with key key.
    // 2) Returns the number of elements with key that compares equivalent to the value x. This overload participates in overload 
    // resolution only if the qualified-id Compare::is_transparent is valid and denotes a type. They allow calling this function 
    // without constructing an instance of Key.
    cout << "How many elements of dog from mySet1? " << mySet1.count("dog") << endl;
    cout << "How many elements of eagle from mySet1? " << mySet1.count("eagle") << endl;

    // find(), find one specific element from set, and we can check if the return is valud by using end() like other containers
    // STL: 1,2) Finds an element with key equivalent to key.
    // 3,4) Finds an element with key that compares equivalent to the value x. This overload participates in overload resolution 
    // only if the qualified-id Compare::is_transparent is valid and denotes a type. It allows calling this function without 
    // constructing an instance of Key.
    auto search=mySet1.find("cat");
    if (search != mySet1.end()) {
        cout << "Find the key cat " << *search << endl;
    } else {
        cout << "Do not find the key cat " << endl;
    }
    search=mySet1.find("eagle");
    if (search != mySet1.end()) {
        cout << "Find the key cat " << *search << endl;
    } else {
        cout << "Do not find the key eagle" << endl;
    }

    // contains(), check if the given element existed in the set
    // STL: 1) Checks if there is an element with key equivalent to key in the container.
    // 2) Checks if there is an element with key that compares equivalent to the value x. This overload participates in overload 
    // resolution only if the qualified-id Compare::is_transparent is valid and denotes a type. It allows calling this function 
    // without constructing an instance of Key.
    // search=mySet1.contains("dog");

    // equal_range(), return a pair of iterators like begin() and end() based on the specified range. The first iterator will be 
    // the one of lower range or the exact one specified in the given element
    // STL: Returns a range containing all elements with the given key in the container. The range is defined by two iterators, 
    // one pointing to the first element that is not less than key and another pointing to the first element greater than key. 
    // Alternatively, the first iterator may be obtained with lower_bound(), and the second with upper_bound().
    // 1,2) Compares the keys to key.
    // 3,4) Compares the keys to the value x. This overload participates in overload resolution only if the qualified-id 
    // Compare::is_transparent is valid and denotes a type. It allows calling this function without constructing an instance of Key.
    cout << "mySet1 by for_each() way" << endl;
    for_each(mySet1.begin(), mySet1.end(), [] (string a) {cout << a << endl;});
    cout << "Element dog is located at the range" << endl;
    auto [la, ub] = mySet1.equal_range("dog");
    cout << *la << endl;
    cout << *ub << endl;

    // when using a key which is not existed in the set, it will return one closest
    // for example, "eagle" is not there, so it returns "elephant" which is the only one starting from latter "e" in the set
    cout << "Element eagle is not located in the set" << endl;
    auto [laa, ubb] = mySet1.equal_range("eagle");
    cout << *laa << endl;
    cout << *ubb << endl;

    // lower_bound()/upper_bound(), get lower and upper bounds, here it returns only one, not a pair like equal_range()
    // STL: 1) Returns an iterator pointing to the first element that is not less than (i.e. greater or equal to) key.
    // 2) Returns an iterator pointing to the first element that compares not less (i.e. greater or equal) to the value x. 
    // This overload participates in overload resolution only if the qualified-id Compare::is_transparent is valid and denotes 
    // a type. It allows calling this function without constructing an instance of Key.
    auto lower = mySet1.lower_bound("dog");
    auto higher = mySet1.upper_bound("dog");
    cout << "Lower bound is " << *lower << " upper bound is " << *higher << endl;

    std::set<int, ModCmp> cont{1, 2, 3, 4, 5};

    // key_comp()/value_comp(), never use this one before, below code example is from https://en.cppreference.com/w/cpp/container/set/key_comp
    // STL: Returns the function object that compares the keys, which is a copy of this container's constructor argument comp. 
    // It is the same as value_comp.
    // STL: Returns the function object that compares the values. It is the same as key_comp.
    auto comp_func = cont.key_comp();
    for (int key : cont) {
        bool before = comp_func(key, 100);
        bool after = comp_func(100, key);
        if (!before && !after)
            std::cout << key << " equivalent to key 100\n";
        else if (before)
            std::cout << key << " goes before key 100\n";
        else if (after)
            std::cout << key << " goes after key 100\n";
        else
            std::cout << "Error\n";
    }

    // std::swap(), similar to swap(), and it swap the whole set
    // STL: Specializes the std::swap algorithm for std::set. Swaps the contents of lhs and rhs. Calls lhs.swap(rhs).
    cout << "Before swap, myIntSet1" << endl;
    for_each(myIntSet1.begin(), myIntSet1.end(), [] (int a) {
        cout << a << endl;
    });
    cout << "Before swap, myIntSet2" << endl;
    for_each(myIntSet2.begin(), myIntSet2.end(), [] (int a) {
        cout << a << endl;
    });
    std::swap(myIntSet1, myIntSet2);
    cout << "After swap, myIntSet1" << endl;
    for_each(myIntSet1.begin(), myIntSet1.end(), [] (int a) {
        cout << a << endl;
    });
    cout << "After swap, myIntSet2" << endl;
    for_each(myIntSet2.begin(), myIntSet2.end(), [] (int a) {
        cout << a << endl;
    });

    // erase_if(), erase the elements if it matches the criteria
    // STL: Erases all elements that satisfy the predicate pred from the container. Equivalent to
    // auto divisible_by_3 = [](auto const& x) { return (x % 3) == 0; };
    // const auto count = std::erase_if(myIntSet2 divisible_by_3);



    return 0;
}
