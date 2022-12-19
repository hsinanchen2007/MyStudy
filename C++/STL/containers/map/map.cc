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

在《C++ STL容器》一节中讲到，C++ 容器大致分为 2 类，即序列式容器和关联式容器。其中，序列式容器（包括 array、vector、list、deque 和 
forward_list）已经在前面章节中做了详细的介绍，从本节开始，将逐个对 C++ STL 标准库中的所有关联式容器做详细的讲解。

提到 C++ STL 关联式容器，读者可能会以下一些疑问：
关联式容器是什么，具有哪些特点？
和序列式容器相比，关联式容器有什么不同？
关联式容器的种类有哪些？

别急，读完本文，这些疑问都会迎刃而解。
C++ STL关联式容器是什么
通过学习所有的序列式容器不难发现，无论是哪种序列式容器，其存储的都是 C++ 基本数据类型（诸如 int、double、float、string 等）或使用
结构体自定义类型的元素。例如，如下是一个存储 int 类型元素的 vector 容器：

std::vector<int> primes {2, 3, 5, 7, 11, 13, 17, 19};


关联式容器则大不一样，此类容器在存储元素值的同时，还会为各元素额外再配备一个值（又称为“键”，其本质也是一个 C++ 基础数据类型或自定义
类型的元素），它的功能是在使用关联式容器的过程中，如果已知目标元素的键的值，则直接通过该键就可以找到目标元素，而无需再通过遍历整个
容器的方式。弃用序列式容器，转而选用关联式容器存储元素，往往就是看中了关联式容器可以快速查找、读取或者删除所存储的元素，同时该类型容器
插入元素的效率也比序列式容器高。

也就是说，使用关联式容器存储的元素，都是一个一个的“键值对”（ <key,value> ），这是和序列式容器最大的不同。除此之外，序列式容器中存储
的元素默认都是未经过排序的，而使用关联式容器存储的元素，默认会根据各元素的键值的大小做升序排序。

注意，关联式容器所具备的这些特性，归咎于 STL 标准库在实现该类型容器时，底层选用了 「红黑树」这种数据结构来组织和存储各个键值对。有关
红黑树组织和存储数据的方式，我们已经在数据结构中做了详细的介绍，读者可猛击《红黑树》一文做详细了解。

C++ STL关联式容器种类
C++ STL 标准库提供了 4 种关联式容器，分别为 map、set、multimap、multiset，其各自的特点如表 1 所示。

表 1 C++ STL关联式容器类别
关联式容器名称	特点
map	定义在 <map> 头文件中，使用该容器存储的数据，其各个元素的键必须是唯一的（即不能重复），该容器会根据各元素键的大小，默认进行升序
排序（调用 std::less<T>）。
set	定义在 <set> 头文件中，使用该容器存储的数据，各个元素键和值完全相同，且各个元素的值不能重复（保证了各元素键的唯一性）。该容器会
自动根据各个元素的键（其实也就是元素值）的大小进行升序排序（调用 std::less<T>）。
multimap	定义在 <map> 头文件中，和 map 容器唯一的不同在于，multimap 容器中存储元素的键可以重复。
multiset	定义在 <set> 头文件中，和 set 容器唯一的不同在于，multiset 容器中存储元素的值可以重复（一旦值重复，则意味着键也是重复的）。
除此之外，C++ 11 还新增了 4 种哈希容器，即 unordered_map、unordered_multimap 以及 unordered_set、unordered_multiset。严格来说，
它们也属于关联式容器，但由于哈希容器底层采用的是哈希表，而不是红黑树，因此本教程将它们分开进行讲解（有关哈希容器，将放在后续章节做详细讲解）。


为了让读者直观地认识到关联式容器的特性，这里为 map 容器为例，编写了一个样例（如下所示）。对于该程序，读者只需体会关联式容器的特性即可，
无需纠结 map 容器的具体用法。

#include <iostream>
#include <map> //使用 map 容器，必须引入该头文件
#include <string>
using namespace std;
int main()
{
    //创建一个空的 map 关联式容器，该容器中存储的键值对，其中键为 string 字符串，值也为 string 字符串类型
    map<string, string> mymap;
    //向 mymap 容器中添加数据
    mymap["http://c.biancheng.net/c/"] = "C语言教程";
    mymap["http://c.biancheng.net/python/"] = "Python教程";
    mymap["http://c.biancheng.net/java/"] = "Java教程";
    //使用 map 容器的迭代器，遍历 mymap 容器，并输出其中存储的各个键值对
    for (map<string, string>::iterator it = mymap.begin(); it != mymap.end(); ++it) {
        //输出各个元素中的键和值
        cout << it->first << " => " << it->second << '\n';
    }
    return 0;
}
程序输出结果为：
http://c.biancheng.net/c/ => C语言教程
http://c.biancheng.net/java/ => Java教程
http://c.biancheng.net/python/ => Python教程


通过分析该程序的执行过程不难看出，mymap 关联式容器中的存储了以下 3 个键值对：
<"http://c.biancheng.net/c/", "C语言教程">
<"http://c.biancheng.net/python/", "Python教程">
<"http://c.biancheng.net/java/", "Java教程">

但需要注意的一点是，由于 map 容器在存储元素时，会根据各个元素键的大小自动调整元素的顺序（默认按照升序排序），因此该容器最终存储的元素顺序为：
<"http://c.biancheng.net/c/", "C语言教程">
<"http://c.biancheng.net/java/", "Java教程">
<"http://c.biancheng.net/python/", "Python教程">

有关 map 容器以及表 1 中其它关联式容器的具体用法，后续章节会做详细介绍。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业故事+学习历程+
工作记录+生活日常+编程资料。


我们知道，关联式容器存储的是“键值对”形式的数据，比如：
<"C语言教程", "http://c.biancheng.net/c/">
<"Python教程", "http://c.biancheng.net/python/">
<"Java教程", "http://c.biancheng.net/java/">

如上所示，每行都表示一个键值对，其中第一个元素作为键（key），第二个元素作为值（value）。
注意，基于各个关联式容器存储数据的特点，只有各个键值对中的键和值全部对应相等时，才能使用 set 和 multiset 关联式容器存储，否则就要选用 
map 或者 multimap 关联式容器。

考虑到“键值对”并不是普通类型数据，C++ STL 标准库提供了 pair 类模板，其专门用来将 2 个普通元素 first 和 second（可以是 C++ 基本数据类型、
结构体、类自定的类型）创建成一个新元素<first, second>。通过其构成的元素格式不难看出，使用 pair 类模板来创建“键值对”形式的元素，再合适不过。

注意，pair 类模板定义在<utility>头文件中，所以在使用该类模板之前，需引入此头文件。另外值得一提的是，在 C++ 11 标准之前，pair 类模板中提供
了以下 3 种构造函数：

#1) 默认构造函数，即创建空的 pair 对象
pair();
#2) 直接使用 2 个元素初始化成 pair 对象
pair (const first_type& a, const second_type& b);
#3) 拷贝（复制）构造函数，即借助另一个 pair 对象，创建新的 pair 对象
template<class U, class V> pair (const pair<U,V>& pr);
在 C++ 11 标准中，在引入右值引用的基础上，pair 类模板中又增添了如下 2 个构造函数：
#4) 移动构造函数
template<class U, class V> pair (pair<U,V>&& pr);
#5) 使用右值引用参数，创建 pair 对象
template<class U, class V> pair (U&& a, V&& b);
除此之外，C++ 11 标准中 pair 类模板还新增加了如下一种构造函数：pair (piecewise_construct_t pwc, tuple<Args1...> first_args, 
tuple<Args2...> second_args);

，该构造 pair 类模板的方式很少用到，因此本节不再对其进行详细介绍，感兴趣的读者可自行查阅资料。
下面程序演示了以上几种创建 pair 对象的方法：
#include <iostream>
#include <utility>      // pair
#include <string>       // string
using namespace std;
int main() {
    // 调用构造函数 1，也就是默认构造函数
    pair <string, double> pair1;
    // 调用第 2 种构造函数
    pair <string, string> pair2("STL教程","http://c.biancheng.net/stl/");  
    // 调用拷贝构造函数
    pair <string, string> pair3(pair2);
    //调用移动构造函数
    pair <string, string> pair4(make_pair("C++教程", "http://c.biancheng.net/cplus/"));
    // 调用第 5 种构造函数
    pair <string, string> pair5(string("Python教程"), string("http://c.biancheng.net/python/"));  
   
    cout << "pair1: " << pair1.first << " " << pair1.second << endl;
    cout << "pair2: "<< pair2.first << " " << pair2.second << endl;
    cout << "pair3: " << pair3.first << " " << pair3.second << endl;
    cout << "pair4: " << pair4.first << " " << pair4.second << endl;
    cout << "pair5: " << pair5.first << " " << pair5.second << endl;
    return 0;
}
程序输出结果为：
pair1:  0
pair2: STL教程 http://c.biancheng.net/stl/
pair3: STL教程 http://c.biancheng.net/stl/
pair4: C++教程 http://c.biancheng.net/cplus/
pair5: Python教程 http://c.biancheng.net/python/

上面程序在创建 pair4 对象时，调用了 make_pair() 函数，它也是 <utility> 头文件提供的，其功能是生成一个 pair 对象。因此，当我们将 
make_pair() 函数的返回值（是一个临时对象）作为参数传递给 pair() 构造函数时，其调用的是移动构造函数，而不是拷贝构造函数。

在上面程序的基础上，C++ 11 还允许我们手动为 pair1 对象赋值，比如：
pair1.first = "Java教程";
pair1.second = "http://c.biancheng.net/java/";
cout << "new pair1: " << pair1.first << " " << pair1.second << endl;
执行结果为：
new pair1: Java教程 http://c.biancheng.net/java/

同时，上面程序中 pair4 对象的创建过程，还可以写入如下形式，它们是完全等价的：
pair <string, string> pair4 = make_pair("C++教程", "http://c.biancheng.net/cplus/");
cout << "pair4: " << pair4.first << " " << pair4.second << endl;

<utility>头文件中除了提供创建 pair 对象的方法之外，还为 pair 对象重载了 <、<=、>、>=、==、!= 这 6 的运算符，其运算规则是：对于
进行比较的 2 个 pair 对象，先比较 pair.first 元素的大小，如果相等则继续比较 pair.second 元素的大小。

注意，对于进行比较的 2 个 pair 对象，其对应的键和值的类型比较相同，否则将没有可比性，同时编译器提示没有相匹配的运算符，即找不到
合适的重载运算符。

举个例子：
#include <iostream>
#include <utility>      // pair
#include <string>       // string
using namespace std;
int main() {
    pair <string, int> pair1("STL教程", 20);
    pair <string, int> pair2("C++教程", 20);
    pair <string, int> pair3("C++教程", 30);
    //pair1和pair2的key不同，value相同
    if (pair1 != pair2) {
        cout << "pair != pair2" << endl;
    }
    //pair2和pair3的key相同，value不同
    if (pair2 != pair3) {
        cout << "pair2 != pair3" << endl;
    }
    return 0;
}
程序执行结果为：
pair != pair2
pair2 != pair3


最后需要指出的是，pair类模板还提供有一个 swap() 成员函数，能够互换 2 个 pair 对象的键值对，其操作成功的前提是这 2 个 pair 对象
的键和值的类型要相同。例如：

#include <iostream>
#include <utility>      // pair
#include <string>       // string
using namespace std;
int main() {
    pair <string, int> pair1("pair", 10);                   
    pair <string, int> pair2("pair2", 20);
    //交换 pair1 和 pair2 的键值对
    pair1.swap(pair2);
    cout << "pair1: " << pair1.first << " " << pair1.second << endl;
    cout << "pair2: " << pair2.first << " " << pair2.second << endl;
    return 0;
}
程序执行结果为：
pair1: pair2 20
pair2: pair 10

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业故事+
学习历程+工作记录+生活日常+编程资料。


作为关联式容器的一种，map 容器存储的都是 pair 对象，也就是用 pair 类模板创建的键值对。其中，各个键值对的键和值可以是任意数据类型，
包括 C++ 基本数据类型（int、double 等）、使用结构体或类自定义的类型。通常情况下，map 容器中存储的各个键值对都选用 string 字符串
作为键的类型。

与此同时，在使用 map 容器存储多个键值对时，该容器会自动根据各键值对的键的大小，按照既定的规则进行排序。默认情况下，map 容器选用
std::less<T>排序规则（其中 T 表示键的数据类型），其会根据键的大小对所有键值对做升序排序。当然，根据实际情况的需要，我们可以手动
指定 map 容器的排序规则，既可以选用 STL 标准库中提供的其它排序规则（比如std::greater<T>），也可以自定义排序规则。

关于如何自定义 map 容器的排序规则，后续章节会做详细讲解。

另外需要注意的是，使用 map 容器存储的各个键值对，键的值既不能重复也不能被修改。换句话说，map 容器中存储的各个键值对不仅键的值独一
无二，键的类型也会用 const 修饰，这意味着只要键值对被存储到 map 容器中，其键的值将不能再做任何修改。

前面提到，map 容器存储的都是 pair 类型的键值对元素，更确切的说，该容器存储的都是 pair<const K, T> 类型（其中 K 和 T 分别表示键
和值的数据类型）的键值对元素。

map 容器定义在 <map> 头文件中，并位于 std 命名空间中。因此，如果想使用 map 容器，代码中应包含如下语句：
#include <map>
using namespace std;
注意，第二行代码不是必需的，如果不用，则后续程序中在使用 map 容器时，需手动注明 std 命名空间（强烈建议初学者使用）。

map 容器的模板定义如下：
template < class Key,                                     // 指定键（key）的类型
           class T,                                       // 指定值（value）的类型
           class Compare = less<Key>,                     // 指定排序规则
           class Alloc = allocator<pair<const Key,T> >    // 指定分配器对象的类型
           > class map;
可以看到，map 容器模板有 4 个参数，其中后 2 个参数都设有默认值。大多数场景中，我们只需要设定前 2 个参数的值，有些场景可能会用到第
 3 个参数，但最后一个参数几乎不会用到。创建C++ map容器的几种方法
map 容器的模板类中包含多种构造函数，因此创建 map 容器的方式也有多种，下面就几种常用的创建 map 容器的方法，做一一讲解。

1) 通过调用 map 容器类的默认构造函数，可以创建出一个空的 map 容器，比如：
std::map<std::string, int>myMap;
如果程序中已经默认指定了 std 命令空间，这里可以省略 std::。

通过此方式创建出的 myMap 容器，初始状态下是空的，即没有存储任何键值对。鉴于空 map 容器可以根据需要随时添加新的键值对，因此创建空 
map 容器是比较常用的。

2) 当然在创建 map 容器的同时，也可以进行初始化，比如：
std::map<std::string, int>myMap{ {"C语言教程",10},{"STL教程",20} };
由此，myMap 容器在初始状态下，就包含有 2 个键值对。

再次强调，map 容器中存储的键值对，其本质都是 pair 类模板创建的 pair 对象。因此，下面程序也可以创建出一模一样的 myMap 容器：
std::map<std::string, int>myMap{std::make_pair("C语言教程",10),std::make_pair("STL教程",20)};

3) 除此之外，在某些场景中，可以利用先前已创建好的 map 容器，再创建一个新的 map 容器。例如：
std::map<std::string, int>newMap(myMap);
由此，通过调用 map 容器的拷贝（复制）构造函数，即可成功创建一个和 myMap 完全一样的 newMap 容器。

C++ 11 标准中，还为 map 容器增添了移动构造函数。当有临时的 map 对象作为参数，传递给要初始化的 map 容器时，此时就会调用移动构造函数
。举个例子：

#创建一个会返回临时 map 对象的函数
std::map<std::string,int> disMap() {
    std::map<std::string, int>tempMap{ {"C语言教程",10},{"STL教程",20} };
    return tempMap;
}
//调用 map 类模板的移动构造函数创建 newMap 容器
std::map<std::string, int>newMap(disMap());
注意，无论是调用复制构造函数还是调用拷贝构造函数，都必须保证这 2 个容器的类型完全一致。


4) map 类模板还支持取已建 map 容器中指定区域内的键值对，创建并初始化新的 map 容器。例如：
std::map<std::string, int>myMap{ {"C语言教程",10},{"STL教程",20} };
std::map<std::string, int>newMap(++myMap.begin(), myMap.end());
这里，通过调用 map 容器的双向迭代器，实现了在创建 newMap 容器的同时，将其初始化为包含一个 {"STL教程",20} 键值对的容器。
有关 map 容器迭代器，后续章节会做详细讲解。


5) 当然，在以上几种创建 map 容器的基础上，我们都可以手动修改 map 容器的排序规则。默认情况下，map 容器调用 std::less<T> 规则，
根据容器内各键值对的键的大小，对所有键值对做升序排序。

因此，如下 2 行创建 map 容器的方式，其实是等价的：
std::map<std::string, int>myMap{ {"C语言教程",10},{"STL教程",20} };
std::map<std::string, int, std::less<std::string> >myMap{ {"C语言教程",10},{"STL教程",20} };
以上 2 中创建方式生成的 myMap 容器，其内部键值对排列的顺序为：
<"C语言教程", 10>
<"STL教程", 20>


下面程序手动修改了 myMap 容器的排序规则，令其作降序排序：
std::map<std::string, int, std::greater<std::string> >myMap{ {"C语言教程",10},{"STL教程",20} };
此时，myMap 容器内部键值对排列的顺序为：
<"STL教程", 20>
<"C语言教程", 10>

在某些特定场景中，我们还需要为 map 容器自定义排序规则，此部分知识后续将利用整整一节做重点讲解。

C++ map容器包含的成员方法
表 1 列出了 map 容器提供的常用成员方法以及各自的功能。

表 1 C++ map容器常用成员方法
成员方法	功能
begin()	返回指向容器中第一个（注意，是已排好序的第一个）键值对的双向迭代器。如果 map 容器用 const 限定，则该方法返回的是 
const 类型的双向迭代器。
end()	返回指向容器最后一个元素（注意，是已排好序的最后一个）所在位置后一个位置的双向迭代器，通常和 begin() 结合使用。
如果 map 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
rbegin()	返回指向最后一个（注意，是已排好序的最后一个）元素的反向双向迭代器。如果 map 容器用 const 限定，则该方法返回的是 
const 类型的反向双向迭代器。
rend()	返回指向第一个（注意，是已排好序的第一个）元素所在位置前一个位置的反向双向迭代器。如果 map 容器用 const 限定，
则该方法返回的是 const 类型的反向双向迭代器。
cbegin()	和 begin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的键值对。
cend()	和 end() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的键值对。
crbegin()	和 rbegin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的键值对。
crend()	和 rend() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的键值对。
find(key)	在 map 容器中查找键为 key 的键值对，如果成功找到，则返回指向该键值对的双向迭代器；反之，则返回和 end() 
方法一样的迭代器。另外，如果 map 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
lower_bound(key)	返回一个指向当前 map 容器中第一个大于或等于 key 的键值对的双向迭代器。如果 map 容器用 const 限定，
则该方法返回的是 const 类型的双向迭代器。
upper_bound(key)	返回一个指向当前 map 容器中第一个大于 key 的键值对的迭代器。如果 map 容器用 const 限定，则该方法
返回的是 const 类型的双向迭代器。
equal_range(key)	该方法返回一个 pair 对象（包含 2 个双向迭代器），其中 pair.first 和 lower_bound() 方法的返回值
等价，pair.second 和 upper_bound() 方法的返回值等价。也就是说，该方法将返回一个范围，该范围中包含的键为 key 的键值对
（map 容器键值对唯一，因此该范围最多包含一个键值对）。
empty() 	若容器为空，则返回 true；否则 false。
size()	返回当前 map 容器中存有键值对的个数。
max_size()	返回 map 容器所能容纳键值对的最大个数，不同的操作系统，其返回值亦不相同。
operator[]	map容器重载了 [] 运算符，只要知道 map 容器中某个键值对的键的值，就可以向获取数组中元素那样，通过键直接获
取对应的值。
at(key)	找到 map 容器中 key 键对应的值，如果找不到，该函数会引发 out_of_range 异常。
insert()	向 map 容器中插入键值对。
erase()	删除 map 容器指定位置、指定键（key）值或者指定区域内的键值对。后续章节还会对该方法做重点讲解。
swap()	交换 2 个 map 容器中存储的键值对，这意味着，操作的 2 个键值对的类型必须相同。
clear()	清空 map 容器中所有的键值对，即使 map 容器的 size() 为 0。
emplace()	在当前 map 容器中的指定位置处构造新键值对。其效果和插入键值对一样，但效率更高。
emplace_hint()	在本质上和 emplace() 在 map 容器中构造新键值对的方式是一样的，不同之处在于，使用者必须为该方法提供
一个指示键值对生成位置的迭代器，并作为该方法的第一个参数。
count(key)	在当前 map 容器中，查找键为 key 的键值对的个数并返回。注意，由于 map 容器中各键值对的键的值是唯一的，
因此该函数的返回值最大为 1。

下面的样例演示了表 1 中部分成员方法的用法：
#include <iostream>
#include <map>      // map
#include <string>       // string
using namespace std;
int main() {
    //创建空 map 容器，默认根据个键值对中键的值，对键值对做降序排序
    std::map<std::string, std::string, std::greater<std::string>>myMap;
    //调用 emplace() 方法，直接向 myMap 容器中指定位置构造新键值对
    myMap.emplace("C语言教程","http://c.biancheng.net/c/");
    myMap.emplace("Python教程", "http://c.biancheng.net/python/");
    myMap.emplace("STL教程", "http://c.biancheng.net/stl/");
    //输出当前 myMap 容器存储键值对的个数
    cout << "myMap size==" << myMap.size() << endl;
    //判断当前 myMap 容器是否为空
    if (!myMap.empty()) {
        //借助 myMap 容器迭代器，将该容器的键值对逐个输出
        for (auto i = myMap.begin(); i != myMap.end(); ++i) {
            cout << i->first << " " << i->second << endl;
        }
    }  
    return 0;
}
程序执行结果为：
myMap size==3
STL教程 http://c.biancheng.net/stl/
Python教程 http://c.biancheng.net/python/
C语言教程 http://c.biancheng.net/c/

有关表 1 中其它成员函数的用法，后续章节会做详细详解。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业故事+
学习历程+工作记录+生活日常+编程资料。


无论是前面学习的序列式容器，还是关联式容器，要想实现遍历操作，就必须要用到该类型容器的迭代器。当然，map 容器也不例外。

C++ STL 标准库为 map 容器配备的是双向迭代器（bidirectional iterator）。这意味着，map 容器迭代器只能进行 ++p、p++、--p、p--、*p 
操作，并且迭代器之间只能使用 == 或者 != 运算符进行比较。

值得一提的是，相比序列式容器，map 容器提供了更多的成员方法（如表 1 所示），通过调用它们，我们可以轻松获取具有指定含义的迭代器。

表 1 map 容器迭代器相关成员方法
成员方法	功能
begin()	返回指向容器中第一个（注意，是已排好序的第一个）键值对的双向迭代器。如果 map 容器用 const 限定，则该方法返回的是 const 
类型的双向迭代器。
end()	返回指向容器最后一个元素（注意，是已排好序的最后一个）所在位置后一个位置的双向迭代器，通常和 begin() 结合使用。如果 map 
容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
rbegin()	返回指向最后一个（注意，是已排好序的最后一个）元素的反向双向迭代器。如果 map 容器用 const 限定，则该方法返回的是 
const 类型的反向双向迭代器。
rend() 	返回指向第一个（注意，是已排好序的第一个）元素所在位置前一个位置的反向双向迭代器。如果 map 容器用 const 限定，则该方法
返回的是 const 类型的反向双向迭代器。
cbegin()	和 begin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的键值对。
cend() 	和 end() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的键值对。
crbegin() 	和 rbegin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的键值对。
crend() 	和 rend() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的键值对。
find(key)	在 map 容器中查找键为 key 的键值对，如果成功找到，则返回指向该键值对的双向迭代器；反之，则返回和 end() 方法一样的
迭代器。另外，如果 map 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
lower_bound(key)	返回一个指向当前 map 容器中第一个大于或等于 key 的键值对的双向迭代器。如果 map 容器用 const 限定，则该方法
返回的是 const 类型的双向迭代器。
upper_bound(key) 	返回一个指向当前 map 容器中第一个大于 key 的键值对的迭代器。如果 map 容器用 const 限定，则该方法返回的是 
const 类型的双向迭代器。
equal_range(key)	该方法返回一个 pair 对象（包含 2 个双向迭代器），其中 pair.first 和 lower_bound() 方法的返回值等价，
pair.second 和 upper_bound() 方法的返回值等价。也就是说，该方法将返回一个范围，该范围中包含的键为 key 的键值对（map 容器键值对
唯一，因此该范围最多包含一个键值对）。

表 1 中多数的成员方法，诸如 begin()、end() 等，在学习序列式容器时已经多次使用过，它们的功能如图 2 所示。

C++ STL map部分成员方法示意图
图 2 表 1 部分成员方法的功能示意图
注意，图中 Ei 表示的是 pair 类对象，即键值对。对于 map 容器来说，每个键值对的键的值都必须保证是唯一的。

下面程序以 begin()/end() 组合为例，演示了如何遍历 map 容器：
#include <iostream>
#include <map>      // pair
#include <string>       // string
using namespace std;
int main() {
    //创建并初始化 map 容器
    std::map<std::string, std::string>myMap{ {"STL教程","http://c.biancheng.net/stl/"},{"C语言教程","http://c.biancheng.net/c/"} };
    //调用 begin()/end() 组合，遍历 map 容器
    for (auto iter = myMap.begin(); iter != myMap.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }
    return 0;
}
程序执行结果为：
C语言教程 http://c.biancheng.net/c/
STL教程 http://c.biancheng.net/stl/

读者可自行尝试使用其他组合（如 cbegin()/cend()、 rbegin()/rend() 等）遍历 map 容器。


除此之外，map 类模板中还提供了 find() 成员方法，它能帮我们查找指定 key 值的键值对，如果成功找到，则返回一个指向该键值对的双向迭代器；
反之，其功能和 end() 方法相同。

举个例子：
#include <iostream>
#include <map>      // pair
#include <string>       // string
using namespace std;
int main() {
    //创建并初始化 map 容器
    std::map<std::string, std::string>myMap{ {"STL教程","http://c.biancheng.net/stl/"},
                                             {"C语言教程","http://c.biancheng.net/c/"},
                                             {"Java教程","http://c.biancheng.net/java/"} };
    //查找键为 "Java教程" 的键值对
    auto iter = myMap.find("Java教程");
    //从 iter 开始，遍历 map 容器
    for (; iter != myMap.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }
    return 0;
}
程序执行结果为：
Java教程 http://c.biancheng.net/java/
STL教程 http://c.biancheng.net/stl/


此程序中，创建并初始化的 myMap 容器，默认会根据各键值对中键的值，对各键值对做升序排序，其排序的结果为：
<"C语言教程","http://c.biancheng.net/c/">
<"Java教程","http://c.biancheng.net/java/">
<"STL教程","http://c.biancheng.net/stl/">

在此基础上，通过调用 find() 方法，我们可以得到一个指向键为 "Java教程" 的键值对的迭代器，由此当使用 for 循环从该迭代器出开始遍历时，
就只会遍历到最后 2 个键值对。

同时，map 类模板中还提供有 lower_bound(key) 和 upper_bound(key) 成员方法，它们的功能是类似的，唯一的区别在于：
lower_bound(key) 返回的是指向第一个键不小于 key 的键值对的迭代器；
upper_bound(key) 返回的是指向第一个键大于 key 的键值对的迭代器；

下面程序演示了它们的功能：
#include <iostream>
#include <map>      // pair
#include <string>       // string
using namespace std;
int main() {
    //创建并初始化 map 容器
    std::map<std::string, std::string>myMap{ {"STL教程","http://c.biancheng.net/stl/"},
                                             {"C语言教程","http://c.biancheng.net/c/"},
                                             {"Java教程","http://c.biancheng.net/java/"} };
    //找到第一个键的值不小于 "Java教程" 的键值对
    auto iter = myMap.lower_bound("Java教程");
    cout << "lower：" << iter->first << " " << iter->second << endl;
   
    //找到第一个键的值大于 "Java教程" 的键值对
    iter = myMap.upper_bound("Java教程");
    cout <<"upper：" << iter->first << " " << iter->second << endl;
    return 0;
}
程序执行结果为：
lower：Java教程 http://c.biancheng.net/java/
upper：STL教程 http://c.biancheng.net/stl/

lower_bound(key) 和 upper_bound(key) 更多用于 multimap 容器，在 map 容器中很少用到。


equal_range(key) 成员方法可以看做是 lower_bound(key) 和 upper_bound(key) 的结合体，该方法会返回一个 pair 对象，其中的 2 
个元素都是迭代器类型，其中 pair.first 实际上就是 lower_bound(key) 的返回值，而 pair.second 则等同于 upper_bound(key) 的返回值。

显然，equal_range(key) 成员方法表示的一个范围，位于此范围中的键值对，其键的值都为 key。举个例子：
#include <iostream>
#include <utility>  //pair
#include <map>      // map
#include <string>       // string
using namespace std;
int main() {
    //创建并初始化 map 容器
    std::map<string, string>myMap{ {"STL教程","http://c.biancheng.net/stl/"},
                                   {"C语言教程","http://c.biancheng.net/c/"},
                                   {"Java教程","http://c.biancheng.net/java/"} };
    //创建一个 pair 对象，来接收 equal_range() 的返回值
    pair <std::map<string, string>::iterator, std::map<string, string>::iterator> myPair = myMap.equal_range("C语言教程");
    //通过遍历，输出 myPair 指定范围内的键值对
    for (auto iter = myPair.first; iter != myPair.second; ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }
    return 0;
}
程序执行结果为：
C语言教程 http://c.biancheng.net/c/

和 lower_bound(key)、upper_bound(key) 一样，该方法也更常用于 multimap 容器，因为 map 容器中各键值对的键的值都是唯一的，因此通过 
map 容器调用此方法，其返回的范围内最多也只有 1 个键值对。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业故事+
学习历程+工作记录+生活日常+编程资料。


我们知道，map 容器中存储的都是 pair 类型的键值对，但几乎在所有使用 map 容器的场景中，经常要做的不是找到指定的 pair 对象（键值对），
而是从该容器中找到某个键对应的值。注意，使用 map 容器存储的各个键值对，其键的值都是唯一的，因此指定键对应的值最多有 1 个。

庆幸的是，map 容器的类模板中提供了以下 2 种方法，可直接获取 map 容器指定键对应的值。

1) map 类模板中对[ ]运算符进行了重载，这意味着，类似于借助数组下标可以直接访问数组中元素，通过指定的键，我们可以轻松获取 map 
容器中该键对应的值。

举个例子：
#include <iostream>
#include <map>      // map
#include <string>   // string
using namespace std;
int main() {
    //创建并初始化 map 容器
    std::map<std::string, std::string>myMap{ {"STL教程","http://c.biancheng.net/stl/"},
                                             {"C语言教程","http://c.biancheng.net/c/"},
                                             {"Java教程","http://c.biancheng.net/java/"} };
    string cValue = myMap["C语言教程"];
    cout << cValue << endl;
    return 0;
}
程序执行结果为：
http://c.biancheng.net/c/

可以看到，在第 11 行代码中，通过指定键的值为 "C语言教程"，借助重载的 [ ] 运算符，就可以在 myMap 容器中直接找到该键对应的值。

注意，只有当 map 容器中确实存有包含该指定键的键值对，借助重载的 [ ] 运算符才能成功获取该键对应的值；反之，若当前 map 容器中没有包含
该指定键的键值对，则此时使用 [ ] 运算符将不再是访问容器中的元素，而变成了向该 map 容器中增添一个键值对。其中，该键值对的键用 [ ] 
运算符中指定的键，其对应的值取决于 map 容器规定键值对中值的数据类型，如果是基本数据类型，则值为 0；如果是 string 类型，其值为 ""，
即空字符串（即使用该类型的默认值作为键值对的值）。

举个例子：
#include <iostream>
#include <map>      // map
#include <string>   // string
using namespace std;
int main() {
    //创建空 map 容器
    std::map<std::string, int>myMap;
    int cValue = myMap["C语言教程"];
    for (auto i = myMap.begin(); i != myMap.end(); ++i) {
        cout << i->first << " "<< i->second << endl;
    }
    return 0;
}
程序执行结果为：
C语言教程 0

显然，对于空的 myMap 容器来说，其内部没有以 "C语言教程" 为键的键值对，这种情况下如果使用 [ ] 运算符获取该键对应的值，其功能就转
变成了向该 myMap 容器中添加一个<"C语言教程",0>键值对（由于 myMap 容器规定各个键值对的值的类型为 int，该类型的默认值为 0）。

实际上，[ ] 运算符确实有“为 map 容器添加新键值对”的功能，但前提是要保证新添加键值对的键和当前 map 容器中已存储的键值对的键都不一样。
例如：

#include <iostream>
#include <map>      // map
#include <string>   // string
using namespace std;
int main() {
    //创建空 map 容器
    std::map<string, string>myMap;
    myMap["STL教程"]="http://c.biancheng.net/java/";
    myMap["Python教程"] = "http://c.biancheng.net/python/";
    myMap["STL教程"] = "http://c.biancheng.net/stl/";
    for (auto i = myMap.begin(); i != myMap.end(); ++i) {
        cout << i->first << " " << i->second << endl;
    }
    return 0;
}
程序执行结果为：
Python教程 http://c.biancheng.net/python/
STL教程 http://c.biancheng.net/stl/

注意，程序中第 9 行代码已经为 map 容器添加了一个以 "STL教程" 作为键的键值对，则第 11 行代码的作用就变成了修改该键对应的值，而不再
是为 map 容器添加新键值对。

2) 除了借助 [ ] 运算符获取 map 容器中指定键对应的值，还可以使用 at() 成员方法。和前一种方法相比，at() 成员方法也需要根据指定的键，
才能从容器中找到该键对应的值；不同之处在于，如果在当前容器中查找失败，该方法不会向容器中添加新的键值对，而是直接抛出 out_of_range 
异常。

举个例子：
#include <iostream>
#include <map>      // map
#include <string>   // string
using namespace std;
int main() {
    //创建并初始化 map 容器
    std::map<std::string, std::string>myMap{ {"STL教程","http://c.biancheng.net/stl/"},
                                             {"C语言教程","http://c.biancheng.net/c/"},
                                             {"Java教程","http://c.biancheng.net/java/"} };
    cout << myMap.at("C语言教程") << endl;
    //下面一行代码会引发 out_of_range 异常
    //cout << myMap.at("Python教程") << endl;
    return 0;
}
程序执行结果为：
http://c.biancheng.net/c/

程序第 12 行代码处，通过 myMap 容器调用  at() 成员方法，可以成功找到键为 "C语言教程" 的键值对，并返回该键对应的值；而第 14 行代码，
由于当前 myMap 容器中没有以 "Python教程" 为键的键值对，会导致 at() 成员方法查找失败，并抛出 out_of_range 异常。

除了可以直接获取指定键对应的值之外，还可以借助 find() 成员方法间接实现此目的。和以上 2 种方式不同的是，该方法返回的是一个迭代器，
即如果查找成功，该迭代器指向查找到的键值对；反之，则指向 map 容器最后一个键值对之后的位置（和 end() 成功方法返回的迭代器一样）。

举个例子：
#include <iostream>
#include <map>      // map
#include <string>   // string
using namespace std;
int main() {
    //创建并初始化 map 容器
    std::map<std::string, std::string>myMap{ {"STL教程","http://c.biancheng.net/stl/"},
                                             {"C语言教程","http://c.biancheng.net/c/"},
                                             {"Java教程","http://c.biancheng.net/java/"} };
    map< std::string, std::string >::iterator myIter = myMap.find("C语言教程");
    cout << myIter->first << " " << myIter->second << endl;
    return 0;
}
程序执行结果为：
C语言教程 http://c.biancheng.net/c/

注意，此程序中如果 find() 查找失败，会导致第 13 行代码运行出错。因为当 find() 方法查找失败时，其返回的迭代器指向的是容器中最后一个
键值对之后的位置，即不指向任何有意义的键值对，也就没有所谓的 first 和 second 成员了。

如果以上方法都不适用，我们还可以遍历整个 map 容器，找到包含指定键的键值对，进而获取该键对应的值。比如：
#include <iostream>
#include <map>      // map
#include <string>   // string
using namespace std;
int main() {
    //创建并初始化 map 容器
    std::map<std::string, std::string>myMap{ {"STL教程","http://c.biancheng.net/stl/"},
                                             {"C语言教程","http://c.biancheng.net/c/"},
                                             {"Java教程","http://c.biancheng.net/java/"} };
    for (auto iter = myMap.begin(); iter != myMap.end(); ++iter) {
        //调用 string 类的 compare() 方法，找到一个键和指定字符串相同的键值对
        if (!iter->first.compare("C语言教程")) {
            cout << iter->first << " " << iter->second << endl;
        }
    }
    return 0;
}
程序执行结果为：
C语言教程 http://c.biancheng.net/c/

本节所介绍的几种方法中，仅从“在 map 容器存储的键值对中，获取指定键对应的值”的角度出发，更推荐使用 at() 成员方法，因为该方法既简单又安全。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业故事+学习历程+
工作记录+生活日常+编程资料。


前面讲过，C++ STL map 类模板中对[ ]运算符进行了重载，即根据使用场景的不同，借助[ ]运算符可以实现不同的操作。举个例子：
#include <iostream>
#include <map>  //map
#include <string> //string
using namespace std;
int main()
{
    std::map<string, string> mymap{ {"STL教程","http://c.biancheng.net/java/"} };
    //获取已存储键值对中，指定键对应的值
    cout << mymap["STL教程"] << endl;
    //向 map 容器添加新键值对
    mymap["Python教程"] = "http://c.biancheng.net/python/";
    //修改 map 容器已存储键值对中，指定键对应的值
    mymap["STL教程"] = "http://c.biancheng.net/stl/";
    for (auto iter = mymap.begin(); iter != mymap.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }
   
    return 0;
}
程序执行结果为：
http://c.biancheng.net/java/
Python教程 http://c.biancheng.net/python/
STL教程 http://c.biancheng.net/stl/

可以看到，当操作对象为 map 容器中已存储的键值对时，则借助 [ ] 运算符，既可以获取指定键对应的值，还能对指定键对应的值进行修改；反之，
若 map 容器内部没有存储以 [ ] 运算符内指定数据为键的键值对，则使用 [ ] 运算符会向当前 map 容器中添加一个新的键值对。

实际上，除了使用 [ ] 运算符实现向 map 容器中添加新键值对外，map 类模板中还提供有 insert() 成员方法，该方法专门用来向 map 容器中插入
新的键值对。注意，这里所谓的“插入”，指的是 insert() 方法可以将新的键值对插入到 map 容器中的指定位置，但这与 map 容器会自动对存储的键值
对进行排序并不冲突。当使用 insert() 方法向 map 容器的指定位置插入新键值对时，其底层会先将新键值对插入到容器的指定位置，如果其破坏了 
map 容器的有序性，该容器会对新键值对的位置进行调整。

自 C++ 11 标准后，insert() 成员方法的用法大致有以下 4 种。

1) 无需指定插入位置，直接将键值对添加到 map 容器中。insert() 方法的语法格式有以下 2 种：
//1、引用传递一个键值对
pair<iterator,bool> insert (const value_type& val);
//2、以右值引用的方式传递键值对
template <class P>
    pair<iterator,bool> insert (P&& val);

其中，val 参数表示键值对变量，同时该方法会返回一个 pair 对象，其中 pair.first 表示一个迭代器，pair.second 为一个 bool 类型变量：
如果成功插入 val，则该迭代器指向新插入的 val，bool 值为 true；
如果插入 val 失败，则表明当前 map 容器中存有和 val 的键相同的键值对（用 p 表示），此时返回的迭代器指向 p，bool 值为 false。
以上 2 种语法格式的区别在于传递参数的方式不同，即无论是局部定义的键值对变量还是全局定义的键值对变量，都采用普通引用传递的方式；而对于
临时的键值对变量，则以右值引用的方式传参。有关右值引用，可阅读《C++右值引用》一文做详细了解。

举个例子：
#include <iostream>
#include <map>  //map
#include <string> //string
using namespace std;
int main()
{
    //创建一个空 map 容器
    std::map<string, string> mymap;
   
    //创建一个真实存在的键值对变量
    std::pair<string, string> STL = { "STL教程","http://c.biancheng.net/stl/" };
   
    //创建一个接收 insert() 方法返回值的 pair 对象
    std::pair<std::map<string, string>::iterator, bool> ret;
   
    //插入 STL，由于 STL 并不是临时变量，因此会以第一种方式传参
    ret = mymap.insert(STL);
    cout << "ret.iter = <{" << ret.first->first << ", " << ret.first->second << "}, " << ret.second << ">" << endl;
    //以右值引用的方式传递临时的键值对变量
    ret = mymap.insert({ "C语言教程","http://c.biancheng.net/c/" });
    cout << "ret.iter = <{" << ret.first->first << ", " << ret.first->second << "}, " << ret.second << ">" << endl;
    //插入失败样例
    ret = mymap.insert({ "STL教程","http://c.biancheng.net/java/" });
    cout << "ret.iter = <{" << ret.first->first << ", " << ret.first->second << "}, " << ret.second << ">" << endl;
    return 0;
}
程序执行结果为：
ret.iter = <{STL教程, http://c.biancheng.net/stl/}, 1>
ret.iter = <{C语言教程, http://c.biancheng.net/c/}, 1>
ret.iter = <{STL教程, http://c.biancheng.net/stl/}, 0>

从执行结果中不难看出，程序中共执行了 3 次插入操作，其中成功了 2 次，失败了 1 次：
对于插入成功的 insert() 方法，其返回的 pair 对象中包含一个指向新插入键值对的迭代器和值为 1 的 bool 变量
对于插入失败的 insert() 方法，同样会返回一个 pair 对象，其中包含一个指向 map 容器中键为 "STL教程" 的键值对和值为 0 的 bool 变量。

另外，在程序中的第 21 行代码，还可以使用如下 2 种方式创建临时的键值对变量，它们是等价的：
//调用 pair 类模板的构造函数
ret = mymap.insert(pair<string,string>{ "C语言教程","http://c.biancheng.net/c/" });
//调用 make_pair() 函数
ret = mymap.insert(make_pair("C语言教程", "http://c.biancheng.net/c/"));

2) 除此之外，insert() 方法还支持向 map 容器的指定位置插入新键值对，该方法的语法格式如下：
//以普通引用的方式传递 val 参数
iterator insert (const_iterator position, const value_type& val);
//以右值引用的方式传递 val 键值对参数
template <class P>
    iterator insert (const_iterator position, P&& val);

其中 val 为要插入的键值对变量。注意，和第 1 种方式的语法格式不同，这里 insert() 方法返回的是迭代器，而不再是 pair 对象：
如果插入成功，insert() 方法会返回一个指向 map 容器中已插入键值对的迭代器；
如果插入失败，insert() 方法同样会返回一个迭代器，该迭代器指向 map 容器中和 val 具有相同键的那个键值对。

举个例子：
#include <iostream>
#include <map>  //map
#include <string> //string
using namespace std;
int main()
{
    //创建一个空 map 容器
    std::map<string, string> mymap;
   
    //创建一个真实存在的键值对变量
    std::pair<string, string> STL = { "STL教程","http://c.biancheng.net/stl/" };
    //指定要插入的位置
    std::map<string, string>::iterator it = mymap.begin();
    //向 it 位置以普通引用的方式插入 STL
    auto iter1 = mymap.insert(it, STL);
    cout << iter1->first << " " << iter1->second << endl;
    //向 it 位置以右值引用的方式插入临时键值对
    auto iter2 = mymap.insert(it, std::pair<string, string>("C语言教程", "http://c.biancheng.net/c/"));
    cout << iter2->first << " " << iter2->second << endl;
    //插入失败样例
    auto iter3 = mymap.insert(it, std::pair<string, string>("STL教程", "http://c.biancheng.net/java/"));
    cout << iter3->first << " " << iter3->second << endl;
    return 0;
}
程序执行结果为：
STL教程 http://c.biancheng.net/stl/
C语言教程 http://c.biancheng.net/c/
STL教程 http://c.biancheng.net/stl/

再次强调，即便指定了新键值对的插入位置，map 容器仍会对存储的键值对进行排序。也可以说，决定新插入键值对位于 map 容器中位置的，
不是 insert() 方法中传入的迭代器，而是新键值对中键的值。

3) insert() 方法还支持向当前 map 容器中插入其它 map 容器指定区域内的所有键值对，该方法的语法格式如下：
template <class InputIterator>
  void insert (InputIterator first, InputIterator last);

其中 first 和 last 都是迭代器，它们的组合<first,last>可以表示某 map 容器中的指定区域。

举个例子：
#include <iostream>
#include <map>  //map
#include <string> //string
using namespace std;
int main()
{
    //创建并初始化 map 容器
    std::map<std::string, std::string>mymap{ {"STL教程","http://c.biancheng.net/stl/"},
                                                {"C语言教程","http://c.biancheng.net/c/"},
                                                {"Java教程","http://c.biancheng.net/java/"} };
    //创建一个空 map 容器
    std::map<std::string, std::string>copymap;
    //指定插入区域
    std::map<string, string>::iterator first = ++mymap.begin();
    std::map<string, string>::iterator last = mymap.end();
    //将<first,last>区域内的键值对插入到 copymap 中
    copymap.insert(first, last);
    //遍历输出 copymap 容器中的键值对
    for (auto iter = copymap.begin(); iter != copymap.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }
    return 0;
}
程序执行结果为：
Java教程 http://c.biancheng.net/java/
STL教程 http://c.biancheng.net/stl/

此程序中，<first,last> 指定的区域是从 mumap 容器第 2 个键值对开始，之后所有的键值对，所以 copymap 容器中包含有 2 个键值对。

4) 除了以上一种格式外，insert() 方法还允许一次向 map 容器中插入多个键值对，其语法格式为：
void insert ({val1, val2, ...});

其中，vali 都表示的是键值对变量。

举个例子：
#include <iostream>
#include <map>  //map
#include <string> //string
using namespace std;
int main()
{
    //创建空的 map 容器
    std::map<std::string, std::string>mymap;
    //向 mymap 容器中添加 3 个键值对
    mymap.insert({ {"STL教程", "http://c.biancheng.net/stl/"},
                   { "C语言教程","http://c.biancheng.net/c/" },
                   { "Java教程","http://c.biancheng.net/java/" } });
    for (auto iter = mymap.begin(); iter != mymap.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }
    return 0;
}
程序执行结果为：
C语言教程 http://c.biancheng.net/c/
Java教程 http://c.biancheng.net/java/
STL教程 http://c.biancheng.net/stl/

值得一提的是，除了 insert() 方法，map 类模板还提供 emplace() 和 emplace_hint() 方法，它们也可以完成向 map 容器中插入键值对
的操作，且效率还会 insert() 方法高。关于这 2 个方法，会在下一节做详细介绍。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业故事+
学习历程+工作记录+生活日常+编程资料。


通过前面的学习我们知道，map 容器模板类中提供有 operator[ ] 和 insert() 这 2 个成员方法，而值得一提的是，这 2 个方法具有相同的
功能，它们既可以实现向 map 容器中添加新的键值对元素，也可以实现更新（修改）map 容器已存储键值对的值。

举个例子（程序一）：
#include <iostream>
#include <map>  //map
#include <string> //string
using namespace std;
int main()
{
    std::map<string, string> mymap;
    //借用 operator[] 添加新键值对
    mymap["STL教程"] = "http://c.biancheng.net/java/";
    cout << "old mymap：" << mymap["STL教程"] << endl;
    //借用 operator[] 更新某个键对应的值
    mymap["STL教程"] = "http://c.biancheng.net/stl/";
    cout << "new mymap：" << mymap["STL教程"] << endl;
    //借用insert()添加新键值对
    std::pair<string, string> STL = { "Java教程","http://c.biancheng.net/python/" };
    std::pair<std::map<string, string>::iterator, bool> ret;
    ret = mymap.insert(STL);
    cout << "old ret.iter = <{" << ret.first->first << ", " << ret.first->second << "}, " << ret.second << ">" << endl;
    //借用 insert() 更新键值对
    mymap.insert(STL).first->second = "http://c.biancheng.net/java/";
    cout << "new ret.iter = <" << ret.first->first << ", " << ret.first->second << ">" << endl;
    return 0;
}
程序执行结果为：
old mymap：http://c.biancheng.net/java/
new mymap：http://c.biancheng.net/stl/
old ret.iter = <{Java教程, http://c.biancheng.net/python/}, 1>
new ret.iter = <Java教程, http://c.biancheng.net/java/>

有关程序中 operator[ ] 和 insert() 成员方法的具体用法，读者可翻阅前面的文章做详细了解，这里不再做过多解释。

显然，map 模板类中 operator[ ] 和 insert() 的功能发生了重叠，这就产生了一个问题，谁的执行效率更高呢？

总的来说，读者可记住这样一条结论：当实现“向 map 容器中添加新键值对元素”的操作时，insert() 成员方法的执行效率更高；而在实现“更新 
map 容器指定键值对的值”的操作时，operator[ ] 的效率更高。

至于为什么，有兴趣的读者可继续往下阅读。
向map容器中增添元素，insert()效率更高
首先解释一下，为什么实现向 map 容器中添加新键值对元素，insert() 方法的执行效率比 operator[ ] 更高？回顾程序一中，如下语句完成了
向空 mymap 容器添加新的键值对元素：

mymap["STL教程"] = "http://c.biancheng.net/java/";
此行代码中，mymap["STL教程"] 实际上是 mymap.operator[ ](“STL教程”) 的缩写（底层调用的 operator[ ] 方法），该方法会返回一个指向 
“STL教程” 对应的 value 值的引用。

但需要注意的是，由于此时 mymap 容器是空的，并没有 "STL教程" 对应的 value 值。这种情况下，operator[ ] 方法会默认构造一个 string 
对象，并将其作为 "STL教程" 对应的 value 值，然后返回一个指向此 string 对象的引用。在此基础上，代码还会将 "http://c.biancheng.net.java/" 
赋值给这个 string 对象。

也就是说，上面这行代码的执行流程，可以等效为如下程序：
typedef map<string, string> mstr;
//创建要添加的默认键值对元素
pair<mstr::iterator, bool>res = mymap.insert(mstr::value_type("STL教程", string()));
//将新键值对的值赋值为指定的值
res.first->second = "http://c.biancheng.net/java/";
注意，这里的 value_type(K,T) 指的是 map 容器中存储元素的类型，其实际上就等同于 pair<K,T>。

可以看到，使用 operator[ ] 添加新键值对元素的流程是，先构造一个有默认值的键值对，然后再为其 value 赋值。

那么，为什么不直接构造一个要添加的键值对元素呢，比如：
mymap.insert(mstr::value_type("STL教程", "http://c.biancheng.net/java/"));
此行代码和上面程序的执行效果完全相同，但它省略了创建临时 string 对象的过程以及析构该对象的过程，同时还省略了调用 string 类重载的赋值运算符。
由于可见，同样是完成向 map 容器添加新键值对，insert() 方法比 operator[ ] 的执行效率更高。

更新map容器中的键值对，operator[]效率更高
仍以程序一中的代码为例，如下分别是 operator[ ] 和 insert() 实现更新 mymap 容器中指定键对应的值的代码：
//operator[]
mymap["STL教程"] = "http://c.biancheng.net/stl/";
//insert()
std::pair<string, string> STL = { "Java教程","http://c.biancheng.net/python/" };
mymap.insert(STL).first->second = "http://c.biancheng.net/java/";
仅仅从语法形式本身来考虑，或许已经促使很多读者选择 operator[ ] 了。接下来，我们再从执行效率的角度对比以上 2 种实现方式。

从上面代码可以看到，insert() 方法在进行更新操作之前，需要有一个 pair 类型（也就是 map::value_type 类型）元素做参数。这意味着，该方法要多
构造一个 pair 对象（附带要构造 2 个 string 对象），并且事后还要析构此 pair 对象（附带 2 个 string 对象的析构）。

而和 insert() 方法相比，operator[ ] 就不需要使用 pair 对象，自然不需要构造（并析构）任何 pair 对象或者 string 对象。因此，对于更新已经
存储在 map 容器中键值对的值，应优先使用 operator[ ] 方法。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业故事+学习历程+
工作记录+生活日常+编程资料。


学习 map insert() 方法时提到，C++ STL map 类模板中还提供了 emplace() 和 emplace_hint() 成员函数，也可以实现向 map 容器中插入新的键值对。
本节就来讲解这 2 个成员方法的用法。

值得一提的是，实现相同的插入操作，无论是用 emplace() 还是 emplace_hont()，都比 insert() 方法的效率高（后续章节会详细讲解）。

和 insert() 方法相比，emplace() 和 emplace_hint() 方法的使用要简单很多，因为它们各自只有一种语法格式。其中，emplace() 方法的语法格式如下：
template <class... Args>
  pair<iterator,bool> emplace (Args&&... args);

参数 (Args&&... args) 指的是，这里只需要将创建新键值对所需的数据作为参数直接传入即可，此方法可以自行利用这些数据构建出指定的键值对。另外，
该方法的返回值也是一个 pair 对象，其中 pair.first 为一个迭代器，pair.second 为一个 bool 类型变量：

当该方法将键值对成功插入到 map 容器中时，其返回的迭代器指向该新插入的键值对，同时 bool 变量的值为 true；
当插入失败时，则表明 map 容器中存在具有相同键的键值对，此时返回的迭代器指向此具有相同键的键值对，同时 bool 变量的值为 false。

下面程序演示 emplace() 方法的具体用法：
#include <iostream>
#include <map>  //map
#include <string> //string
using namespace std;
int main()
{
    //创建并初始化 map 容器
    std::map<string, string>mymap;
    //插入键值对
    pair<map<string, string>::iterator, bool> ret = mymap.emplace("STL教程", "http://c.biancheng.net/stl/");
    cout << "1、ret.iter = <{" << ret.first->first << ", " << ret.first->second << "}, " << ret.second << ">" << endl;
    //插入新键值对
    ret = mymap.emplace("C语言教程", "http://c.biancheng.net/c/");
    cout << "2、ret.iter = <{" << ret.first->first << ", " << ret.first->second << "}, " << ret.second << ">" << endl;
    //失败插入的样例
    ret = mymap.emplace("STL教程", "http://c.biancheng.net/java/");
    cout << "3、ret.iter = <{" << ret.first->first << ", " << ret.first->second << "}, " << ret.second << ">" << endl;
    return 0;
}
程序执行结果为：
1、ret.iter = <{STL教程, http://c.biancheng.net/stl/}, 1>
2、ret.iter = <{C语言教程, http://c.biancheng.net/c/}, 1>
3、ret.iter = <{STL教程, http://c.biancheng.net/stl/}, 0>

可以看到，程序中共执行了 3 次向 map 容器插入键值对的操作，其中前 2 次都成功了，第 3 次由于要插入的键值对的键和 map 容器中已存在的键值对
的键相同，因此插入失败。

emplace_hint() 方法的功能和 emplace() 类似，其语法格式如下：
template <class... Args>
  iterator emplace_hint (const_iterator position, Args&&... args);

显然和 emplace() 语法格式相比，有以下 2 点不同：
该方法不仅要传入创建键值对所需要的数据，还需要传入一个迭代器作为第一个参数，指明要插入的位置（新键值对键会插入到该迭代器指向的键值对的前面）；
该方法的返回值是一个迭代器，而不再是 pair 对象。当成功插入新键值对时，返回的迭代器指向新插入的键值对；反之，如果插入失败，则表明 map 容器中
存有相同键的键值对，返回的迭代器就指向这个键值对。

下面程序演示 emplace_hint() 方法的用法：
#include <iostream>
#include <map>  //map
#include <string> //string
using namespace std;
int main()
{
    //创建并初始化 map 容器
    std::map<string, string>mymap;
    //指定在 map 容器插入键值对
    map<string, string>::iterator iter = mymap.emplace_hint(mymap.begin(),"STL教程", "http://c.biancheng.net/stl/");
    cout << iter->first << " " << iter->second << endl;
    iter = mymap.emplace_hint(mymap.begin(), "C语言教程", "http://c.biancheng.net/c/");
    cout << iter->first << " " << iter->second << endl;
    //插入失败样例
    iter = mymap.emplace_hint(mymap.begin(), "STL教程", "http://c.biancheng.net/java/");
    cout << iter->first << " " << iter->second << endl;
    return 0;
}
程序执行结果为：
STL教程 http://c.biancheng.net/stl/
C语言教程 http://c.biancheng.net/c/
STL教程 http://c.biancheng.net/stl/

注意，和 insert() 方法一样，虽然 emplace_hint() 方法指定了插入键值对的位置，但 map 容器为了保持存储键值对的有序状态，可能会移动其位置。
那么，为什么 emplace() 和 emplace_hint() 方法的执行效率，比 insert() 高呢？下一节会做详细解释。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业故事+学习历程+
工作记录+生活日常+编程资料。


上一节在学习 C++STL map 容器的 emplace() 和 emplace_hint() 的基本用法时，还遗留了一个问题，即为什么 emplace() 和 emplace_hint() 
的执行效率会比 insert() 高？

原因很简单，它们向 map 容器插入键值对时，底层的实现方式不同：
使用 insert() 向 map 容器中插入键值对的过程是，先创建该键值对，然后再将该键值对复制或者移动到 map 容器中的指定位置；
使用 emplace() 或 emplace_hint() 插入键值对的过程是，直接在 map 容器中的指定位置构造该键值对。

也就是说，向 map 容器中插入键值对时，emplace() 和 emplace_hint() 方法都省略了移动键值对的过程，因此执行效率更高。下面程序提供了有利
的证明：

#include <iostream>
#include <map>  //map
#include <string> //string
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
private:
    int num;
};
int main()
{
    //创建空 map 容器
    std::map<std::string, testDemo>mymap;
    cout << "insert():" << endl;
    mymap.insert({ "http://c.biancheng.net/stl/", testDemo(1) });
   
    cout << "emplace():" << endl;
    mymap.emplace( "http://c.biancheng.net/stl/:", 1);
    cout << "emplace_hint():" << endl;
    mymap.emplace_hint(mymap.begin(), "http://c.biancheng.net/stl/", 1);
    return 0;
}
程序输出结果为：
insert():
调用构造函数
调用移动构造函数
调用移动构造函数
emplace():
调用构造函数
emplace_hint():
调用构造函数

分析一下这个程序。首先，我们创建了一个存储 <string,tempDemo> 类型键值对的空 map 容器，接下来分别用 insert()、emplace() 和 
emplace_hint() 方法向该 map 容器中插入相同的键值对。

从输出结果可以看出，在使用 insert() 方法向 map 容器插入键值对时，整个插入过程调用了 1 次 tempDemo 类的构造函数，同时还调用了 
2 次移动构造函数。实际上，程序第 28 行代码底层的执行过程，可以分解为以下 3 步：
//构造类对象
testDemo val = testDemo(1); //调用 1 次构造函数
//构造键值对
auto pai = make_pair("http://c.biancheng.net/stl/", val); //调用 1 次移动构造函数
//完成插入操作
mymap.insert(pai); //调用 1 次移动构造函数
而完成同样的插入操作，emplace() 和 emplace_hint() 方法都只调用了 1 次构造函数，这足以证明，这 2 个方法是在 map 容器内部直接
构造的键值对。
因此，在实现向 map 容器中插入键值对时，应优先考虑使用 emplace() 或者 emplace_hint()。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业故事+
学习历程+工作记录+生活日常+编程资料。

*/

using namespace std;
static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();

// solution
void myMapPrint(std::pair<string, int> element) {
    cout << element.first << " " << element.second << endl;
}
void myMapPrint2(std::pair<char, double> element) {
    cout << element.first << " " << element.second << endl;
}
void myMapPrint3(std::pair<string, double> element) {
    cout << element.first << " " << element.second << endl;
}

// main
int main() {

    // constructor, initialized at the beginning or by std::makr_pair()
    map<string, int> myMap1 = {{"Book", 4}, {"Desktop", 3}, {"Laptop", 1}, {"Table", 2}};
    map<string, int> myMap2 = {{"Breakfast", 1}, {"Lunch", 2}, {"Dinner", 3}};

    // insert after constructor
    map<string, double> myMap3;
    myMap3.insert(std::make_pair("Student1", 99.9));
    myMap3.insert(std::make_pair("Student2", 65.4));
    myMap3.insert(std::make_pair("Student3", 35.7));
    map<string, double> myMap6;

    // copy constructor
    map<string, double> myMap4 = myMap3;

    // character constructor
    map<char, double> myMap5 = {{'A', 0.1}, {'C', 0.3}, {'E', 0.5}};

    // at(), return an element with range check
    // STL: Returns a reference to the mapped value of the element with key equivalent to key. 
    // If no such element exists, an exception of type std::out_of_range is thrown.
    auto item1 = myMap1.at("Book");
    cout << "The number of Book by at() is " << item1 << endl;

    // operator[], access element by operator like array, but there is no range check
    // STL: Returns a reference to the value that is mapped to a key equivalent to key, performing an insertion if such key does not already exist.
    auto item2 = myMap1["Book"];
    cout << "The number of Book by operator is " << item2 << endl;

    // operator[] has another feature that will insert new element by this operator way
    // as there is no value specified, the default value will be 0 assigned to "Bag"
    auto item3 = myMap1["Bag"];
    cout << "The size of myMap1 now after Bag is " << myMap1.size() << endl;
    for_each(myMap1.begin(), myMap1.end(), myMapPrint);

    // what if we add another not existed one? This will be OK as "key" of map is different, even the default value is 0
    // the sorting of map is based on given key, so if all values are 0 in this map, this is like a set, except map will do the sorting
    // automatically based on key, while set will not do it
    // Output:
    // Bag 0
    // Book 4
    // Desktop 3
    // Laptop 1
    // Table 2
    // Watch 0
    auto item4 = myMap1["Watch"];
    cout << "The size of myMap1 now after Watch is " << myMap1.size() << endl;
    for_each(myMap1.begin(), myMap1.end(), myMapPrint);

    // begin()/end()/cbegin()/cend(), iterator, in general in map, we will NOT modify key as it will cause unnecessary re-sorting
    // so we can use cbegin()/cend() most of time
    cout << "Items inside myMap2 are:" << endl;
    for (auto item5 = myMap2.cbegin(); item5 !=myMap2.end(); item5++) {
        cout << "  " << item5->first << " " << item5->second << endl;
    }

    // empty(), check if the given map is empty or not, use std::boolalpha/std::noboolalpha to change 0/1 to false/true
    // STL: Checks if the container has no elements, i.e. whether begin() == end()
    cout << "myMap3 is empty? " << std::boolalpha << myMap3.empty() << endl;
    cout << "myMap3 is empty? " << std::noboolalpha << myMap3.empty() << endl;

    // size()/max_size(), return current size of map (number of elements), or max size that this OS can handle
    // STL: Returns the number of elements in the container, i.e. std::distance(begin(), end())
    // STL: Returns the maximum number of elements the container is able to hold due to system or library implementation limitations, 
    // i.e. std::distance(begin(), end()) for the largest container.
    cout << "myMap4 size is " << myMap4.size() << endl;
    cout << "myMap4 max size is " << myMap4.max_size() << endl;

    // clear(), erase all elements in the map
    // STL: Erases all elements from the container. After this call, size() returns zero. Invalidates any references, pointers, 
    // or iterators referring to contained elements. Any past-the-end iterator remains valid.
    cout << "myMap4 size now is " << myMap4.size() << " before clear() call" << endl;
    myMap4.clear();
    cout << "myMap4 size now is " << myMap4.size() << " after clear() call" << endl;

    // insert(), insert a new element into map, based on its pair of (key, value)
    // STL: Inserts element(s) into the container, if the container doesn't already contain an element with an equivalent key.
    // 1-3) Inserts value. The overload (2) is equivalent to emplace(std::forward<P>(value)) and only participates in overload resolution 
    // if std::is_constructible<value_type, P&&>::value == true.
    // 4-6) Inserts value in the position as close as possible, just prior(since C++11), to hint. The overload (5) is equivalent to 
    // emplace_hint(hint, std::forward<P>(value)) and only participates in overload resolution if std::is_constructible<value_type, P&&>::value == true.
    // 7) Inserts elements from range [first, last). If multiple elements in the range have keys that compare equivalent, it is unspecified 
    // which element is inserted (pending LWG2844).
    // 8) Inserts elements from initializer list ilist. If multiple elements in the range have keys that compare equivalent, it is unspecified 
    // which element is inserted (pending LWG2844).
    // 9) If nh is an empty node handle, does nothing. Otherwise, inserts the element owned by nh into the container , if the container 
    // doesn't already contain an element with a key equivalent to nh.key(). The behavior is undefined if nh is not empty and 
    // get_allocator() != nh.get_allocator().
    // 10) If nh is an empty node handle, does nothing and returns the end iterator. Otherwise, inserts the element owned by nh into the container, 
    // if the container doesn't already contain an element with a key equivalent to nh.key(), and returns the iterator pointing to the element 
    // with key equivalent to nh.key() (regardless of whether the insert succeeded or failed). If the insertion succeeds, nh is moved from, 
    // otherwise it retains ownership of the element. The element is inserted as close as possible to the position just prior to hint. 
    // The behavior is undefined if nh is not empty and get_allocator() != nh.get_allocator().
    // No iterators or references are invalidated. If the insertion is successful, pointers and references to the element obtained while it is held 
    // in the node handle are invalidated, and pointers and references obtained to that element before it was extracted become valid. (since C++17)
    cout << "myMap5 size is " << myMap5.size() << endl;

    // insert pair directly by adding {} and corresponding key with '' or "", and value, into the map 
    myMap5.insert({'B', 0.2});
    cout << "myMap5 size now is " << myMap5.size() << endl;

    // insert with std::make_pair() into map
    myMap5.insert(std::make_pair('D', 0.4));
    cout << "myMap5 size now is " << myMap5.size() << endl;

    // insert with std::pair() into map, note that by using std::pair, it needed additional definition <char, double> there
    // while std::make_pair didn't need it
    myMap5.insert(std::pair<char, double>{'F', 0.6});
    cout << "myMap5 size now is " << myMap5.size() << endl;

    cout << "All elements in the myMap5 are" << endl;
    for_each(myMap5.begin(), myMap5.end(), myMapPrint2);

    // insert_or_assign(), insert this new (key, value) or just update the value of same key
    // STL: 1,3) If a key equivalent to k already exists in the container, assigns std::forward<M>(obj) to the mapped_type corresponding 
    // to the key k. If the key does not exist, inserts the new value as if by insert, constructing it from value_type(k, std::forward<M>(obj))
    // 2,4) Same as (1,3), except the mapped value is constructed from value_type(std::move(k), std::forward<M>(obj))
    // The behavior is undefined (until C++20). The program is ill-formed (since C++20) if std::is_assignable_v<mapped_type&, M&&> is false.
    // No iterators or references are invalidated.
    myMap5.insert_or_assign('A', 0.6);
    myMap5.insert_or_assign('B', 0.5);
    myMap5.insert_or_assign('C', 0.4);
    myMap5.insert_or_assign('D', 0.3);
    myMap5.insert_or_assign('E', 0.2);
    myMap5.insert_or_assign('F', 0.1);
    cout << "All elements in the myMap5 after insert_or_assign() update are" << endl;
    for_each(myMap5.begin(), myMap5.end(), myMapPrint2);

    // emplace(), like insert() but it will construct the element with faster runtime
    // STL: Inserts a new element into the container constructed in-place with the given args if there is no element with the key in the container.
    // Careful use of emplace allows the new element to be constructed while avoiding unnecessary copy or move operations. The constructor of the 
    // new element (i.e. std::pair<const Key, T>) is called with exactly the same arguments as supplied to emplace, forwarded via 
    // std::forward<Args>(args).... The element may be constructed even if there already is an element with the key in the container, in which case 
    // the newly constructed element will be destroyed immediately.
    // No iterators or references are invalidated.
    myMap5.clear();
    myMap5.emplace('A', 0.001);
    myMap5.emplace('B', 0.010);
    myMap5.emplace('C', 0.100);
    cout << "New elements in the myMap5 are" << endl;
    for_each(myMap5.begin(), myMap5.end(), myMapPrint2);

    // emplace_hint(), similar to emplace(), but by giving a hint to insert the new element at a location, however, it doesn't guarantee that the 
    // new inserted element will be really there, just be as close as possible
    // STL: Inserts a new element to the container as close as possible to the position just before hint. The element is constructed in-place, i.e. 
    // no copy or move operations are performed.
    // The constructor of the element type (value_type, that is, std::pair<const Key, T>) is called with exactly the same arguments as supplied to 
    // the function, forwarded with std::forward<Args>(args)....
    // No iterators or references are invalidated.
    cout << "New element \"Z\" in the myMap5 has hint to location 0" << endl;
    myMap5.emplace_hint(myMap5.begin(), 10000, 'Z');
    for_each(myMap5.begin(), myMap5.end(), myMapPrint2);

    // try_emplace(), a new API that combines emplace() or emplace_hint(), if the given key doesn't exist, inert this new key, otherwise, nothing
    // STL: Inserts a new element into the container with key k and value constructed with args, if there is no element with the key in the container.
    // 1) If a key equivalent to k already exists in the container, does nothing. Otherwise, behaves like emplace except that the element is 
    // constructed as
    // value_type(std::piecewise_construct,
    //       std::forward_as_tuple(k),
    //       std::forward_as_tuple(std::forward<Args>(args)...))
    // 2) If a key equivalent to k already exists in the container, does nothing. Otherwise, behaves like emplace except that the element is constructed as
    // value_type(std::piecewise_construct,
    //       std::forward_as_tuple(std::move(k)),
    //       std::forward_as_tuple(std::forward<Args>(args)...))
    // 3) If a key equivalent to k already exists in the container, does nothing. Otherwise, behaves like emplace_hint except that the element is constructed as
    // value_type(std::piecewise_construct,
    //       std::forward_as_tuple(k),
    //       std::forward_as_tuple(std::forward<Args>(args)...))
    // 4) If a key equivalent to k already exists in the container, does nothing. Otherwise, behaves like emplace_hint except that the element is constructed as
    // value_type(std::piecewise_construct,
    //       std::forward_as_tuple(std::move(k)),
    //       std::forward_as_tuple(std::forward<Args>(args)...))
    // No iterators or references are invalidated.
    cout << "Changes of original A, B, C should remain same by calling try_emplace()" << endl;
    myMap5.try_emplace('A', 111.111);
    myMap5.try_emplace('B', 222.222);
    myMap5.try_emplace('C', 333.333);
    for_each(myMap5.begin(), myMap5.end(), myMapPrint2);
    cout << "Changes of new X, Y, Z should be inserted by calling try_emplace()" << endl;
    myMap5.try_emplace('Z', 444.444);
    myMap5.try_emplace('Y', 555.555);
    myMap5.try_emplace('X', 666.666);
    for_each(myMap5.begin(), myMap5.end(), myMapPrint2);

    // erase(), delete one specific element in map
    // STL: Removes specified elements from the container.
    // 1) Removes the element at pos.
    // 2) Removes the elements in the range [first; last), which must be a valid range in *this.
    // 3) Removes the element (if one exists) with the key equivalent to key.
    // 4) Removes the element (if one exists) with key that compares equivalent to the value x. This overload participates in overload resolution 
    // only if the qualified-id Compare::is_transparent is valid and denotes a type, and neither iterator nor const_iterator is implicitly convertible 
    // from K. It allows calling this function without constructing an instance of Key.
    // References and iterators to the erased elements are invalidated. Other references and iterators are not affected.
    // The iterator pos must be valid and dereferenceable. Thus the end() iterator (which is valid, but is not dereferenceable) cannot be used as a value for pos.
    myMap5.erase('A');
    myMap5.erase('B');
    myMap5.erase('C');
    myMap5.erase('D');
    myMap5.erase('Z');
    cout << "After calling erase() to remove specific elements" << endl; 
    for_each(myMap5.begin(), myMap5.end(), myMapPrint2);
    myMap5.clear();

    // swap(), swap elements from one map to another map
    // STL: Exchanges the contents of the container with those of other. Does not invoke any move, copy, or swap operations on individual elements.
    // All iterators and references remain valid. The past-the-end iterator is invalidated.
    // The Compare objects must be Swappable, and they are exchanged using unqualified call to non-member swap.
    // If std::allocator_traits<allocator_type>::propagate_on_container_swap::value is true, then the allocators are exchanged using an unqualified 
    // call to non-member swap. Otherwise, they are not swapped (and if get_allocator() != other.get_allocator(), the behavior is undefined). (since C++11)
    cout << "myMap3 before swap()" << endl; 
    for_each(myMap3.begin(), myMap3.end(), myMapPrint3);
    cout << "myMap6 before swap()" << endl; 
    for_each(myMap6.begin(), myMap6.end(), myMapPrint3);
    myMap3.swap(myMap6);
    cout << "myMap3 after swap()" << endl; 
    for_each(myMap3.begin(), myMap3.end(), myMapPrint3);
    cout << "myMap6 after swap()" << endl; 
    for_each(myMap6.begin(), myMap6.end(), myMapPrint3);

    // extract(), get one element by specifying key, and by using key(), that allows us to change key in the map, not usual usage
    // Also, it needed to be inserted again back to map with std::move() call
    // STL: 1) Unlinks the node that contains the element pointed to by position and returns a node handle that owns it.
    // 2) If the container has an element with key equivalent to k, unlinks the node that contains that element from the container and returns a node 
    // handle that owns it. Otherwise, returns an empty node handle.
    // 3) Same as (2). This overload participates in overload resolution only if the qualified-id Compare::is_transparent is valid and denotes a type, 
    // and neither iterator nor const_iterator is implicitly convertible from K. It allows calling this function without constructing an instance of Key.
    // In either case, no elements are copied or moved, only the internal pointers of the container nodes are repointed (rebalancing may occur, as with 
    // erase()).
    // Extracting a node invalidates only the iterators to the extracted element. Pointers and references to the extracted element remain valid, but 
    // cannot be used while element is owned by a node handle: they become usable if the element is inserted into a container.
    auto test1 = myMap6.extract("Student1");
    test1.key() = "Student4";
    myMap6.insert(std::move(test1));
    cout << "myMap6 after changing Student1 to Student4" << endl; 
    for_each(myMap6.begin(), myMap6.end(), myMapPrint3);

    // merge(), merge to maps into one, as map can only allow one key, when it already has the key, the later value will be ignored
    // STL: Attempts to extract ("splice") each element in source and insert it into *this using the comparison object of *this. If there is an element 
    // in *this with key equivalent to the key of an element from source, then that element is not extracted from source. No elements are copied or moved, 
    // only the internal pointers of the container nodes are repointed. All pointers and references to the transferred elements remain valid, but now 
    // refer into *this, not into source.
    // The behavior is undefined if get_allocator() != source.get_allocator().
    std::map<int, std::string> ma {{1, "apple"}, {5, "pear"}, {10, "banana"}};
    std::map<int, std::string> mb {{2, "zorro"}, {4, "batman"}, {5, "X"}, {8, "alpaca"}};
    for (auto el = ma.begin(); el != ma.end(); el++) {
        cout << el->first << " " << el->second << endl;
    }
    for (auto el = mb.begin(); el != mb.end(); el++) {
        cout << el->first << " " << el->second << endl;
    }
    ma.merge(mb);
    cout << "After merge to ma" << endl;
    for (auto &el : ma) {
        cout << el.first << " " << el.second << endl;
    }
    cout << "Elements left in mb due to same key 5" << endl;
    for (auto &el : mb) {
        cout << el.first << " " << el.second << endl;
    }

    // count(), return number of elements of given key. For map, it should be either 0 or 1 as map doesn't allow duplicated ones
    // STL: Returns the number of elements with key that compares equivalent to the specified argument, which is either 1 or 0 since this container 
    // does not allow duplicates.
    // 1) Returns the number of elements with key key.
    // 2) Returns the number of elements with key that compares equivalent to the value x. This overload participates in overload resolution 
    // only if the qualified-id Compare::is_transparent 
    // is valid and denotes a type. They allow calling this function without constructing an instance of Key.
    cout << "How many elements of key 1 in ma? " << ma.count(1) << endl;

    // find(), find the given element by key
    // STL: 1,2) Finds an element with key equivalent to key.
    // 3,4) Finds an element with key that compares equivalent to the value x. This overload participates in overload resolution only if the qualified-id 
    // Compare::is_transparent is valid and denotes a type. It allows calling this function without constructing an instance of Key.
    auto left_element = mb.find(5);
    cout << "The last element left in mb is " << left_element->first << " " << left_element->second << endl;

    // contains(), check if the given key existed in the map, note that this is supported from C++ 20
    // STL: 1) Checks if there is an element with key equivalent to key in the container.
    // 2) Checks if there is an element with key that compares equivalent to the value x. This overload participates in overload resolution only if the 
    // qualified-id Compare::is_transparent is valid and denotes a type. It allows calling this function without constructing an instance of Key.
    // cout << "Is key 5 existed in the mb? " << std::boolalpha << mb.contains(5) << endl; 

    // equal_range(), return two iterators, first is not less than the key, second is the first one that is greater than the key, so the first and second
    // may be the same one
    // STL: Returns a range containing all elements with the given key in the container. The range is defined by two iterators, one pointing to the first 
    // element that is not less than key and another pointing to the first element greater than key. Alternatively, the first iterator may be obtained 
    // with lower_bound(), and the second with upper_bound().
    // 1,2) Compares the keys to key.
    // 3,4) Compares the keys to the value x. This overload participates in overload resolution only if the qualified-id Compare::is_transparent is valid 
    // and denotes a type. It allows calling this function without constructing an instance of Key. This section is incomplete Reason: explain better
    cout << "Elements in ma are:" << endl;
    for (auto &el : ma) {
        cout << " " << el.first << " " << el.second << endl;
    }
    auto range_elements = ma.equal_range(6);
    cout << "The equal range of ma for number 6 is " << range_elements.first->first << " and " << range_elements.second->first << endl;
    range_elements = ma.equal_range(4);
    cout << "The equal range of ma for number 4 is " << range_elements.first->first << " and " << range_elements.second->first << endl;
    range_elements = ma.equal_range(8);
    cout << "The equal range of ma for number 8 is " << range_elements.first->first << " and " << range_elements.second->first << endl;

    // lower_bound()/upper_bound(), return the iterator that is first iterator not less than the given key, or greater than the given key
    auto bound_element = ma.lower_bound(4);
    cout << "The lower_bound of ma for number 4 is " << bound_element->first << " and " << bound_element->second << endl;
    bound_element = ma.upper_bound(4);
    cout << "The upper_bound of ma for number 4 is " << bound_element->first << " and " << bound_element->second << endl;

    // key_comp(), compare function for map, if we want to customize the comparison function
    // STL: Returns the function object that compares the keys, which is a copy of this container's constructor argument comp.
    // Below code examlpe is from https://en.cppreference.com/w/cpp/container/map/key_comp
    struct ModCmp {
        bool operator()(const int lhs, const int rhs) const
        {
            return (lhs % 97) < (rhs % 97);
        }
    };
    std::map<int, char, ModCmp> cont = {{1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
    auto comp_func = cont.key_comp();
    cout << "key_comp() operation:" << endl;
    for (auto it = cont.begin(); it != cont.end(); it++) {
        bool before = comp_func(it->first, 100);
        cout << boolalpha << it->first << " " << it->second << " " << before << endl;
        bool after = comp_func(100, it->first);
        cout << boolalpha << it->first << " " << it->second << " " << after << endl;
    }
    
    // value_comp(), compare function for map, if we want to customize the comparsion function
    // STL: Returns a function object that compares objects of type std::map::value_type (key-value pairs) by using key_comp to 
    // compare the first components of the pairs.
    auto comp_value_func = cont.value_comp();
    const std::pair<int, char> val = { 100, 'a' };
    cout << "value_comp() operation:" << endl;
    for (auto it : cont) {
        bool before = comp_value_func(it, val);
        cout << boolalpha << it.first << " " << it.second << " " << before << endl;
        bool after = comp_value_func(val, it);
        cout << boolalpha << it.first << " " << it.second << " " << after << endl;
    }

    // std::swap(), swap whole map from one to another
    // STL: Specializes the std::swap algorithm for std::map. Swaps the contents of lhs and rhs. Calls lhs.swap(rhs).
    std::map<int, char> alice{{1, 'a'}, {2, 'b'}, {3, 'c'}};
    std::map<int, char> bob{{7, 'Z'}, {8, 'Y'}, {9, 'X'}, {10, 'W'}};
    auto print = [](std::pair<const int, char>& n) { 
        std::cout << " " << n.first << '(' << n.second << ')'; 
    };
    std::for_each(alice.begin(), alice.end(), print);
    cout << endl;
    std::for_each(bob.begin(), bob.end(), print);
    cout << endl;
    std::cout << "-- SWAP --\n";
    std::swap(alice, bob);
    std::for_each(alice.begin(), alice.end(), print);
    cout << endl;
    std::for_each(bob.begin(), bob.end(), print);
    cout << endl;

    // erase_if(), erase element if the condition matched
    // STL: Erases all elements that satisfy the predicate pred from the container. Equivalent to
    // auto old_size = c.size();
    // for (auto i = c.begin(), last = c.end(); i != last; ) {
    //   if (pred(*i)) {
    //     i = c.erase(i);
    //   } else {
    //     ++i;
    //   }
    // }
    // return old_size - c.size();
    // std::map<int, char> data {{1, 'a'},{2, 'b'},{3, 'c'},{4, 'd'},
    //                          {5, 'e'},{4, 'f'},{5, 'g'},{5, 'g'}};
    // const auto count = std::erase_if(data, [](const auto& item) {
    //   auto const& [key, value] = item;
    //   return (key & 1) == 1;
    // });

    return 0;
}
