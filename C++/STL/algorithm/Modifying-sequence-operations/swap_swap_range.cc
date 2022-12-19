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
#include <iterator>

using namespace std;

/*

https://en.cppreference.com/w/cpp/algorithm/swap

Exchanges the given values.

1) Swaps the values a and b. This overload does not participate in overload resolution unless 
std::is_move_constructible_v<T> && std::is_move_assignable_v<T> is true. (since C++17)
2) Swaps the arrays a and b. In effect calls std::swap_ranges(a, a+N, b). This overload does 
not participate in overload resolution unless std::is_swappable_v<T2> is true. (since C++17)

Return value
(none)


可以用 swap_ranges() 算法来交换两个序列。这个算法需要 3 个正向迭代器作为参数。前两个参数分别是第一个序列的开始和结束迭代器，
第三个参数是第二个序列的开始迭代器。显然，这两个序列的长度必须相同。这个算法会返回一个迭代器，它指向第二个序列的最后一个被交换
元素的下一个位置。例如：

using Name = std::pair<string, string>; // First and second name
std::vector<Name> people {Name{"Al", "Bedo" }, Name { "Ann", "Ounce"}, Name{"Jo"，"King"}};
std::list<Name> folks {Name{"Stan", "Down"}, Name{"Dan","Druff"},Name {"Bea", "Gone"}};
std::swap_ranges(std::begin(people), std::begin(people) + 2, ++std::begin(folks));
std::for_each(std::begin(people), std::end(people),[](const Name& name) {std: :cout << '"' << name.first << " " 
<< name.second << "\" ";});
std::cout << std::endl; // "Dan Druff" "Bea Gone" "Jo King"
std::for_each (std::begin (folks) , std::end (folks) ,[] (const Name& name){std::cout << '"' << name.first << " " 
<< name.second << "\" "; });
std::cout << std::endl;// "Stan Down" "Al Bedo" "Ann Ounce"

这里使用 vector 和 list 容器来保存 pair<string,string> 类型的元素，pair<string,string> 用来表示名称。swap_ranges() 
算法被用来交换 people 的前两个元素和 folks 的后两个元素。这里并没有为了将 pair 对象写入流而重载 operator<<() 函数，因此 
copy() 无法用输出流迭代器来列出容器的内容。为了生成输出，选择使用 for_each() 算法将 lambda 表达式运用到容器的每个元素上。
这个 lambda 表达式只会将传给它的 Name 元素的成员变量写入标准输出流。注释展示了执行这段代码后输出的结果：

定义在 utility 头文件中的 swap() 算法的重载函数的模板原型为：
template<typename T1, typename T2> void swap(std::pair<T1,T2> left, std::pair<T1,T2> right);

这段代码会对 pair<T1,T2> 对象进行交换，在前面的代码段中也可以用 swap_ranges() 来交换元素。

用来交换两个 T 类型对象的 swap() 模板也被定义在 utility 头文件中。除了 pair 对象的重载之外，utility 文件头中也有可以
交换任何类型的容器对象的模板的重载。也就是说，可以交换两个 list<T> 容器或者两个 set<T> 容器但不能是一个 list<T> 和 
vector<T>，也不能是一个 list<T1> 和一个 list<T2>。

另一个 swap() 模板的重载可以交换两个相同类型的数组。也有其他几个 swap() 的重载，它们可以用来交换其他类型的对象，包含元组
和智能指针类型，正如本章前面所述。iter_swap() 算法有一些不同，它会交换两个正向迭代器所指向的元素。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业
故事+学习历程+工作记录+生活日常+编程资料。

*/

namespace Ns {
    class A {
        int id{};
    
        friend void swap(A& lhs, A& rhs) {
            std::cout << "swap(" << lhs << ", " << rhs << ")\n";
            std::swap(lhs.id, rhs.id);
        }
    
        friend std::ostream& operator<< (std::ostream& os, A const& a) {
            return os << "A::id=" << a.id;
        }
    
    public:
        A(int i) : id{i} { }
        A(A const&) = delete;
        A& operator = (A const&) = delete;
    };
}

// example from https://en.cppreference.com/w/cpp/algorithm/swap 
int main()
{
    int a = 5, b = 3;
    std::cout << a << ' ' << b << '\n';
    std::swap(a,b);
    std::cout << a << ' ' << b << '\n';
 
    Ns::A p{6}, q{9};
    std::cout << p << ' ' << q << '\n';

    // cannot add "std::" in below swap as the object A has its owned swap function
    //  std::swap(p, q);  // error, type requirements are not satisfied
    swap(p, q);  // OK, ADL finds the appropriate friend `swap`
    std::cout << p << ' ' << q << '\n';

    // swap whole elements in two vectors by container's swap() function
    vector<int> v1 = {1, 3, 5};
    vector<int> v2 = {2, 4, 6};
    cout << "Before swap by using vector's swap():" << endl;
    for_each(v1.begin(), v1.end(), [](int v){ cout << v << endl;});
    for_each(v2.begin(), v2.end(), [](int v){ cout << v << endl;});
    v1.swap(v2);
    cout << "After swap by using vector's swap():" << endl;
    for_each(v1.begin(), v1.end(), [](int v){ cout << v << endl;});
    for_each(v2.begin(), v2.end(), [](int v){ cout << v << endl;});

    // by using std::swap()
    std::swap(v1, v2);
    cout << "After swap by std::swap():" << endl;
    for_each(v1.begin(), v1.end(), [](int v){ cout << v << endl;});
    for_each(v2.begin(), v2.end(), [](int v){ cout << v << endl;});

    // swap individual element
    std::swap(v1[1], v2[1]);
    cout << "After swap 2nd element by std::swap():" << endl;
    for_each(v1.begin(), v1.end(), [](int v){ cout << v << endl;});
    for_each(v2.begin(), v2.end(), [](int v){ cout << v << endl;});

    return 0;
    // 5 3
    // 3 5
    // A::id=6 A::id=9
    // swap(A::id=6, A::id=9)
    // A::id=9 A::id=6
    // Before swap by using vector's swap():
    // 1
    // 3
    // 5
    // 2
    // 4
    // 6
    // After swap by using vector's swap():
    // 2
    // 4
    // 6
    // 1
    // 3
    // 5
    // After swap by std::swap():
    // 1
    // 3
    // 5
    // 2
    // 4
    // 6
    // After swap 2nd element by std::swap():
    // 1
    // 4
    // 5
    // 2
    // 3
    // 6
}


