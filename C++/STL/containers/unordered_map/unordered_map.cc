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

继 map、multimap、set、multiset 关联式容器之后，从本节开始，再讲解一类“特殊”的关联式容器，它们常被称为“无序容器”、“哈希容器”或者
“无序关联容器”。

注意，无序容器是 C++ 11 标准才正式引入到 STL 标准库中的，这意味着如果要使用该类容器，则必须选择支持 C++ 11 标准的编译器。

和关联式容器一样，无序容器也使用键值对（pair 类型）的方式存储数据。不过，本教程将二者分开进行讲解，因为它们有本质上的不同：
关联式容器的底层实现采用的树存储结构，更确切的说是红黑树结构；
无序容器的底层实现采用的是哈希表的存储结构。
C++ STL 底层采用哈希表实现无序容器时，会将所有数据存储到一整块连续的内存空间中，并且当数据存储位置发生冲突时，解决方法选用的是“
链地址法”（又称“开链法”）。有关哈希表存储结构，读者可阅读《哈希表(散列表)详解》一文做详细了解。

基于底层实现采用了不同的数据结构，因此和关联式容器相比，无序容器具有以下 2 个特点：
无序容器内部存储的键值对是无序的，各键值对的存储位置取决于该键值对中的键，
和关联式容器相比，无序容器擅长通过指定键查找对应的值（平均时间复杂度为 O(1)）；但对于使用迭代器遍历容器中存储的元素，无序容器的
执行效率则不如关联式容器。

C++ STL无序容器种类
和关联式容器一样，无序容器只是一类容器的统称，其包含有 4 个具体容器，分别为 unordered_map、unordered_multimap、unordered_set 
以及 unordered_multiset。

表 1 对这 4 种无序容器的功能做了详细的介绍。

表 1 无序容器种类
无序容器	功能
unordered_map 	存储键值对 <key, value> 类型的元素，其中各个键值对键的值不允许重复，且该容器中存储的键值对是无序的。
unordered_multimap	和 unordered_map 唯一的区别在于，该容器允许存储多个键相同的键值对。
unordered_set	不再以键值对的形式存储数据，而是直接存储数据元素本身（当然也可以理解为，该容器存储的全部都是键 key 和值 value 
相等的键值对，正因为它们相等，因此只存储 value 即可）。另外，该容器存储的元素不能重复，且容器内部存储的元素也是无序的。
unordered_multiset	和 unordered_set 唯一的区别在于，该容器允许存储值相同的元素。
可能读者已经发现，以上 4 种无序容器的名称，仅是在前面所学的 4 种关联式容器名称的基础上，添加了 "unordered_"。如果读者已经学完了 
map、multimap、set 和 multiset 容器不难发现，以 map 和 unordered_map 为例，其实它们仅有一个区别，即 map 容器内存会对存储的
键值对进行排序，而 unordered_map 不会。
也就是说，C++ 11 标准的 STL 中，在已提供有 4 种关联式容器的基础上，又新增了各自的“unordered”版本（无序版本、哈希版本），提高了
查找指定元素的效率。


有读者可能会问，既然无序容器和之前所学的关联式容器类似，那么在实际使用中应该选哪种容器呢？总的来说，实际场景中如果涉及大量遍历容器
的操作，建议首选关联式容器；反之，如果更多的操作是通过键获取对应的值，则应首选无序容器。

为了加深读者对无序容器的认识，这里以 unordered_map 容器为例，举个例子（不必深究该容器的具体用法）：
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main()
{
    //创建并初始化一个 unordered_map 容器，其存储的 <string,string> 类型的键值对
    std::unordered_map<std::string, std::string> my_uMap{
        {"C语言教程","http://c.biancheng.net/c/"},
        {"Python教程","http://c.biancheng.net/python/"},
        {"Java教程","http://c.biancheng.net/java/"} };
    //查找指定键对应的值，效率比关联式容器高
    string str = my_uMap.at("C语言教程");
    cout << "str = " << str << endl;
    //使用迭代器遍历哈希容器，效率不如关联式容器
    for (auto iter = my_uMap.begin(); iter != my_uMap.end(); ++iter)
    {
        //pair 类型键值对分为 2 部分
        cout << iter->first << " " << iter->second << endl;
    }
    return 0;
}
程序执行结果为：
str = http://c.biancheng.net/c/
C语言教程 http://c.biancheng.net/c/
Python教程 http://c.biancheng.net/python/
Java教程 http://c.biancheng.net/java/

关于 4 种无序容器各自的用法，后续章节会做详细讲解。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业故事+
学习历程+工作记录+生活日常+编程资料。


C++ STL 标准库中提供有 4 种无序关联式容器，本节先讲解 unordered_map 容器。

unordered_map 容器，直译过来就是"无序 map 容器"的意思。所谓“无序”，指的是 unordered_map 容器不会像 map 容器那样对存储的数据
进行排序。换句话说，unordered_map 容器和 map 容器仅有一点不同，即 map 容器中存储的数据是有序的，而 unordered_map 容器中是无序的。
对于已经学过 map 容器的读者，可以将 unordered_map 容器等价为无序的 map 容器。

具体来讲，unordered_map 容器和 map 容器一样，以键值对（pair类型）的形式存储数据，存储的各个键值对的键互不相同且不允许被修改。
但由于 unordered_map 容器底层采用的是哈希表存储结构，该结构本身不具有对数据的排序功能，所以此容器内部不会自行对存储的键值对进行
排序。

值得一提的是，unordered_map 容器在<unordered_map>头文件中，并位于 std 命名空间中。因此，如果想使用该容器，代码中应包含如下语句：
#include <unordered_map>
using namespace std;
注意，第二行代码不是必需的，但如果不用，则后续程序中在使用此容器时，需手动注明 std 命名空间（强烈建议初学者使用）。

unordered_map 容器模板的定义如下所示：
template < class Key,                        //键值对中键的类型
           class T,                          //键值对中值的类型
           class Hash = hash<Key>,           //容器内部存储键值对所用的哈希函数
           class Pred = equal_to<Key>,       //判断各个键值对键相同的规则
           class Alloc = allocator< pair<const Key,T> >  // 指定分配器对象的类型
           > class unordered_map;
以上 5 个参数中，必须显式给前 2 个参数传值，并且除特殊情况外，最多只需要使用前 4 个参数，各自的含义和功能如表 1 所示。

表 1 unordered_map 容器模板类的常用参数
参数	含义
<key,T>	前 2 个参数分别用于确定键值对中键和值的类型，也就是存储键值对的类型。
Hash = hash<Key>	用于指明容器在存储各个键值对时要使用的哈希函数，默认使用 STL 标准库提供的 hash<key> 哈希函数。注意，默认哈希
函数只适用于基本数据类型（包括 string 类型），而不适用于自定义的结构体或者类。
Pred = equal_to<Key>	要知道，unordered_map 容器中存储的各个键值对的键是不能相等的，而判断是否相等的规则，就由此参数指定。默认
情况下，使用 STL 标准库中提供的 equal_to<key> 规则，该规则仅支持可直接用 == 运算符做比较的数据类型。
总的来说，当无序容器中存储键值对的键为自定义类型时，默认的哈希函数 hash 以及比较函数 equal_to 将不再适用，只能自己设计适用该类型的
哈希函数和比较函数，并显式传递给 Hash 参数和 Pred 参数。至于如何实现自定义，后续章节会做详细讲解。

创建C++ unordered_map容器的方法
常见的创建 unordered_map 容器的方法有以下几种。

1) 通过调用 unordered_map 模板类的默认构造函数，可以创建空的 unordered_map 容器。比如：
std::unordered_map<std::string, std::string> umap;
由此，就创建好了一个可存储 <string,string> 类型键值对的 unordered_map 容器。

2) 当然，在创建 unordered_map 容器的同时，可以完成初始化操作。比如：
std::unordered_map<std::string, std::string> umap{
    {"Python教程","http://c.biancheng.net/python/"},
    {"Java教程","http://c.biancheng.net/java/"},
    {"Linux教程","http://c.biancheng.net/linux/"} };
通过此方法创建的 umap 容器中，就包含有 3 个键值对元素。

3) 另外，还可以调用 unordered_map 模板中提供的复制（拷贝）构造函数，将现有 unordered_map 容器中存储的键值对，复制给新建 
unordered_map 容器。

例如，在第二种方式创建好 umap 容器的基础上，再创建并初始化一个 umap2 容器：
std::unordered_map<std::string, std::string> umap2(umap);
由此，umap2 容器中就包含有 umap 容器中所有的键值对。

除此之外，C++ 11 标准中还向 unordered_map 模板类增加了移动构造函数，即以右值引用的方式将临时 unordered_map 容器中存储的所有键值对，
全部复制给新建容器。例如：

//返回临时 unordered_map 容器的函数
std::unordered_map <std::string, std::string > retUmap(){
    std::unordered_map<std::string, std::string>tempUmap{
        {"Python教程","http://c.biancheng.net/python/"},
        {"Java教程","http://c.biancheng.net/java/"},
        {"Linux教程","http://c.biancheng.net/linux/"} };
    return tempUmap;
}
//调用移动构造函数，创建 umap2 容器
std::unordered_map<std::string, std::string> umap2(retUmap());
注意，无论是调用复制构造函数还是拷贝构造函数，必须保证 2 个容器的类型完全相同。

4) 当然，如果不想全部拷贝，可以使用 unordered_map 类模板提供的迭代器，在现有 unordered_map 容器中选择部分区域内的键值对，为新建 
unordered_map 容器初始化。例如：

//传入 2 个迭代器，
std::unordered_map<std::string, std::string> umap2(++umap.begin(),umap.end());
通过此方式创建的 umap2 容器，其内部就包含 umap 容器中除第 1 个键值对外的所有其它键值对。
C++ unordered_map容器的成员方法
unordered_map 既可以看做是关联式容器，更属于自成一脉的无序容器。因此在该容器模板类中，既包含一些在学习关联式容器时常见的成员方法，
还有一些属于无序容器特有的成员方法。

表 2 列出了 unordered_map 类模板提供的所有常用的成员方法以及各自的功能。

表 2 unordered_map类模板成员方法
成员方法	功能
begin()	返回指向容器中第一个键值对的正向迭代器。
end() 	返回指向容器中最后一个键值对之后位置的正向迭代器。
cbegin()	和 begin() 功能相同，只不过在其基础上增加了 const 属性，即该方法返回的迭代器不能用于修改容器内存储的键值对。
cend()	和 end() 功能相同，只不过在其基础上，增加了 const 属性，即该方法返回的迭代器不能用于修改容器内存储的键值对。
empty()	若容器为空，则返回 true；否则 false。
size()	返回当前容器中存有键值对的个数。
max_size()	返回容器所能容纳键值对的最大个数，不同的操作系统，其返回值亦不相同。
operator[key]	该模板类中重载了 [] 运算符，其功能是可以向访问数组中元素那样，只要给定某个键值对的键 key，就可以获取该键对应的值。
注意，如果当前容器中没有以 key 为键的键值对，则其会使用该键向当前容器中插入一个新键值对。
at(key)	返回容器中存储的键 key 对应的值，如果 key 不存在，则会抛出 out_of_range 异常。 
find(key)	查找以 key 为键的键值对，如果找到，则返回一个指向该键值对的正向迭代器；反之，则返回一个指向容器中最后一个键值对之后位置
的迭代器（如果 end() 方法返回的迭代器）。
count(key)	在容器中查找以 key 键的键值对的个数。
equal_range(key)	返回一个 pair 对象，其包含 2 个迭代器，用于表明当前容器中键为 key 的键值对所在的范围。
emplace()	向容器中添加新键值对，效率比 insert() 方法高。
emplace_hint()	向容器中添加新键值对，效率比 insert() 方法高。
insert() 	向容器中添加新键值对。
erase()	删除指定键值对。
clear() 	清空容器，即删除容器中存储的所有键值对。
swap()	交换 2 个 unordered_map 容器存储的键值对，前提是必须保证这 2 个容器的类型完全相等。
bucket_count()	返回当前容器底层存储键值对时，使用桶（一个线性链表代表一个桶）的数量。
max_bucket_count()	返回当前系统中，unordered_map 容器底层最多可以使用多少桶。
bucket_size(n)	返回第 n 个桶中存储键值对的数量。
bucket(key)	返回以 key 为键的键值对所在桶的编号。
load_factor()	返回 unordered_map 容器中当前的负载因子。负载因子，指的是的当前容器中存储键值对的数量（size()）和使用桶数
（bucket_count()）的比值，即 load_factor() = size() / bucket_count()。
max_load_factor()	返回或者设置当前 unordered_map 容器的负载因子。
rehash(n)	将当前容器底层使用桶的数量设置为 n。
reserve()	将存储桶的数量（也就是 bucket_count() 方法的返回值）设置为至少容纳count个元（不超过最大负载因子）所需的数量，并重新
整理容器。
hash_function()	返回当前容器使用的哈希函数对象。
注意，对于实现互换 2 个相同类型 unordered_map 容器的键值对，除了可以调用该容器模板类中提供的 swap() 成员方法外，STL 标准库还提供
了同名的 swap() 非成员函数。


下面的样例演示了表 2 中部分成员方法的用法：
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main()
{
    //创建空 umap 容器
    unordered_map<string, string> umap;
    //向 umap 容器添加新键值对
    umap.emplace("Python教程", "http://c.biancheng.net/python/");
    umap.emplace("Java教程", "http://c.biancheng.net/java/");
    umap.emplace("Linux教程", "http://c.biancheng.net/linux/");
    //输出 umap 存储键值对的数量
    cout << "umap size = " << umap.size() << endl;
    //使用迭代器输出 umap 容器存储的所有键值对
    for (auto iter = umap.begin(); iter != umap.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }
    return 0;
}
程序执行结果为：
umap size = 3
Python教程 http://c.biancheng.net/python/
Linux教程 http://c.biancheng.net/linux/
Java教程 http://c.biancheng.net/java/

有关表 2 中其它成员方法的用法，后续章节会做详细讲解。当然，读者也可以自行查询 C++ STL标准库手册。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业故事+学习历程+
工作记录+生活日常+编程资料。


在阅读本节内容之前，读者需了解哈希表存储结构的原理，可猛击《哈希表（散列表）详解》一节。

在了解哈希表存储结构的基础上，本节将具体分析 C++ STL 无序容器（哈希容器）底层的实现原理。

C++ STL 标准库中，不仅是 unordered_map 容器，所有无序容器的底层实现都采用的是哈希表存储结构。更准确地说，是用“链地址法”（又称“开链法”）
解决数据存储位置发生冲突的哈希表，整个存储结构如图 1 所示。

C++ STL 无序容器存储状态示意图
图 1 C++ STL 无序容器存储状态示意图
其中，Pi 表示存储的各个键值对。

可以看到，当使用无序容器存储键值对时，会先申请一整块连续的存储空间，但此空间并不用来直接存储键值对，而是存储各个链表的头指针，各键值对真正
的存储位置是各个链表的节点。注意，STL 标准库通常选用 vector 容器存储各个链表的头指针。

不仅如此，在 C++ STL 标准库中，将图 1 中的各个链表称为桶（bucket），每个桶都有自己的编号（从 0 开始）。当有新键值对存储到无序容器中时，
整个存储过程分为如下几步：

将该键值对中键的值带入设计好的哈希函数，会得到一个哈希值（一个整数，用 H 表示）；
将 H 和无序容器拥有桶的数量 n 做整除运算（即 H % n），该结果即表示应将此键值对存储到的桶的编号；
建立一个新节点存储此键值对，同时将该节点链接到相应编号的桶上。

另外值得一提的是，哈希表存储结构还有一个重要的属性，称为负载因子（load factor）。该属性同样适用于无序容器，用于衡量容器存储键值对的空/满程序，
即负载因子越大，意味着容器越满，即各链表中挂载着越多的键值对，这无疑会降低容器查找目标键值对的效率；反之，负载因子越小，容器肯定越空，但并不一
定各个链表中挂载的键值对就越少。

举个例子，如果设计的哈希函数不合理，使得各个键值对的键带入该函数得到的哈希值始终相同（所有键值对始终存储在同一链表上）。这种情况下，即便增加桶
数是的负载因子减小，该容器的查找效率依旧很差。

无序容器中，负载因子的计算方法为：
负载因子 = 容器存储的总键值对 / 桶数

默认情况下，无序容器的最大负载因子为 1.0。如果操作无序容器过程中，使得最大复杂因子超过了默认值，则容器会自动增加桶数，并重新进行哈希，以此来减小
负载因子的值。需要注意的是，此过程会导致容器迭代器失效，但指向单个键值对的引用或者指针仍然有效。
这也就解释了，为什么我们在操作无序容器过程中，键值对的存储顺序有时会“莫名”的发生变动。


C++ STL 标准库为了方便用户更好地管控无序容器底层使用的哈希表存储结构，各个无序容器的模板类中都提供表 2 所示的成员方法。

表 2 无序容器管理哈希表的成员方法
成员方法	功能
bucket_count()	返回当前容器底层存储键值对时，使用桶的数量。
max_bucket_count()	返回当前系统中，unordered_map 容器底层最多可以使用多少个桶。
bucket_size(n)	返回第 n 个桶中存储键值对的数量。
bucket(key)	返回以 key 为键的键值对所在桶的编号。
load_factor()	返回 unordered_map 容器中当前的负载因子。
max_load_factor()	返回或者设置当前 unordered_map 容器的最大负载因子。
rehash(n)	尝试重新调整桶的数量为等于或大于 n 的值。如果 n 大于当前容器使用的桶数，则该方法会是容器重新哈希，该容器新的桶数将等于或大于 n。
反之，如果 n 的值小于当前容器使用的桶数，则调用此方法可能没有任何作用。
reserve(n)	将容器使用的桶数（bucket_count() 方法的返回值）设置为最适合存储 n 个元素的桶数。
hash_function()	返回当前容器使用的哈希函数对象。
下面的程序以学过的 unordered_map 容器为例，演示了表 2 中部分成员方法的用法：
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main()
{
    //创建空 umap 容器
    unordered_map<string, string> umap;
   
    cout << "umap 初始桶数: " << umap.bucket_count() << endl;
    cout << "umap 初始负载因子: " << umap.load_factor() << endl;
    cout << "umap 最大负载因子: " << umap.max_load_factor() << endl;
    //设置 umap 使用最适合存储 9 个键值对的桶数
    umap.reserve(9);
    cout << "*********************" << endl;
    cout << "umap 新桶数: " << umap.bucket_count() << endl;
    cout << "umap 新负载因子: " << umap.load_factor() << endl;
    //向 umap 容器添加 3 个键值对
    umap["Python教程"] = "http://c.biancheng.net/python/";
    umap["Java教程"] = "http://c.biancheng.net/java/";
    umap["Linux教程"] = "http://c.biancheng.net/linux/";
    //调用 bucket() 获取指定键值对位于桶的编号
    cout << "以\"Python教程\"为键的键值对，位于桶的编号为:" << umap.bucket("Python教程") << endl;
    //自行计算某键值对位于哪个桶
    auto fn = umap.hash_function();
    cout << "计算以\"Python教程\"为键的键值对，位于桶的编号为：" << fn("Python教程") % (umap.bucket_count()) << endl;
    return 0;
}
程序执行结果为：
umap 初始桶数: 8
umap 初始负载因子: 0
umap 最大负载因子: 1
*********************
umap 新桶数: 16
umap 新负载因子: 0
以"Python教程"为键的键值对，位于桶的编号为:9
计算以"Python教程"为键的键值对，位于桶的编号为：9

从输出结果可以看出，对于空的 umap 容器，初始状态下会分配 8 个桶，并且默认最大负载因子为 1.0，但由于其为存储任何键值对，因此负载因子值为 0。

与此同时，程序中调用 reverse() 成员方法，是 umap 容器的桶数改为了 16，其最适合存储 9 个键值对。从侧面可以看出，一旦负载因子大于 1.0（9/8 > 1.0），
则容器所使用的桶数就会翻倍式（8、16、32、...）的增加。

程序最后还演示了如何手动计算出指定键值对存储的桶的编号，其计算结果和使用 bucket() 成员方法得到的结果是一致的。
关于表 2 中成员方法的具体语法和用法，都很简单，不再过多赘述，感兴趣的读者可自行翻阅 C++ STL手册。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业故事+学习历程+
工作记录+生活日常+编程资料。


C++ STL 标准库中，unordered_map 容器迭代器的类型为前向迭代器（又称正向迭代器）。这意味着，假设 p 是一个前向迭代器，则其只能进行 
*p、p++、++p 操作，且 2 个前向迭代器之间只能用 == 和 != 运算符做比较。

在 unordered_map 容器模板中，提供了表 1 所示的成员方法，可用来获取指向指定位置的前向迭代器。

表 1 C++ unordered_map迭代器相关成员方法
成员方法	功能
begin()	返回指向容器中第一个键值对的正向迭代器。
end() 	返回指向容器中最后一个键值对之后位置的正向迭代器。
cbegin()	和 begin() 功能相同，只不过在其基础上增加了 const 属性，即该方法返回的迭代器不能用于修改容器内存储的键值对。
cend()	和 end() 功能相同，只不过在其基础上，增加了 const 属性，即该方法返回的迭代器不能用于修改容器内存储的键值对。
find(key)	查找以 key 为键的键值对，如果找到，则返回一个指向该键值对的正向迭代器；反之，则返回一个指向容器中最后一个键值对之后位置的
迭代器（如果 end() 方法返回的迭代器）。
equal_range(key)	返回一个 pair 对象，其包含 2 个迭代器，用于表明当前容器中键为 key 的键值对所在的范围。
值得一提的是，equal_range(key) 很少用于 unordered_map 容器，因为该容器中存储的都是键不相等的键值对，即便调用该成员方法，得到的 2 
个迭代器所表示的范围中，最多只包含 1 个键值对。事实上，该成员方法更适用于 unordered_multimap 容器（该容器后续章节会做详细讲解）。


下面的程序演示了表 1 中部分成员方法的用法。
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main()
{
    //创建 umap 容器
    unordered_map<string, string> umap{
        {"Python教程","http://c.biancheng.net/python/"},
        {"Java教程","http://c.biancheng.net/java/"},
        {"Linux教程","http://c.biancheng.net/linux/"} };
    cout << "umap 存储的键值对包括：" << endl;
    //遍历输出 umap 容器中所有的键值对
    for (auto iter = umap.begin(); iter != umap.end(); ++iter) {
        cout << "<" << iter->first << ", " << iter->second << ">" << endl;
    }
    //获取指向指定键值对的前向迭代器
    unordered_map<string, string>::iterator iter = umap.find("Java教程");
    cout <<"umap.find(\"Java教程\") = " << "<" << iter->first << ", " << iter->second << ">" << endl;
    return 0;
}
程序执行结果为：
umap 存储的键值对包括：
<Python教程, http://c.biancheng.net/python/>
<Linux教程, http://c.biancheng.net/linux/>
<Java教程, http://c.biancheng.net/java/>
umap.find("Java教程") = <Java教程, http://c.biancheng.net/java/>


需要注意的是，在操作 unordered_map 容器过程（尤其是向容器中添加新键值对）中，一旦当前容器的负载因子超过最大负载因子（默认值为 1.0），
该容器就会适当增加桶的数量（通常是翻一倍），并自动执行 rehash() 成员方法，重新调整各个键值对的存储位置（此过程又称“重哈希”），此过程
很可能导致之前创建的迭代器失效。
所谓迭代器失效，针对的是那些用于表示容器内某个范围的迭代器，由于重哈希会重新调整每个键值对的存储位置，所以容器重哈希之后，之前表示特定
范围的迭代器很可能无法再正确表示该范围。但是，重哈希并不会影响那些指向单个键值对元素的迭代器。

举个例子：
#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    //创建 umap 容器
    unordered_map<int, int> umap;
    //向 umap 容器添加 50 个键值对
    for (int i = 1; i <= 50; i++) {
        umap.emplace(i, i);
    }
    //获取键为 49 的键值对所在的范围
    auto pair = umap.equal_range(49);
    //输出 pair 范围内的每个键值对的键的值
    for (auto iter = pair.first; iter != pair.second; ++iter) {
        cout << iter->first <<" ";
    }
    cout << endl;
    //手动调整最大负载因子数
    umap.max_load_factor(3.0);
    //手动调用 rehash() 函数重哈希
    umap.rehash(10);
    //重哈希之后，pair 的范围可能会发生变化
    for (auto iter = pair.first; iter != pair.second; ++iter) {
        cout << iter->first << " ";
    }
    return 0;
}
程序执行结果为：
49
49 17

观察输出结果不难发现，之前用于表示键为 49 的键值对所在范围的 2 个迭代器，重哈希之后表示的范围发生了改变。
经测试，用于遍历整个容器的 begin()/end() 和 cbegin()/cend() 迭代器对，重哈希只会影响遍历容器内键值对的顺序，整个遍历的操作仍然可以
顺利完成。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业故事+
学习历程+工作记录+生活日常+编程资料。


通过前面的学习我们知道，unordered_map 容器以键值对的方式存储数据。为了方便用户快速地从该类型容器提取出目标元素（也就是某个键值对的值），
unordered_map 容器类模板中提供了以下几种方法。

1) unordered_map 容器类模板中，实现了对 [ ] 运算符的重载，使得我们可以像“利用下标访问普通数组中元素”那样，通过目标键值对的键获取到该
键对应的值。

举个例子：
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main()
{
    //创建 umap 容器
    unordered_map<string, string> umap{
        {"Python教程","http://c.biancheng.net/python/"},
        {"Java教程","http://c.biancheng.net/java/"},
        {"Linux教程","http://c.biancheng.net/linux/"} };
    //获取 "Java教程" 对应的值
    string str = umap["Java教程"];
    cout << str << endl;
    return 0;
}
程序输出结果为：
http://c.biancheng.net/java/


需要注意的是，如果当前容器中并没有存储以 [ ] 运算符内指定的元素作为键的键值对，则此时 [ ] 运算符的功能将转变为：向当前容器中添加以目标元素
为键的键值对。举个例子：

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main()
{
    //创建空 umap 容器
    unordered_map<string, string> umap;
    //[] 运算符在 = 右侧
    string str = umap["STL教程"];
    //[] 运算符在 = 左侧
    umap["C教程"] = "http://c.biancheng.net/c/";
   
    for (auto iter = umap.begin(); iter != umap.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }
    return 0;
}
程序执行结果为：
C教程 http://c.biancheng.net/c/
STL教程

可以看到，当使用 [ ] 运算符向 unordered_map 容器中添加键值对时，分为 2 种情况：
当 [ ] 运算符位于赋值号（=）右侧时，则新添加键值对的键为 [ ] 运算符内的元素，其值为键值对要求的值类型的默认值（string 类型默认值为空字符串）；
当 [ ] 运算符位于赋值号（=）左侧时，则新添加键值对的键为 [ ] 运算符内的元素，其值为赋值号右侧的元素。

2) unordered_map 类模板中，还提供有 at() 成员方法，和使用 [ ] 运算符一样，at() 成员方法也需要根据指定的键，才能从容器中找到该键对应的值；
不同之处在于，如果在当前容器中查找失败，该方法不会向容器中添加新的键值对，而是直接抛出out_of_range异常。

举个例子：
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main()
{
    //创建 umap 容器
    unordered_map<string, string> umap{
        {"Python教程","http://c.biancheng.net/python/"},
        {"Java教程","http://c.biancheng.net/java/"},
        {"Linux教程","http://c.biancheng.net/linux/"} };
    //获取指定键对应的值
    string str = umap.at("Python教程");
    cout << str << endl;
    //执行此语句会抛出 out_of_range 异常
    //cout << umap.at("GO教程");
    return 0;
}
程序执行结果为：
http://c.biancheng.net/python/

此程序中，第 13 行代码用于获取 umap 容器中键为“Python教程”对应的值，由于 umap 容器确实有符合条件的键值对，因此可以成功执行；而第 17 行代码，
由于当前 umap 容器没有存储以“Go教程”为键的键值对，因此执行此语句会抛出 out_of_range 异常。

3) [ ] 运算符和 at() 成员方法基本能满足大多数场景的需要。除此之外，还可以借助 unordered_map 模板中提供的 find() 成员方法。

和前面方法不同的是，通过 find() 方法得到的是一个正向迭代器，该迭代器的指向分以下 2 种情况：
当 find() 方法成功找到以指定元素作为键的键值对时，其返回的迭代器就指向该键值对；
当 find() 方法查找失败时，其返回的迭代器和 end() 方法返回的迭代器一样，指向容器中最后一个键值对之后的位置。

举个例子：
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main()
{
    //创建 umap 容器
    unordered_map<string, string> umap{
        {"Python教程","http://c.biancheng.net/python/"},
        {"Java教程","http://c.biancheng.net/java/"},
        {"Linux教程","http://c.biancheng.net/linux/"} };
    //查找成功
    unordered_map<string, string>::iterator iter = umap.find("Python教程");
    cout << iter->first << " " << iter->second << endl;
    //查找失败
    unordered_map<string, string>::iterator iter2 = umap.find("GO教程");
    if (iter2 == umap.end()) {
        cout << "当前容器中没有以\"GO教程\"为键的键值对";
    }
    return 0;
}
程序执行结果为：
Python教程 http://c.biancheng.net/python/
当前容器中没有以"GO教程"为键的键值对


4) 除了 find() 成员方法之外，甚至可以借助 begin()/end() 或者 cbegin()/cend()，通过遍历整个容器中的键值对来找到目标键值对。

举个例子：
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main()
{
    //创建 umap 容器
    unordered_map<string, string> umap{
        {"Python教程","http://c.biancheng.net/python/"},
        {"Java教程","http://c.biancheng.net/java/"},
        {"Linux教程","http://c.biancheng.net/linux/"} };
    //遍历整个容器中存储的键值对
    for (auto iter = umap.begin(); iter != umap.end(); ++iter) {
        //判断当前的键值对是否就是要找的
        if (!iter->first.compare("Java教程")) {
            cout << iter->second << endl;
            break;
        }
    }
    return 0;
}
程序执行结果为：
http://c.biancheng.net/java/

以上 4 种方法中，前 2 种方法基本能满足多数场景的需要，建议初学者首选 at() 成员方法！

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业故事+学习历程+
工作记录+生活日常+编程资料。


为了方便用户向已建 unordered_map 容器中添加新的键值对，该容器模板中提供了 insert() 方法，本节就对此方法的用法做详细的讲解。

unordered_map 模板类中，提供了多种语法格式的 insert() 方法，根据功能的不同，可划分为以下几种用法。

1) insert() 方法可以将 pair 类型的键值对元素添加到 unordered_map 容器中，其语法格式有 2 种：
//以普通方式传递参数
pair<iterator,bool> insert ( const value_type& val );
//以右值引用的方式传递参数
template <class P>
    pair<iterator,bool> insert ( P&& val );

有关右值引用，可阅读《C++右值引用详解》一文，这里不再做具体解释。

以上 2 种格式中，参数 val 表示要添加到容器中的目标键值对元素；该方法的返回值为 pair类型值，内部包含一个 iterator 迭代器和 bool 变量：
当 insert() 将 val 成功添加到容器中时，返回的迭代器指向新添加的键值对，bool 值为 True；
当 insert() 添加键值对失败时，意味着当前容器中本就存储有和要添加键值对的键相等的键值对，这种情况下，返回的迭代器将指向这个导致插入操作
失败的迭代器，bool 值为 False。

举个例子：
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main()
{
    //创建空 umap 容器
    unordered_map<string, string> umap;
    //构建要添加的键值对
    std::pair<string, string>mypair("STL教程", "http://c.biancheng.net/stl/");
    //创建接收 insert() 方法返回值的pair类型变量
    std::pair<unordered_map<string, string>::iterator, bool> ret;
    //调用 insert() 方法的第一种语法格式
    ret = umap.insert(mypair);
    cout << "bool = " << ret.second << endl;
    cout << "iter -> " << ret.first->first <<" " << ret.first->second << endl;
   
    //调用 insert() 方法的第二种语法格式
    ret = umap.insert(std::make_pair("Python教程","http://c.biancheng.net/python/"));
    cout << "bool = " << ret.second << endl;
    cout << "iter -> " << ret.first->first << " " << ret.first->second << endl;
    return 0;
}
程序执行结果为：
bool = 1
iter -> STL教程 http://c.biancheng.net/stl/
bool = 1
iter -> Python教程 http://c.biancheng.net/python/

从输出结果很容易看出，两次添加键值对的操作，insert() 方法返回值中的 bool 变量都为 1，表示添加成功，此时返回的迭代器指向的是添加成功的
键值对。

2) 除此之外，insert() 方法还可以指定新键值对要添加到容器中的位置，其语法格式如下：
//以普通方式传递 val 参数
iterator insert ( const_iterator hint, const value_type& val );
//以右值引用方法传递 val 参数
template <class P>
    iterator insert ( const_iterator hint, P&& val );

以上 2 种语法格式中，hint 参数为迭代器，用于指定新键值对要添加到容器中的位置；val 参数指的是要添加容器中的键值对；方法的返回值为迭代器：
如果 insert() 方法成功添加键值对，该迭代器指向新添加的键值对；
如果 insert() 方法添加键值对失败，则表示容器中本就包含有相同键的键值对，该方法返回的迭代器就指向容器中键相同的键值对；
注意，以上 2 种语法格式中，虽然通过 hint 参数指定了新键值对添加到容器中的位置，但该键值对真正存储的位置，并不是 hint 参数说了算，最终
的存储位置仍取决于该键值对的键的值。

举个例子：
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main()
{
    //创建空 umap 容器
    unordered_map<string, string> umap;
    //构建要添加的键值对
    std::pair<string, string>mypair("STL教程", "http://c.biancheng.net/stl/");
    //创建接收 insert() 方法返回值的迭代器类型变量
    unordered_map<string, string>::iterator iter;
    //调用第一种语法格式
    iter = umap.insert(umap.begin(), mypair);
    cout << "iter -> " << iter->first <<" " << iter->second << endl;
   
    //调用第二种语法格式
    iter = umap.insert(umap.begin(),std::make_pair("Python教程", "http://c.biancheng.net/python/"));
    cout << "iter -> " << iter->first << " " << iter->second << endl;
    return 0;
}
程序输出结果为：
iter -> STL教程 http://c.biancheng.net/stl/
iter -> Python教程 http://c.biancheng.net/python/


3) insert() 方法还支持将某一个 unordered_map 容器中指定区域内的所有键值对，复制到另一个 unordered_map 容器中，其语法格式如下：
template <class InputIterator>
    void insert ( InputIterator first, InputIterator last );

其中 first 和 last 都为迭代器，[first, last)表示复制其它 unordered_map 容器中键值对的区域。

举个例子：
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main()
{
    //创建并初始化 umap 容器
    unordered_map<string, string> umap{ {"STL教程","http://c.biancheng.net/stl/"},
    {"Python教程","http://c.biancheng.net/python/"},
    {"Java教程","http://c.biancheng.net/java/"} };
    //创建一个空的 unordered_map 容器
    unordered_map<string, string> otherumap;
    //指定要拷贝 umap 容器中键值对的范围
    unordered_map<string, string>::iterator first = ++umap.begin();
    unordered_map<string, string>::iterator last = umap.end();
    //将指定 umap 容器中 [first,last) 区域内的键值对复制给 otherumap 容器
    otherumap.insert(first, last);
    //遍历 otherumap 容器中存储的键值对
    for (auto iter = otherumap.begin(); iter != otherumap.end(); ++iter){
        cout << iter->first << " " << iter->second << endl;
    }
    return 0;
}
程序输出结果为：
Python教程 http://c.biancheng.net/python/
Java教程 http://c.biancheng.net/java/


4) 除了以上 3 种方式，insert() 方法还支持一次向 unordered_map 容器添加多个键值对，其语法格式如下：
void insert ( initializer_list<value_type> il );

其中，il 参数指的是可以用初始化列表的形式指定多个键值对元素。

举个例子：
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main()
{
    //创建空的 umap 容器
    unordered_map<string, string> umap;
    //向 umap 容器同时添加多个键值对
    umap.insert({ {"STL教程","http://c.biancheng.net/stl/"},
    {"Python教程","http://c.biancheng.net/python/"},
    {"Java教程","http://c.biancheng.net/java/"} });
    //遍历输出 umap 容器中存储的键值对
    for (auto iter = umap.begin(); iter != umap.end(); ++iter){
        cout << iter->first << " " << iter->second << endl;
    }
    return 0;
}
程序输出结果为：
STL教程 http://c.biancheng.net/stl/
Python教程 http://c.biancheng.net/python/
Java教程 http://c.biancheng.net/java/


总的来说，unordered_map 模板类提供的 insert() 方法，有以上 4 种用法，读者可以根据实际场景的需要自行选择使用哪一种。
关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业故事+
学习历程+工作记录+生活日常+编程资料。


和前面学的 map、set 等容器一样，C++ 11 标准也为 unordered_map 容器新增了 emplace() 和 emplace_hint() 成员方法，
本节将对它们的用法做详细的介绍。

我们知道，实现向已有 unordered_map 容器中添加新键值对，可以通过调用 insert() 方法，但其实还有更好的方法，即使用 emplace() 
或者 emplace_hint() 方法，它们完成“向容器中添加新键值对”的效率，要比 insert() 方法高。
至于为什么 emplace()、emplace_hint() 执行效率会比 insert() 方法高，可阅读《为什么emplace()、emplace_hint()执行效率比
insert()高》一文，虽然此文的讲解对象为 map 容器，但就这 3 个方法来说，unordered_map 容器和 map 容器是一样的。

unordered_map emplace()方法
emplace() 方法的用法很简单，其语法格式如下：
template <class... Args>
    pair<iterator, bool> emplace ( Args&&... args );

其中，参数 args 表示可直接向该方法传递创建新键值对所需要的 2 个元素的值，其中第一个元素将作为键值对的键，另一个作为键值对的值。
也就是说，该方法无需我们手动创建键值对，其内部会自行完成此工作。

另外需要注意的是，该方法的返回值为 pair 类型值，其包含一个迭代器和一个 bool 类型值：
当 emplace() 成功添加新键值对时，返回的迭代器指向新添加的键值对，bool 值为 True；
当 emplace() 添加新键值对失败时，说明容器中本就包含一个键相等的键值对，此时返回的迭代器指向的就是容器中键相同的这个键值对，
bool 值为 False。

举个例子：
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main()
{
    //创建 umap 容器
    unordered_map<string, string> umap;
    //定义一个接受 emplace() 方法的 pair 类型变量
    pair<unordered_map<string, string>::iterator, bool> ret;
    //调用 emplace() 方法
    ret = umap.emplace("STL教程", "http://c.biancheng.net/stl/");
    //输出 ret 中包含的 2 个元素的值
    cout << "bool =" << ret.second << endl;
    cout << "iter ->" << ret.first->first << " " << ret.first->second << endl;
    return 0;
}
程序执行结果为：
bool =1
iter ->STL教程 http://c.biancheng.net/stl/

通过执行结果中 bool 变量的值为 1 可以得知，emplace() 方法成功将新键值对添加到了 umap 容器中。
unordered_map emplace_hint()方法
emplace_hint() 方法的语法格式如下：
template <class... Args>
    iterator emplace_hint ( const_iterator position, Args&&... args );

和 emplace() 方法相同，emplace_hint() 方法内部会自行构造新键值对，因此我们只需向其传递构建该键值对所需的 2 个元素
（第一个作为键，另一个作为值）即可。不同之处在于：
emplace_hint() 方法的返回值仅是一个迭代器，而不再是 pair 类型变量。当该方法将新键值对成功添加到容器中时，返回的迭代器
指向新添加的键值对；反之，如果添加失败，该迭代器指向的是容器中和要添加键值对键相同的那个键值对。
emplace_hint() 方法还需要传递一个迭代器作为第一个参数，该迭代器表明将新键值对添加到容器中的位置。需要注意的是，新键值
对添加到容器中的位置，并不是此迭代器说了算，最终仍取决于该键值对的键的值。
可以这样理解，emplace_hint() 方法中传入的迭代器，仅是给 unordered_map 容器提供一个建议，并不一定会被容器采纳。

举个例子：
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main()
{
    //创建 umap 容器
    unordered_map<string, string> umap;
    //定义一个接受 emplace_hint() 方法的迭代器
    unordered_map<string,string>::iterator iter;
    //调用 empalce_hint() 方法
    iter = umap.emplace_hint(umap.begin(),"STL教程", "http://c.biancheng.net/stl/");
    //输出 emplace_hint() 返回迭代器 iter 指向的键值对的内容
    cout << "iter ->" << iter->first << " " << iter->second << endl;
    return 0;
}
程序执行结果为：
iter ->STL教程 http://c.biancheng.net/stl/

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享
创业故事+学习历程+工作记录+生活日常+编程资料。


C++ STL 标准库为了方便用户可以随时删除 unordered_map 容器中存储的键值对，unordered_map 容器类模板中提供了以下 2 个成员方法：
erase()：删除 unordered_map 容器中指定的键值对；
clear()：删除 unordered_map 容器中所有的键值对，即清空容器。

本节就对以上 2 个成员方法的用法做详细的讲解。
unordered_map erase()方法
为了满足不同场景删除 unordered_map 容器中键值对的需要，此容器的类模板中提供了 3 种语法格式的 erase() 方法。

1) erase() 方法可以接受一个正向迭代器，并删除该迭代器指向的键值对。该方法的语法格式如下：
iterator erase ( const_iterator position );

其中 position 为指向容器中某个键值对的迭代器，该方法会返回一个指向被删除键值对之后位置的迭代器。

举个例子：
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main()
{
    //创建 umap 容器
    unordered_map<string, string> umap{
        {"STL教程", "http://c.biancheng.net/stl/"},
        {"Python教程", "http://c.biancheng.net/python/"},
        {"Java教程", "http://c.biancheng.net/java/"} };
    //输出 umap 容器中存储的键值对
    for (auto iter = umap.begin(); iter != umap.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }
    cout << "erase:" << endl;
    //定义一个接收 erase() 方法的迭代器
    unordered_map<string,string>::iterator ret;
    //删除容器中第一个键值对
    ret = umap.erase(umap.begin());
    //输出 umap 容器中存储的键值对
    for (auto iter = umap.begin(); iter != umap.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }
    cout << "ret = " << ret->first << " " << ret->second << endl;
    return 0;
}
程序执行结果为：
STL教程 http://c.biancheng.net/stl/
Python教程 http://c.biancheng.net/python/
Java教程 http://c.biancheng.net/java/
erase:
Python教程 http://c.biancheng.net/python/
Java教程 http://c.biancheng.net/java/
ret = Python教程 http://c.biancheng.net/python/

可以看到，通过给 erase() 方法传入指向容器中第一个键值对的迭代器，该方法可以将容器中第一个键值对删除，同时返回一个指向
被删除键值对之后位置的迭代器。注意，如果erase()方法删除的是容器存储的最后一个键值对，则该方法返回的迭代器，将指向容器
中最后一个键值对之后的位置（等同于 end() 方法返回的迭代器）。


2) 我们还可以直接将要删除键值对的键作为参数直接传给 erase() 方法，该方法会自行去 unordered_map 容器中找和给定键相同
的键值对，将其删除。erase() 方法的语法格式如下：

size_type erase ( const key_type& k );

其中，k 表示目标键值对的键的值；该方法会返回一个整数，其表示成功删除的键值对的数量。

举个例子：
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main()
{
    //创建 umap 容器
    unordered_map<string, string> umap{
        {"STL教程", "http://c.biancheng.net/stl/"},
        {"Python教程", "http://c.biancheng.net/python/"},
        {"Java教程", "http://c.biancheng.net/java/"} }; 
    //输出 umap 容器中存储的键值对
    for (auto iter = umap.begin(); iter != umap.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }
    int delNum = umap.erase("Python教程");
    cout << "delNum = " << delNum << endl;
    //再次输出 umap 容器中存储的键值对
    for (auto iter = umap.begin(); iter != umap.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }
    return 0;
}
程序执行结果为：
STL教程 http://c.biancheng.net/stl/
Python教程 http://c.biancheng.net/python/
Java教程 http://c.biancheng.net/java/
delNum = 1
STL教程 http://c.biancheng.net/stl/
Java教程 http://c.biancheng.net/java/

通过输出结果可以看到，通过将 "Python教程" 传给 erase() 方法，就成功删除了 umap 容器中键为 "Python教程" 的键值对。

3) 除了支持删除 unordered_map 容器中指定的某个键值对，erase() 方法还支持一次删除指定范围内的所有键值对，其语法
格式如下：

iterator erase ( const_iterator first, const_iterator last );

其中 first 和 last 都是正向迭代器，[first, last) 范围内的所有键值对都会被 erase() 方法删除；同时，该方法会返回一
个指向被删除的最后一个键值对之后一个位置的迭代器。

举个例子：
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main()
{
    //创建 umap 容器
    unordered_map<string, string> umap{
        {"STL教程", "http://c.biancheng.net/stl/"},
        {"Python教程", "http://c.biancheng.net/python/"},
        {"Java教程", "http://c.biancheng.net/java/"} };
    //first 指向第一个键值对
    unordered_map<string, string>::iterator first = umap.begin();
    //last 指向最后一个键值对
    unordered_map<string, string>::iterator last = umap.end();
    //删除[fist,last)范围内的键值对
    auto ret = umap.erase(first, last);
    //输出 umap 容器中存储的键值对
    for (auto iter = umap.begin(); iter != umap.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }
    return 0;
}
执行程序会发现，没有输出任何数据，因为 erase() 方法删除了 umap 容器中 [begin(), end()) 范围内所有的元素。
unordered_map clear()方法
在个别场景中，可能需要一次性删除 unordered_map 容器中存储的所有键值对，可以使用 clear() 方法，其语法格式如下：
void clear()


举个例子：
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main()
{
    //创建 umap 容器
    unordered_map<string, string> umap{
        {"STL教程", "http://c.biancheng.net/stl/"},
        {"Python教程", "http://c.biancheng.net/python/"},
        {"Java教程", "http://c.biancheng.net/java/"} };
    //输出 umap 容器中存储的键值对
    for (auto iter = umap.begin(); iter != umap.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }
    //删除容器内所有键值对
    umap.clear();
    cout << "umap size = " << umap.size() << endl;
    return 0;
}
程序执行结果为：
STL教程 http://c.biancheng.net/stl/
Python教程 http://c.biancheng.net/python/
Java教程 http://c.biancheng.net/java/
umap size = 0

显然，通过调用 clear() 方法，原本包含 3 个键值对的 umap 容器，变成了空容器。
注意，虽然使用 erase() 方法的第 3 种语法格式，可能实现删除 unordered_map 容器内所有的键值对，但更推荐使用 clear() 方法。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享
创业故事+学习历程+工作记录+生活日常+编程资料。

*/

using namespace std;
static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();

// solution


// main
int main() {
    // STL unordered_map container study, a string to int map used like a hash table
    unordered_map<string, int> myStrToIntMap;

    myStrToIntMap.insert(std::make_pair("key0", 0));
    myStrToIntMap.insert(std::make_pair("key1", 1));
    myStrToIntMap.insert(std::make_pair("key2", 2));
    myStrToIntMap.insert(std::make_pair("key3", 3));
    myStrToIntMap.insert(std::make_pair("key4", 4));

    // begin()/end() iterators used in unordered_map container
    // STL: Returns an iterator to the first element of the unordered_map.
    // If the unordered_map is empty, the returned iterator will be equal to end().
    for (auto item = myStrToIntMap.begin(); item != myStrToIntMap.end(); item++) {
        cout << item->first << " " << item->second << endl;
    }
    for (auto item : myStrToIntMap) {
        cout << item.first << " " << item.second << endl;
    }
    for (auto &item : myStrToIntMap) {
        cout << item.first << " " << item.second << endl;
    }

    // Note above and below for loop difference, can't compile below
    // for (auto item : myStrToIntMap) {
    //     cout << item->first << " " << item->second << endl;
    // }

    // empty(), check if the container is empty or not
    // STL: Checks if the container has no elements, i.e. whether begin() == end().
    cout << boolalpha << "Is this container empty? " << myStrToIntMap.empty()? "yes" : "no";
    cout << endl;

    // size()/max_size(), check current number of elements in the container
    // STL: Returns the number of elements in the container, i.e. std::distance(begin(), end()).
    // STL: Returns the maximum number of elements the container is able to hold due to system or library implementation limitations, 
    // i.e. std::distance(begin(), end()) for the largest container.
    cout << "size() of the container is " << myStrToIntMap.size() << endl;
    cout << "max_size() of the container is " << myStrToIntMap.max_size() << endl;

    // clear(), remove all elements in the container
    // STL: Erases all elements from the container. After this call, size() returns zero.
    // Invalidates any references, pointers, or iterators referring to contained elements. May also invalidate past-the-end iterators.
    unordered_map<string, int> myStrToIntMap2;
    myStrToIntMap2 = myStrToIntMap;
    cout << "size() of the container before clear() is " << myStrToIntMap.size() << endl;
    myStrToIntMap.clear();
    cout << "size() of the container after clear() is " << myStrToIntMap.size() << endl;
    myStrToIntMap = myStrToIntMap2;
    
    // insert(), add a new element into unordered_map container, note that it can only hold one unique pair (key, value)
    // STL: Inserts element(s) into the container, if the container doesn't already contain an element with an equivalent key.
    // 1-2) Inserts value. The overload (2) is equivalent to emplace(std::forward<P>(value)) and only participates in overload resolution 
    // if std::is_constructible<value_type, P&&>::value == true.
    // 3-4) Inserts value, using hint as a non-binding suggestion to where the search should start. The overload (4) is equivalent to 
    // emplace_hint(hint, std::forward<P>(value)) and only participates in overload resolution if std::is_constructible<value_type, P&&>::value 
    // == true.
    // 5) Inserts elements from range [first, last). If multiple elements in the range have keys that compare equivalent, it is unspecified 
    // which element is inserted (pending LWG2844).
    // 6) Inserts elements from initializer list ilist. If multiple elements in the range have keys that compare equivalent, it is unspecified 
    // which element is inserted (pending LWG2844).
    // 7) If nh is an empty node handle, does nothing. Otherwise, inserts the element owned by nh into the container , if the container 
    // doesn't already contain an element with a key equivalent to nh.key(). The behavior is undefined if nh is not empty and get_allocator() 
    // != nh.get_allocator().
    // 8) If nh is an empty node handle, does nothing and returns the end iterator. Otherwise, inserts the element owned by nh into the 
    // container, if the container doesn't already contain an element with a key equivalent to nh.key(), and returns the iterator pointing to 
    // the element with key equivalent to nh.key() (regardless of whether the insert succeeded or failed). If the insertion succeeds, nh is 
    // moved from, otherwise it retains ownership of the element. The element is inserted as close as possible to hint. The behavior is 
    // undefined if nh is not empty and get_allocator() != nh.get_allocator().
    // If rehashing occurs due to the insertion, all iterators are invalidated. Otherwise iterators are not affected. References are not 
    // invalidated. Rehashing occurs only if the new number of elements is greater than max_load_factor()*bucket_count(). If the insertion 
    // is successful, pointers and references to the element obtained while it is held in the node handle are invalidated, and pointers and 
    // references obtained to that element before it was extracted become valid. (since C++17)
    myStrToIntMap.insert(std::make_pair("key99", 99));
    for (auto item : myStrToIntMap) {
        cout << item.first << " " << item.second << endl;
    }

    // insert_or_assign(), similar to the insert(), but if the key is already there, update the value instead
    // Note that this function will return a pair of answer, the iterator and boolean status
    // That means this return may return a valid iterator, but its status is false, which mean the key is already there, but just
    // update its value, not new created iterator returned
    // STL: 1,3) If a key equivalent to k already exists in the container, assigns std::forward<M>(obj) to the mapped_type corresponding to 
    // the key k. If the key does not exist, inserts the new value as if by insert, constructing it from value_type(k, std::forward<M>(obj))
    // 2,4) Same as (1,3), except the mapped value is constructed from value_type(std::move(k), std::forward<M>(obj))
    // The behavior is undefined (until C++20)The program is ill-formed (since C++20) if std::is_assignable_v<mapped_type&, M&&> is false.
    // If an insertion occurs and results in a rehashing of the container, all iterators are invalidated. Otherwise iterators are not affected. 
    // References are not invalidated. Rehashing occurs only if the new number of elements is greater than max_load_factor()*bucket_count().
    // auto tricky_return = myStrToIntMap.insert_or_assign(std::make_pair("key99", 1000));
    // if (tricky_return.first != myStrToIntMap.end()) {
    //     cout << "Update key99 and return status " << boolalpha << tricky_return.second << endl;
    // } else {
    //     cout << "Fail to update key99 and return status " << boolalpha << tricky_return.second << endl;
    // }

    // emplace()/emplace_hint(), construct a new element into container without any copy or move operation
    // STL: Inserts a new element into the container constructed in-place with the given args if there is no element with the key in the 
    // container.
    // Careful use of emplace allows the new element to be constructed while avoiding unnecessary copy or move operations. The constructor 
    // of the new element (i.e. std::pair<const Key, T>) is called with exactly the same arguments as supplied to emplace, forwarded via 
    // std::forward<Args>(args).... The element may be constructed even if there already is an element with the key in the container, in 
    // which case the newly constructed element will be destroyed immediately.
    // If rehashing occurs due to the insertion, all iterators are invalidated. Otherwise iterators are not affected. References are not 
    // invalidated. Rehashing occurs only if the new number of elements is greater than max_load_factor()*bucket_count().
    // STL: Inserts a new element to the container, using hint as a suggestion where the element should go. The element is constructed in-place, 
    // i.e. no copy or move operations are performed.
    // The constructor of the element type (value_type, that is, std::pair<const Key, T>) is called with exactly the same arguments as 
    // supplied to the function, forwarded with std::forward<Args>(args)....
    // If rehashing occurs due to the insertion, all iterators are invalidated. Otherwise iterators are not affected. References are not 
    // invalidated. Rehashing occurs only if the new number of elements is greater than max_load_factor()*bucket_count().
    myStrToIntMap.emplace(std::make_pair("key100", 100));
    myStrToIntMap.emplace_hint(myStrToIntMap.end(), std::make_pair("key101", 101));
    for (auto item : myStrToIntMap) {
        cout << item.first << " " << item.second << endl;
    }

    // try_emplace(), do nothing if the key is already in container
    // STL: Inserts a new element into the container with key k and value constructed with args, if there is no element with the key in the 
    // container.
    // 1) If a key equivalent to k already exists in the container, does nothing. Otherwise, behaves like emplace except that the element is 
    // constructed as
    //value_type(std::piecewise_construct,
    //       std::forward_as_tuple(k),
    //       std::forward_as_tuple(std::forward<Args>(args)...))
    // 2) If a key equivalent to k already exists in the container, does nothing. Otherwise, behaves like emplace except that the element is 
    // constructed as
    // value_type(std::piecewise_construct,
    //       std::forward_as_tuple(std::move(k)),
    //       std::forward_as_tuple(std::forward<Args>(args)...))
    // 3) If a key equivalent to k already exists in the container, does nothing. Otherwise, behaves like emplace_hint except that the element 
    // is constructed as
    // value_type(std::piecewise_construct,
    //       std::forward_as_tuple(k),
    //       std::forward_as_tuple(std::forward<Args>(args)...))
    // 4) If a key equivalent to k already exists in the container, does nothing. Otherwise, behaves like emplace_hint except that the element 
    // is constructed as
    // value_type(std::piecewise_construct,
    //       std::forward_as_tuple(std::move(k)),
    //       std::forward_as_tuple(std::forward<Args>(args)...))
    // If rehashing occurs due to the insertion, all iterators are invalidated. Otherwise iterators are not affected. References are not 
    // invalidated. Rehashing occurs only if the new number of elements is greater than max_load_factor()*bucket_count().
    // auto tricky_return2 = myStrToIntMap.try_emplace(std::make_pair("key99", 1000));
    // if (tricky_return2.first != myStrToIntMap.end()) {
    //    cout << "Update key99 and return status " << boolalpha << tricky_return2.second << endl;
    // } else {
    //    cout << "Fail to update key99 and return status " << boolalpha << tricky_return2.second << endl;
    // }

    // erase(), remote the specific element in container
    // STL: Removes specified elements from the container.
    // 1) Removes the element at pos.
    // 2) Removes the elements in the range [first; last), which must be a valid range in *this.
    // 3) Removes the element (if one exists) with the key equivalent to key.
    // 4) Removes the element (if one exists) with key that compares equivalent to the value x. This overload participates in overload 
    // resolution only if Hash::is_transparent and KeyEqual::is_transparent are valid and each denotes a type, and neither iterator nor 
    // const_iterator is implicitly convertible from K. This assumes that such Hash is callable with both K and Key type, and that the 
    // KeyEqual is transparent, which, together, allows calling this function without constructing an instance of Key.
    // References and iterators to the erased elements are invalidated. Other iterators and references are not invalidated.
    // The iterator pos must be valid and dereferenceable. Thus the end() iterator (which is valid, but is not dereferenceable) cannot 
    // be used as a value for pos.
    // The order of the elements that are not erased is preserved. (This makes it possible to erase individual elements while iterating 
    // through the container.)
    cout << "Removing elements ......" << endl;
    myStrToIntMap.erase("key99");
    myStrToIntMap.erase("key100");
    myStrToIntMap.erase("key101");
    for (auto item : myStrToIntMap) {
        cout << item.first << " " << item.second << endl;
    }

    // swap(), swap content in two containers with same type defined
    // STL: Exchanges the contents of the container with those of other. Does not invoke any move, copy, or swap operations on individual 
    // elements.
    // All iterators and references remain valid. The past-the-end iterator is invalidated.
    // The Hash and KeyEqual objects must be Swappable, and they are exchanged using unqualified calls to non-member swap.
    // If std::allocator_traits<allocator_type>::propagate_on_container_swap::value is true, then the allocators are exchanged using an 
    // unqualified call to non-member swap. Otherwise, they are not swapped (and if get_allocator() != other.get_allocator(), the behavior 
    // is undefined).(since C++11)
    cout << "myStrToIntMap2 is clear now" << endl;
    myStrToIntMap2.clear();
    for (auto item : myStrToIntMap2) {
        cout << item.first << " " << item.second << endl;
    }
    cout << "myStrToIntMap2 is being swapped now" << endl;
    myStrToIntMap2.swap(myStrToIntMap);
    for (auto item : myStrToIntMap2) {
        cout << item.first << " " << item.second << endl;
    }
    // copy construct
    myStrToIntMap = myStrToIntMap2;

    // extract(), get key from container, modify key, and add it back. Not a usual way
    // STL: 1) Unlinks the node that contains the element pointed to by position and returns a node handle that owns it.
    // 2) If the container has an element with key equivalent to k, unlinks the node that contains that element from the container and 
    // returns a node handle that owns it. Otherwise, returns an empty node handle.
    // 3) Same as (2). This overload participates in overload resolution only if Hash::is_transparent and KeyEqual::is_transparent are 
    // valid and each denotes a type, and neither iterator nor const_iterator is implicitly convertible from K. This assumes that such 
    // Hash is callable with both K and Key type, and that the KeyEqual is transparent, which, together, allows calling this function 
    // without constructing an instance of Key.
    // In either case, no elements are copied or moved, only the internal pointers of the container nodes are repointed .
    // Extracting a node invalidates only the iterators to the extracted element, and preserves the relative order of the elements that 
    // are not erased. Pointers and references to the extracted element remain valid, but cannot be used while element is owned by a node 
    // handle: they become usable if the element is inserted into a container.
    auto modify = myStrToIntMap.extract("key4");
    modify.key() = "key4444";
    myStrToIntMap.insert(move(modify));
    // update value as well
    // myStrToIntMap.insert_or_assign(std::make_pair("key4444", 4444));
    for (auto item : myStrToIntMap) {
        cout << item.first << " " << item.second << endl;
    }

    // merge(), merge content from one container to another container. Note that if key is already in the to be merged container, it will 
    // be skipped and leave in original container
    // STL: Attempts to extract ("splice") each element in source and insert it into *this using the hash function and key equality 
    // predicate of *this. If there is an element in *this with key equivalent to the key of an element from source, then that element 
    // is not extracted from source. No elements are copied or moved, only the internal pointers of the container nodes are repointed. 
    // All pointers and references to the transferred elements remain valid, but now refer into *this, not into source. Iterators referring 
    // to the transferred elements and all iterators referring to *this are invalidated. Iterators to elements remaining in source remain 
    // valid.
    // The behavior is undefined if get_allocator() != source.get_allocator().
    cout << "After merge" << endl;
    myStrToIntMap2.merge(myStrToIntMap);
    for (auto item : myStrToIntMap2) {
        cout << item.first << " " << item.second << endl;
    }

    // at(), return the value of the specific key
    // STL: Returns a reference to the mapped value of the element with key equivalent to key. If no such element exists, an exception of type 
    // std::out_of_range is thrown.
    auto at_return = myStrToIntMap2.at("key1");
    cout << at_return << endl;

    // [] operation of map
    // STL: Returns a reference to the value that is mapped to a key equivalent to key, performing an insertion if such key does not already 
    // exist.
    // 1) Inserts a value_type object constructed in-place from std::piecewise_construct, std::forward_as_tuple(key), std::tuple<>() if the 
    // key does not exist. This function is equivalent to return this->try_emplace(key).first->second;. (since C++17)
    // When the default allocator is used, this results in the key being copy constructed from key and the mapped value being value-initialized.
    // -value_type must be EmplaceConstructible from std::piecewise_construct, std::forward_as_tuple(key), std::tuple<>(). When the default 
    // allocator is used, this means that key_type must be CopyConstructible and mapped_type must be DefaultConstructible.
    // 2) Inserts a value_type object constructed in-place from std::piecewise_construct, std::forward_as_tuple(std::move(key)), std::tuple<>() 
    // if the key does not exist. This function is equivalent to return this->try_emplace(std::move(key)).first->second;. (since C++17)
    // When the default allocator is used, this results in the key being move constructed from key and the mapped value being value-initialized.
    // -value_type must be EmplaceConstructible from std::piecewise_construct, std::forward_as_tuple(std::move(key)), std::tuple<>(). When the 
    // default allocator is used, this means that key_type must be MoveConstructible and mapped_type must be DefaultConstructible.
    // If an insertion occurs and results in a rehashing of the container, all iterators are invalidated. Otherwise iterators are not affected. 
    // References are not invalidated. Rehashing occurs only if the new number of elements is greater than max_load_factor()*bucket_count().
    myStrToIntMap2["key1"] = 100;
    myStrToIntMap2["key2"] = 200;
    myStrToIntMap2["key3"] = 300;
    myStrToIntMap2["key4"] = 400;

    // the given key does not exist yet, but this will automatically add (key50, 50) into container
    myStrToIntMap2["key50"] = 50;

    cout << "After new key50 is added" << endl;
    for (auto item : myStrToIntMap2) {
        cout << item.first << " " << item.second << endl;
    }

    // count(), return # of elements of specific key, here should be either 0 or 1 only as it can only handle one unique key
    // STL: 1) Returns the number of elements with key that compares equal to the specified argument key, which is either 1 or 0 since this 
    // container does not allow duplicates.
    // 2) Returns the number of elements with key that compares equivalent to the specified argument x. This overload participates in overload 
    // resolution only if Hash::is_transparent and KeyEqual::is_transparent are valid and each denotes a type. This assumes that such Hash is 
    // callable with both K and Key type, and that the KeyEqual is transparent, which, together, allows calling this function without constructing 
    // an instance of Key.
    cout << "How many key1 in the container? " << myStrToIntMap2.count("key1") << endl;
    cout << "How many key333 in the container? " << myStrToIntMap2.count("key333") << endl;

    // find(), check and see if the given key existed in the container
    // STL: 1,2) Finds an element with key equivalent to key.
    // 3,4) Finds an element with key that compares equivalent to the value x. This overload participates in overload resolution only 
    // if Hash::is_transparent and KeyEqual::is_transparent are valid and each denotes a type. This assumes that such Hash is callable with 
    // both K and Key type, and that the KeyEqual is transparent, which, together, allows calling this function without constructing an 
    // instance of Key.
    auto myReturn1 = myStrToIntMap2.find("key1");
    if (myReturn1 != myStrToIntMap2.end()) {
        cout << "Found key1 in container, key = " << myReturn1->first << ", value = " << myReturn1->second << endl;
    }

    // contains(), similar to find(), but it will return boolean status. Note this one is supported only from C++ 20 or above
    // STL: 1) Checks if there is an element with key equivalent to key in the container.
    // 2) Checks if there is an element with key that compares equivalent to the value x. This overload participates in overload resolution 
    // only if Hash::is_transparent and KeyEqual::is_transparent are valid and each denotes a type. This assumes that such Hash is callable 
    // with both K and Key type, and that the KeyEqual is transparent, which, together, allows calling this function without constructing an 
    // instance of Key.



    // equal_range(), return a pair of iterators, first one is the first iterator of the key, the second one is the first iterator that is 
    // right after the key
    // STL: 1,2) Returns a range containing all elements with key key in the container. The range is defined by two iterators, the first 
    // pointing to the first element of the wanted range and the second pointing past the last element of the range.
    // 3,4) Returns a range containing all elements in the container with key equivalent to x. This overload participates in overload 
    // resolution only if Hash::is_transparent and KeyEqual::is_transparent are valid and each denotes a type. This assumes that such Hash is 
    // callable with both K and Key type, and that the KeyEqual is transparent, which, together, allows calling this function without 
    // constructing an instance of Key.



    // bucket_count()/max_bucket_count()/bucket_size()/bucket(), same as unordered_set container



    // load_factor()/max_load_factor()/rehash()/reserve(), same as unorder_set container



    // hash_function()/key_eq(), same as unorder_set container



    // std::swap()/erase_if(), same as unorder_set container

    return 0;
}
