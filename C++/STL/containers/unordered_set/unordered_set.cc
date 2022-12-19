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

我们知道，C++ 11 为 STL 标准库增添了 4 种无序（哈希）容器，前面已经对 unordered_map 和 unordered_multimap 容器做了详细的介绍，
本节再讲解一种无序容器，即 unordered_set 容器。

unordered_set 容器，可直译为“无序 set 容器”，即 unordered_set 容器和 set 容器很像，唯一的区别就在于 set 容器会自行对存储的数据
进行排序，而 unordered_set 容器不会。

总的来说，unordered_set 容器具有以下几个特性：
不再以键值对的形式存储数据，而是直接存储数据的值；
容器内部存储的各个元素的值都互不相等，且不能被修改。
不会对内部存储的数据进行排序（这和该容器底层采用哈希表结构存储数据有关，可阅读《C++ STL无序容器底层实现原理》一文做详细了解）；
对于 unordered_set 容器不以键值对的形式存储数据，读者也可以这样认为，即 unordered_set 存储的都是键和值相等的键值对，为了节省存储
空间，该类容器在实际存储时选择只存储每个键值对的值。

另外，实现 unordered_set 容器的模板类定义在<unordered_set>头文件，并位于 std 命名空间中。这意味着，如果程序中需要使用该类型容器，
则首先应该包含如下代码：

#include <unordered_set>
using namespace std;
注意，第二行代码不是必需的，但如果不用，则程序中只要用到该容器时，必须手动注明 std 命名空间（强烈建议初学者使用）。

unordered_set 容器的类模板定义如下：
template < class Key,            //容器中存储元素的类型
           class Hash = hash<Key>,    //确定元素存储位置所用的哈希函数
           class Pred = equal_to<Key>,   //判断各个元素是否相等所用的函数
           class Alloc = allocator<Key>   //指定分配器对象的类型
           > class unordered_set;
可以看到，以上 4 个参数中，只有第一个参数没有默认值，这意味着如果我们想创建一个 unordered_set 容器，至少需要手动传递 1 个参数。
事实上，在 99% 的实际场景中最多只需要使用前 3 个参数（各自含义如表 1 所示），最后一个参数保持默认值即可。

表 1 unordered_set模板类定义
参数	含义
Key	确定容器存储元素的类型，如果读者将 unordered_set 看做是存储键和值相同的键值对的容器，则此参数则用于确定各个键值对的键和值的
类型，因为它们是完全相同的，因此一定是同一数据类型的数据。
Hash = hash<Key>	指定 unordered_set 容器底层存储各个元素时，所使用的哈希函数。需要注意的是，默认哈希函数 hash<Key> 只适用于
基本数据类型（包括 string 类型），而不适用于自定义的结构体或者类。
Pred = equal_to<Key>	unordered_set 容器内部不能存储相等的元素，而衡量 2 个元素是否相等的标准，取决于该参数指定的函数。 默认
情况下，使用 STL 标准库中提供的 equal_to<key> 规则，该规则仅支持可直接用 == 运算符做比较的数据类型。
注意，如果 unordered_set 容器中存储的元素为自定义的数据类型，则默认的哈希函数 hash<key> 以及比较函数 equal_to<key> 将不再适用，
只能自己设计适用该类型的哈希函数和比较函数，并显式传递给 Hash 参数和 Pred 参数。至于如何实现自定义，后续章节会做详细讲解。

创建C++ unordered_set容器
前面介绍了如何创建 unordered_map 和 unordered_multimap 容器，值得一提的是，创建它们的所有方式完全适用于 unordereded_set 容器。
不过，考虑到一些读者可能尚未学习其它无序容器，因此这里还是讲解一下创建 unordered_set 容器的几种方法。

1) 通过调用 unordered_set 模板类的默认构造函数，可以创建空的 unordered_set 容器。比如：
std::unordered_set<std::string> uset;
如果程序已经引入了 std 命名空间，这里可以省略所有的 std::。

由此，就创建好了一个可存储 string 类型值的 unordered_set 容器，该容器底层采用默认的哈希函数 hash<Key> 和比较函数 equal_to<Key>。

2) 当然，在创建 unordered_set 容器的同时，可以完成初始化操作。比如：
std::unordered_set<std::string> uset{ "http://c.biancheng.net/c/",
                                      "http://c.biancheng.net/java/",
                                      "http://c.biancheng.net/linux/" };
通过此方法创建的 uset 容器中，就包含有 3 个 string 类型元素。

3) 还可以调用 unordered_set 模板中提供的复制（拷贝）构造函数，将现有 unordered_set 容器中存储的元素全部用于为新建 unordered_set 
容器初始化。

例如，在第二种方式创建好 uset 容器的基础上，再创建并初始化一个 uset2 容器：
std::unordered_set<std::string> uset2(uset);
由此，umap2 容器中就包含有 umap 容器中所有的元素。

除此之外，C++ 11 标准中还向 unordered_set 模板类增加了移动构造函数，即以右值引用的方式，利用临时 unordered_set 容器中存储的所有元素，
给新建容器初始化。例如：

//返回临时 unordered_set 容器的函数
std::unordered_set <std::string> retuset() {
    std::unordered_set<std::string> tempuset{ "http://c.biancheng.net/c/",
                                              "http://c.biancheng.net/java/",
                                              "http://c.biancheng.net/linux/" };
    return tempuset;
}
//调用移动构造函数，创建 uset 容器
std::unordered_set<std::string> uset(retuset());
注意，无论是调用复制构造函数还是拷贝构造函数，必须保证 2 个容器的类型完全相同。


4) 当然，如果不想全部拷贝，可以使用 unordered_set 类模板提供的迭代器，在现有 unordered_set 容器中选择部分区域内的元素，为新建 
unordered_set 容器初始化。例如：

//传入 2 个迭代器，
std::unordered_set<std::string> uset2(++uset.begin(),uset.end());
通过此方式创建的 uset2 容器，其内部就包含 uset 容器中除第 1 个元素外的所有其它元素。
C++ unordered_set容器的成员方法
unordered_set 类模板中，提供了如表 2 所示的成员方法。

表 2 unordered_set 类模板成员方法
成员方法	功能
begin()	返回指向容器中第一个元素的正向迭代器。
end();	返回指向容器中最后一个元素之后位置的正向迭代器。
cbegin()	和 begin() 功能相同，只不过其返回的是 const 类型的正向迭代器。
cend()	和 end() 功能相同，只不过其返回的是 const 类型的正向迭代器。
empty()	若容器为空，则返回 true；否则 false。
size()	返回当前容器中存有元素的个数。
max_size()	返回容器所能容纳元素的最大个数，不同的操作系统，其返回值亦不相同。
find(key)	查找以值为 key 的元素，如果找到，则返回一个指向该元素的正向迭代器；反之，则返回一个指向容器中最后一个元素之后位置的迭代器
（如果 end() 方法返回的迭代器）。
count(key)	在容器中查找值为 key 的元素的个数。
equal_range(key)	返回一个 pair 对象，其包含 2 个迭代器，用于表明当前容器中值为 key 的元素所在的范围。
emplace()	向容器中添加新元素，效率比 insert() 方法高。
emplace_hint()	向容器中添加新元素，效率比 insert() 方法高。
insert()	向容器中添加新元素。
erase()	删除指定元素。
clear()	清空容器，即删除容器中存储的所有元素。
swap()	交换 2 个 unordered_set 容器存储的元素，前提是必须保证这 2 个容器的类型完全相等。
bucket_count()	返回当前容器底层存储元素时，使用桶（一个线性链表代表一个桶）的数量。
max_bucket_count()	返回当前系统中，unordered_set 容器底层最多可以使用多少桶。
bucket_size(n)	返回第 n 个桶中存储元素的数量。
bucket(key)	返回值为 key 的元素所在桶的编号。
load_factor()	返回 unordered_set 容器中当前的负载因子。负载因子，指的是的当前容器中存储元素的数量（size()）和使用桶数（bucket_count()）
的比值，即 load_factor() = size() / bucket_count()。
max_load_factor()	返回或者设置当前 unordered_set 容器的负载因子。
rehash(n)	将当前容器底层使用桶的数量设置为 n。
reserve()	将存储桶的数量（也就是 bucket_count() 方法的返回值）设置为至少容纳 count 个元（不超过最大负载因子）所需的数量，并重新整理容器。
hash_function()	返回当前容器使用的哈希函数对象。
注意，此容器模板类中没有重载 [ ] 运算符，也没有提供 at() 成员方法。不仅如此，由于 unordered_set 容器内部存储的元素值不能被修改，因此无论使用
那个迭代器方法获得的迭代器，都不能用于修改容器中元素的值。

另外，对于实现互换 2 个相同类型 unordered_set 容器的所有元素，除了调用表 2 中的 swap() 成员方法外，还可以使用 STL 标准库提供的 swap() 
非成员函数，它们具有相同的名称，用法也相同（都只需要传入 2 个参数即可），仅是调用方式上有差别。

下面的样例演示了表 2 中部分成员方法的用法：
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
int main()
{
    //创建一个空的unordered_set容器
    std::unordered_set<std::string> uset;
    //给 uset 容器添加数据
    uset.emplace("http://c.biancheng.net/java/");
    uset.emplace("http://c.biancheng.net/c/");
    uset.emplace("http://c.biancheng.net/python/");
    //查看当前 uset 容器存储元素的个数
    cout << "uset size = " << uset.size() << endl;
    //遍历输出 uset 容器存储的所有元素
    for (auto iter = uset.begin(); iter != uset.end(); ++iter) {
        cout << *iter << endl;
    }
    return 0;
}
程序执行结果为：
uset size = 3
http://c.biancheng.net/java/
http://c.biancheng.net/c/
http://c.biancheng.net/python/

注意，表 2 中绝大多数成员方法的用法，都和 unordered_map 容器提供的同名成员方法相同，读者可翻阅前面的文章做详细了解，当然也可以到 C++
STL标准库官网查询。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业故事+学习历程+
工作记录+生活日常+编程资料。

*/

using namespace std;
static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();

// solution
void printMySetStr(string element) {
    cout << element << " ";
}

template<typename Os, typename Container>
inline Os& operator<<(Os& os, Container const& container)
{
    os << "{ ";
    for (const auto& item : container) {
        os << item << ' ';
    }
    return os << "}";
} 

// main
int main() {
    // STL unordered_set study
    unordered_set<int> myUnOrderedInt_Set1;
    unordered_set<double> myUnOrderedDouble_Set2;
    unordered_set<string> myUnOrderedString_Set3;

    // find target within vector, two numbers sum up = target
    vector<int> myV = {1, 3, 5, 7, 9};
    int target = 12;

    for (int i = 0; i < myV.size(); i++) {
        myUnOrderedInt_Set1.insert(myV[i]);
    }

    for (int i = 0; i < myV.size(); i++) {
        int tmp = target - myV[i];
        if (myUnOrderedInt_Set1.find(tmp) != myUnOrderedInt_Set1.end()) {
            cout << "Find answer of " << myV[i] << " and " << tmp << endl;
        }
    }

    // begin()/end()/cbegin()/cend(), iterator to all elements in set. Note that for unordered_set/unordered_map,
    // there is no such rbegin()/rend() usage
    // STL: Returns an iterator to the first element of the unordered_set.
    // If the unordered_set is empty, the returned iterator will be equal to end().
    // STL: Returns an iterator to the element following the last element of the unordered_set.
    // This element acts as a placeholder; attempting to access it results in undefined behavior.
    // search key of string
    myUnOrderedString_Set3.emplace("key1");
    myUnOrderedString_Set3.emplace("key2");
    myUnOrderedString_Set3.emplace("key3");
    myUnOrderedString_Set3.emplace("key123");
    myUnOrderedString_Set3.emplace("key321");

    if (myUnOrderedString_Set3.find("key1234")!= myUnOrderedString_Set3.end()) {
        cout << "Found key1234" << endl;
    } else {
        cout << "key1234 doesn't exist. Here are keys in unordered_set: " << endl;
        for (auto item = myUnOrderedString_Set3.begin(); item != myUnOrderedString_Set3.end(); item++) {
            cout << *item << endl;
        }
    }

    // empty(), check if the set is empty or not
    // STL: Checks if the container has no elements, i.e. whether begin() == end().
    cout << boolalpha << "myUnOrderedString_Set3 is empty? " << myUnOrderedString_Set3.empty()? "yes" : "no";
    cout << endl;

    // size(), current # of elements in the set
    cout << "How many items in myUnOrderedString_Set3? " << myUnOrderedString_Set3.size() << endl;

    // max_size(), max # of elements can be added in the set based on current system
    // STL: Returns the maximum number of elements the container is able to hold due to system or library 
    // implementation limitations, i.e. std::distance(begin(), end()) for the largest container.
    cout << "Max size of this system can hold elements in the set? " << myUnOrderedString_Set3.max_size() << endl;

    // clear(), remove all elements in the set
    // STL: Erases all elements from the container. After this call, size() returns zero.
    // Invalidates any references, pointers, or iterators referring to contained elements. May also invalidate past-the-end iterators.
    myUnOrderedString_Set3.clear();
    cout << "How many items in myUnOrderedString_Set3 after clear() call? " << myUnOrderedString_Set3.size() << endl;

    // insert(), add one element into unordered_set, the key and value are same as the given key
    // STL: Inserts element(s) into the container, if the container doesn't already contain an element with an equivalent key.
    // 1-2) Inserts value.
    // 3-4) Inserts value, using hint as a non-binding suggestion to where the search should start.
    // 5) Inserts elements from range [first, last). If multiple elements in the range have keys that compare equivalent, it is unspecified 
    // which element is inserted (pending LWG2844).
    // 6) Inserts elements from initializer list ilist. If multiple elements in the range have keys that compare equivalent, it is unspecified 
    // which element is inserted (pending LWG2844).
    // 7) If nh is an empty node handle, does nothing. Otherwise, inserts the element owned by nh into the container , if the container doesn't 
    // already contain an element with a key equivalent to nh.key(). The behavior is undefined if nh is not empty and 
    // get_allocator() != nh.get_allocator().
    // 8) If nh is an empty node handle, does nothing and returns the end iterator. Otherwise, inserts the element owned by nh into the 
    // container, if the container doesn't already contain an element with a key equivalent to nh.key(), and returns the iterator pointing 
    // to the element with key equivalent to nh.key() (regardless of whether the insert succeeded or failed). If the insertion succeeds, 
    // nh is moved from, otherwise it retains ownership of the element. The element is inserted as close as possible to hint. The behavior 
    // is undefined if nh is not empty and get_allocator() != nh.get_allocator().
    // If rehashing occurs due to the insertion, all iterators are invalidated. Otherwise iterators are not affected. References are not 
    // invalidated. Rehashing occurs only if the new number of elements is greater than max_load_factor()*bucket_count(). If the insertion 
    // is successful, pointers and references to the element obtained while it is held in the node handle are invalidated, and pointers and 
    // references obtained to that element before it was extracted become valid. (since C++17)
    myUnOrderedDouble_Set2.insert(1.2);
    myUnOrderedDouble_Set2.insert(2.3);
    myUnOrderedDouble_Set2.insert(3.4);
    myUnOrderedDouble_Set2.insert(4.5);
    cout << "myUnOrderedDouble_Set2 now has following items: " << endl;
    for (auto item = myUnOrderedDouble_Set2.begin(); item != myUnOrderedDouble_Set2.end(); item++) {
        cout << *item << endl;
    }

    // emplace(); construct element directly into unordered_set
    // STL: Inserts a new element into the container constructed in-place with the given args if there is no element with the key in the 
    // container.
    // Careful use of emplace allows the new element to be constructed while avoiding unnecessary copy or move operations. The constructor 
    // of the new element is called with exactly the same arguments as supplied to emplace, forwarded via std::forward<Args>(args).... 
    // The element may be constructed even if there already is an element with the key in the container, in which case the newly constructed 
    // element will be destroyed immediately.
    // If rehashing occurs due to the insertion, all iterators are invalidated. Otherwise iterators are not affected. References are not 
    // invalidated. Rehashing occurs only if the new number of elements is greater than max_load_factor()*bucket_count().
    myUnOrderedString_Set3.emplace("newStr1");
    myUnOrderedString_Set3.emplace("Str2new");
    myUnOrderedString_Set3.emplace("newStr3new");
    for_each(myUnOrderedString_Set3.begin(), myUnOrderedString_Set3.end(), printMySetStr);
    cout << endl;

    // emplace_hint(), give additional hint to add new element into unordered_set, but not guarantee
    // STL: Inserts a new element to the container, using hint as a suggestion where the element should go. The element is constructed in-place, 
    // i.e. no copy or move operations are performed.
    // The constructor of the element is called with exactly the same arguments as supplied to the function, forwarded with std::forward<Args>(args)....
    // If rehashing occurs due to the insertion, all iterators are invalidated. Otherwise iterators are not affected. References are not 
    // invalidated. Rehashing occurs only if the new number of elements is greater than max_load_factor()*bucket_count().
    myUnOrderedString_Set3.emplace_hint(myUnOrderedString_Set3.begin(), "str4Hint");
    for_each(myUnOrderedString_Set3.begin(), myUnOrderedString_Set3.end(), printMySetStr);
    cout << endl;
    myUnOrderedString_Set3.emplace_hint(myUnOrderedString_Set3.end(), "str5Hint");
    for_each(myUnOrderedString_Set3.begin(), myUnOrderedString_Set3.end(), printMySetStr);
    cout << endl;

    // erase(), remove a specific element from unordered_set
    // STL: Removes specified elements from the container.
    // 1) Removes the element at pos. Only one overload is provided if iterator and const_iterator are the same type.
    // 2) Removes the elements in the range [first; last), which must be a valid range in *this.
    // 3) Removes the element (if one exists) with the key equivalent to key.
    // 4) Removes the element (if one exists) with key that compares equivalent to the value x. This overload participates in overload 
    // resolution only if Hash::is_transparent and KeyEqual::is_transparent are valid and each denotes a type, and neither iterator nor 
    // const_iterator is implicitly convertible from K. This assumes that such Hash is callable with both K and Key type, and that the 
    // KeyEqual is transparent, which, together, allows calling this function without constructing an instance of Key.
    // References and iterators to the erased elements are invalidated. Other iterators and references are not invalidated.
    // The iterator pos must be valid and dereferenceable. Thus the end() iterator (which is valid, but is not dereferenceable) cannot be 
    // used as a value for pos.
    // The order of the elements that are not erased is preserved. (This makes it possible to erase individual elements while iterating 
    // through the container.)
    int return1 = myUnOrderedString_Set3.erase("str6");
    if (return1 == 0) {
        cout << "No element is removed" << endl;
    } else {
        cout << "str6 is removed" << endl;
    }
    int return2 = myUnOrderedString_Set3.erase("str5Hint");
    if (return2 == 0) {
        cout << "No element is removed" << endl;
    } else {
        cout << "str5Hint is removed" << endl;
    }

    // swap(), swap two unordered_set with same type
    // STL: Exchanges the contents of the container with those of other. Does not invoke any move, copy, or swap operations on individual 
    // elements.
    // All iterators and references remain valid. The past-the-end iterator is invalidated.
    // The Hash and KeyEqual objects must be Swappable, and they are exchanged using unqualified calls to non-member swap.
    // If std::allocator_traits<allocator_type>::propagate_on_container_swap::value is true, then the allocators are exchanged using an 
    // unqualified call to non-member swap. Otherwise, they are not swapped (and if get_allocator() != other.get_allocator(), the behavior 
    // is undefined).(since C++11)
    cout << "swap myUnOrderedString_Set3 and myUnOrderedString_Set4" << endl;
    unordered_set<string> myUnOrderedString_Set4;
    cout << "Before: " << endl;
    for_each(myUnOrderedString_Set3.begin(), myUnOrderedString_Set3.end(), printMySetStr);
    cout << endl;
    for_each(myUnOrderedString_Set4.begin(), myUnOrderedString_Set4.end(), printMySetStr);
    cout << endl;
    myUnOrderedString_Set3.swap(myUnOrderedString_Set4);
    cout << "After: " << endl;
    for_each(myUnOrderedString_Set3.begin(), myUnOrderedString_Set3.end(), printMySetStr);
    cout << endl;
    for_each(myUnOrderedString_Set4.begin(), myUnOrderedString_Set4.end(), printMySetStr);
    cout << endl;
    myUnOrderedString_Set3 = myUnOrderedString_Set4;

    // extract(), in general, for set or unordered_set, the given key itself is also a value
    // change key in set or unordered_set is not usual, but this is a way.
    // Note that when it is being added back, still need to call "insert()" and with "move()" to update that element (key/value) 
    // accordingly
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
    cout << "After changing str4Hint to str4HintNew" << endl;
    auto item = myUnOrderedString_Set3.extract("str4Hint");
    item.value() = "str4HintNew";
    myUnOrderedString_Set3.insert(move(item));
    for_each(myUnOrderedString_Set3.begin(), myUnOrderedString_Set3.end(), printMySetStr);
    cout << endl;

    // merge(), merge elements from ont to another, as this is unordered_Set, not unordered_multiset, if there are duplicated one,
    // it will leave in original unordered_set
    // STL: Attempts to extract ("splice") each element in source and insert it into *this using the hash function and key equality 
    // predicate of *this. If there is an element in *this with key equivalent to the key of an element from source, then that element 
    // is not extracted from source. No elements are copied or moved, only the internal pointers of the container nodes are repointed. 
    // All pointers and references to the transferred elements remain valid, but now refer into *this, not into source. Iterators referring 
    // to the transferred elements and all iterators referring to *this are invalidated. Iterators to elements remaining in source remain 
    // valid.
    // The behavior is undefined if get_allocator() != source.get_allocator().
    cout << "Before merge, myUnOrderedString_Set4" << endl;
    for_each(myUnOrderedString_Set4.begin(), myUnOrderedString_Set4.end(), printMySetStr);
    cout << endl;
    for_each(myUnOrderedString_Set3.begin(), myUnOrderedString_Set3.end(), printMySetStr);
    cout << endl;
    cout << "Merge myUnOrderedString_Set3 to myUnOrderedString_Set4, it should have str4HintNew" << endl;
    myUnOrderedString_Set4.merge(myUnOrderedString_Set3);
    for_each(myUnOrderedString_Set4.begin(), myUnOrderedString_Set4.end(), printMySetStr);
    cout << endl;
    cout << "myUnOrderedString_Set3 should miss only one str4HintNew" << endl;
    for_each(myUnOrderedString_Set3.begin(), myUnOrderedString_Set3.end(), printMySetStr);
    cout << endl;

    // count(), return number of specific element in unordered_set, this should be either 0 or 1 here
    // as unordered_set can only hold one element, no duplicated one
    // STL: 1) Returns the number of elements with key that compares equal to the specified argument key, which is either 1 or 0 
    // since this container does not allow duplicates.
    // 2) Returns the number of elements with key that compares equivalent to the specified argument x. This overload participates 
    // in overload resolution only if Hash::is_transparent and KeyEqual::is_transparent are valid and each denotes a type. This assumes 
    // that such Hash is callable with both K and Key type, and that the KeyEqual is transparent, which, together, allows calling 
    // this function without constructing an instance of Key.
    cout << "Count() of newStr3new returns " << myUnOrderedString_Set3.count("newStr3new") << endl;
    cout << "Count() of xyz returns " << myUnOrderedString_Set3.count("xyz") << endl;

    // find(), look up one specific element, and return iterator. If not found, it will be same as end() iterator
    // STL: 1,2) Finds an element with key equivalent to key.
    // 3,4) Finds an element with key that compares equivalent to the value x. This overload participates in overload resolution only 
    // if Hash::is_transparent and KeyEqual::is_transparent are valid and each denotes a type. This assumes that such Hash is callable 
    // with both K and Key type, and that the KeyEqual is transparent, which, together, allows calling this function without constructing 
    // an instance of Key.
    auto item2 = myUnOrderedString_Set3.find("newStr3new");
    if (item2 == myUnOrderedString_Set3.end()) {
        cout << "Cannot find newStr3new" << endl;
    } else {
        cout << "Find newStr3new" << endl;
    }

    // contains(), similar to find(), but this one will return boolean
    // STL: 1) Checks if there is an element with key equivalent to key in the container.
    // 2) Checks if there is an element with key that compares equivalent to the value x. This overload participates in overload resolution 
    // only if Hash::is_transparent and KeyEqual::is_transparent are valid and each denotes a type. This assumes that such Hash is callable 
    // with both K and Key type, and that the KeyEqual is transparent, which, together, allows calling this function without constructing an 
    // instance of Key.
    // This function is supported only if C++ 20 or after



    // equal_range(), return a pair of two iterators, first one pointed to the iterator that pointed to the first element of key, second
    // one pointed to the iterator that is right after the key
    // STL: 1,2) Returns a range containing all elements with key key in the container. The range is defined by two iterators, the first 
    // pointing to the first element of the wanted range and the second pointing past the last element of the range.
    // 3,4) Returns a range containing all elements in the container with key equivalent to x. This overload participates in overload 
    // resolution only if Hash::is_transparent and KeyEqual::is_transparent are valid and each denotes a type. This assumes that such Hash 
    // is callable with both K and Key type, and that the KeyEqual is transparent, which, together, allows calling this function without 
    // constructing an instance of Key.



    // bucket_count()/max_bucket_count()/bucket_size(), return number of buckets in the current unordered_set
    // Note that bucket_size() will need to pvovide a bucket index value
    // STL: Returns the number of buckets in the container.
    // STL: Returns the maximum number of buckets the container is able to hold due to system or library implementation limitations.
    // STL: Returns the number of elements in the bucket with index n.
    cout << "bucket_count() is " << myUnOrderedString_Set4.bucket_count() << endl; 
    cout << "max_bucket_count() is " << myUnOrderedString_Set4.max_bucket_count() << endl;
    cout << "bucket_size(0) is " << myUnOrderedString_Set4.bucket_size(0) << endl;

    // load_factor()/max_load_factor(), return the factor info of container
    // STL: Returns the average number of elements per bucket, that is, size() divided by bucket_count().
    // STL Manages the maximum load factor (number of elements per bucket). The container automatically increases the number of buckets 
    // if the load factor exceeds this threshold.
    // 1) Returns current maximum load factor.
    // 2) Sets the maximum load factor to ml.
    cout << "load_factor() is " << myUnOrderedString_Set4.load_factor() << endl;
    cout << "max_load_factor() is " << myUnOrderedString_Set4.max_load_factor() << endl;

    // rehash(), re-generate hash table based on given specified number
    // STL: Sets the number of buckets to count and rehashes the container, i.e. puts the elements into appropriate buckets considering 
    // that total number of buckets has changed. If the new number of buckets makes load factor more than maximum load factor 
    // (count < size() / max_load_factor()), then the new number of buckets is at least size() / max_load_factor().
    cout << "bucket_count() is " << myUnOrderedString_Set3.bucket_count() << endl; 
    cout << "bucket_size(0) is " << myUnOrderedString_Set3.bucket_size(0) << endl;
    myUnOrderedString_Set3.rehash(10);
    cout << "bucket_count() is " << myUnOrderedString_Set3.bucket_count() << endl; 
    cout << "bucket_size(0) is " << myUnOrderedString_Set3.bucket_size(0) << endl;

    // reserve(), reserve specific buckets based on given number
    // STL: Sets the number of buckets to the number needed to accomodate at least count elements without exceeding maximum load factor 
    // and rehashes the container, i.e. puts the elements into appropriate buckets considering that total number of buckets has changed. 
    // Effectively calls rehash(std::ceil(count / max_load_factor())).
    myUnOrderedString_Set4.reserve(1000);
    cout << "bucket_count() is " << myUnOrderedString_Set4.bucket_count() << endl; 
    cout << "bucket_size(0) is " << myUnOrderedString_Set4.bucket_size(0) << endl;

    // hash_function(), return the hash function used in this container
    // STL: Returns the function that hashes the keys.



    // key_eq()
    // STL: Returns the function that compares keys for equality.



    // operator==,!=(std::unordered_set)
    // STL: Compares the contents of two unordered containers.
    // The contents of two unordered containers lhs and rhs are equal if the following conditions hold:
    // lhs.size() == rhs.size()
    // each group of equivalent elements [lhs_eq1, lhs_eq2) obtained from lhs.equal_range(lhs_eq1) has a corresponding group of equivalent 
    // elements in the other container [rhs_eq1, rhs_eq2) obtained from rhs.equal_range(rhs_eq1), that has the following properties:
    // std::distance(lhs_eq1, lhs_eq2) == std::distance(rhs_eq1, rhs_eq2).
    // std::is_permutation(lhs_eq1, lhs_eq2, rhs_eq1) == true.
    // The behavior is undefined if Key is not EqualityComparable.
    // The behavior is also undefined if hash_function() and key_eq() do (until C++20)key_eq() does (since C++20) not have the same behavior 
    // on lhs and rhs or if operator== for Key is not a refinement of the partition into equivalent-key groups introduced by key_eq() (that is,
    // if two elements that compare equal using operator== fall into different partitions)
    // The != operator is synthesized from operator==.(since C++20)



    // std::swap(), swap content in two container, same data type is required
    // STL: Specializes the std::swap algorithm for std::unordered_set. Swaps the contents of lhs and rhs. Calls lhs.swap(rhs).
    std::unordered_set<int> alice{1, 2, 3};
    std::unordered_set<int> bob{7, 8, 9, 10};
    auto print = [](const int& n) { std::cout << ' ' << n; };
 
    // Print state before swap
    std::cout << "alice:";
    std::for_each(alice.begin(), alice.end(), print);
    std::cout << "\n" "bob  :";
    std::for_each(bob.begin(), bob.end(), print);
    std::cout << '\n';
    std::cout << "-- SWAP\n";
    std::swap(alice, bob);

    // Print state after swap
    std::cout << "alice:";
    std::for_each(alice.begin(), alice.end(), print);
    std::cout << "\n" "bob  :";
    std::for_each(bob.begin(), bob.end(), print);
    std::cout << '\n';

    // erase_if(), remove the specific element if condition matched
    // STL: Erases all elements that satisfy the predicate pred from the container. Equivalent to
    // auto old_size = c.size();
    // for (auto i = c.begin(), last = c.end(); i != last; ) {
    //  if (pred(*i)) {
    //    i = c.erase(i);
    //  } else {
    //    ++i;
    //  }
    // }
    // return old_size - c.size();

    // std::unordered_set data { 3, 3, 4, 5, 5, 6, 6, 7, 2, 1, 0 };
    // std::cout << "Original:\n" << data << '\n';
    // auto divisible_by_3 = [](auto const& x) { return (x % 3) == 0; };
    //
    // const auto count = std::erase_if(data, divisible_by_3);
    //
    // std::cout << "Erase all items divisible by 3:\n" << data << '\n'
    //           << count << " items erased.\n";


    return 0;
}
