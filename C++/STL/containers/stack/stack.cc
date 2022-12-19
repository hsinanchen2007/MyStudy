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

在详解什么是容器适配器之前，初学者首先要理解适配器的含义。

其实，容器适配器中的“适配器”，和生活中常见的电源适配器中“适配器”的含义非常接近。我们知道，无论是电脑、手机还是其它电器，
充电时都无法直接使用 220V 的交流电，为了方便用户使用，各个电器厂商都会提供一个适用于自己产品的电源线，它可以将 220V 
的交流电转换成适合电器使用的低压直流电。

从用户的角度看，电源线扮演的角色就是将原本不适用的交流电变得适用，因此其又被称为电源适配器。

再举一个例子，假设一个代码模块 A，它的构成如下所示：
class A{
public:
    void f1(){}
    void f2(){}
    void f3(){}
    void f4(){}
};
现在我们需要设计一个模板 B，但发现，其实只需要组合一下模块 A 中的 f1()、f2()、f3()，就可以实现模板 B 需要的功能。
其中 f1() 单独使用即可，而 f2() 和 f3() 需要组合起来使用，如下所示：
class B{
private:
    A * a;
public:
    void g1(){
        a->f1();
    }
    void g2(){
        a->f2();
        a->f3();
    }
};
可以看到，就如同是电源适配器将不适用的交流电变得适用一样，模板 B 将不适合直接拿来用的模板 A 变得适用了，因此我们
可以将模板 B 称为 B 适配器。

容器适配器也是同样的道理，简单的理解容器适配器，其就是将不适用的序列式容器（包括 vector、deque 和 list）变得适用。
容器适配器的底层实现和模板 A、B 的关系是完全相同的，即通过封装某个序列式容器，并重新组合该容器中包含的成员函数，
使其满足某些特定场景的需要。容器适配器本质上还是容器，只不过此容器模板类的实现，利用了大量其它基础容器模板类中已经
写好的成员函数。当然，如果必要的话，容器适配器中也可以自创新的成员函数。

需要注意的是，STL 中的容器适配器，其内部使用的基础容器并不是固定的，用户可以在满足特定条件的多个基础容器中自由选择。
STL容器适配器的种类
STL 提供了 3 种容器适配器，分别为 stack 栈适配器、queue 队列适配器以及 priority_queue 优先权队列适配器。其中，
各适配器所使用的默认基础容器以及可供用户选择的基础容器，如表 1 所示。

表 1 STL 容器适配器及其基础容器
容器适配器	基础容器筛选条件	默认使用的基础容器
stack 	基础容器需包含以下成员函数：
empty()
size()
back()
push_back()
pop_back()
满足条件的基础容器有 vector、deque、list。	deque
queue	基础容器需包含以下成员函数：
empty()
size()
front()
back()
push_back()
pop_front()
满足条件的基础容器有 deque、list。	deque
priority_queue	基础容器需包含以下成员函数：
empty()
size()
front()
push_back()
pop_back()
满足条件的基础容器有vector、deque。	vector
不同场景下，由于不同的序列式容器其底层采用的数据结构不同，因此容器适配器的执行效率也不尽相同。但通常情况下，使用默认
的基础容器即可。当然，我们也可以手动修改，具体的修改容器适配器基础容器的方法，后续讲解具体的容器适配器会详细介绍。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于
分享创业故事+学习历程+工作记录+生活日常+编程资料。


stack 栈适配器是一种单端开口的容器（如图 1 所示），实际上该容器模拟的就是栈存储结构，即无论是向里存数据还是从中取数据，
都只能从这一个开口实现操作。

stack适配器示意图
图 1 stack 适配器示意图

如图 1 所示，stack 适配器的开头端通常称为栈顶。由于数据的存和取只能从栈顶处进行操作，因此对于存取数据，stack 适配器
有这样的特性，即每次只能访问适配器中位于最顶端的元素，也只有移除 stack 顶部的元素之后，才能访问位于栈中的元素。

栈中存储的元素满足“后进先出（简称LIFO）”的准则，stack 适配器也同样遵循这一准则。

stack容器适配器的创建
由于 stack 适配器以模板类 stack<T,Container=deque<T>>（其中 T 为存储元素的类型，Container 表示底层容器的类型）
的形式位于<stack>头文件中，并定义在 std 命名空间里。因此，在创建该容器之前，程序中应包含以下 2 行代码：

#include <stack>
using namespace std;
std 命名空间也可以在使用 stack 适配器时额外注明。

创建 stack 适配器，大致分为如下几种方式。

1) 创建一个不包含任何元素的 stack 适配器，并采用默认的 deque 基础容器：
std::stack<int> values;
上面这行代码，就成功创建了一个可存储 int 类型元素，底层采用 deque 基础容器的 stack 适配器。

2) 上面提到，stack<T,Container=deque<T>> 模板类提供了 2 个参数，通过指定第二个模板类型参数，我们可以使用出 deque 
容器外的其它序列式容器，只要该容器支持 empty()、size()、back()、push_back()、pop_back() 这 5 个成员函数即可。

在介绍适配器时提到，序列式容器中同时包含这 5 个成员函数的，有 vector、deque 和 list 这 3 个容器。因此，stack 
适配器的基础容器可以是它们 3 个中任何一个。例如，下面展示了如何定义一个使用 list 基础容器的 stack 适配器：
std::stack<std::string, std::list<int>> values;

3) 可以用一个基础容器来初始化 stack 适配器，只要该容器的类型和 stack 底层使用的基础容器类型相同即可。例如：
std::list<int> values {1, 2, 3};
std::stack<int,std::list<int>> my_stack (values);
注意，初始化后的 my_stack 适配器中，栈顶元素为 3，而不是 1。另外在第 2 行代码中，stack 第 2 个模板参数必须显式
指定为 list<int>（必须为 int 类型，和存储类型保持一致），否则 stack 底层将默认使用 deque 容器，也就无法用 lsit 
容器的内容来初始化 stack 适配器。

4) 还可以用一个 stack 适配器来初始化另一个 stack 适配器，只要它们存储的元素类型以及底层采用的基础容器类型相同即可。
例如：
std::list<int> values{ 1, 2, 3 };
std::stack<int, std::list<int>> my_stack1(values);
std::stack<int, std::list<int>> my_stack=my_stack1;
//std::stack<int, std::list<int>> my_stack(my_stack1);

可以看到，和使用基础容器不同，使用 stack 适配器给另一个 stack 进行初始化时，有 2 种方式，使用哪一种都可以。
注意，第 3、4 种初始化方法中，my_stack 适配器的数据是经过拷贝得来的，也就是说，操作 my_stack 适配器，并不会对 
values 容器以及 my_stack1 适配器有任何影响；反过来也是如此。

stack容器适配器支持的成员函数
和其他序列容器相比，stack 是一类存储机制简单、提供成员函数较少的容器。表 1 列出了 stack 容器支持的全部成员函数。
表 1 stack容器适配器支持的成员函数
成员函数	功能
empty()	当 stack 栈中没有元素时，该成员函数返回 true；反之，返回 false。
size()	返回 stack 栈中存储元素的个数。
top()	返回一个栈顶元素的引用，类型为 T&。如果栈为空，程序会报错。
push(const T& val)	先复制 val，再将 val 副本压入栈顶。这是通过调用底层容器的 push_back() 函数完成的。
push(T&& obj)	以移动元素的方式将其压入栈顶。这是通过调用底层容器的有右值引用参数的 push_back() 函数完成的。
pop()	弹出栈顶元素。
emplace(arg...)	arg... 可以是一个参数，也可以是多个参数，但它们都只用于构造一个对象，并在栈顶直接生成该对象，
作为新的栈顶元素。
swap(stack<T> & other_stack)	将两个 stack 适配器中的元素进行互换，需要注意的是，进行互换的 2 个 stack 
适配器中存储的元素类型以及底层采用的基础容器类型，都必须相同。

下面这个例子中演示了表 1 中部分成员函数的用法：
#include <iostream>
#include <stack>
#include <list>
using namespace std;
int main()
{
    //构建 stack 容器适配器
    list<int> values{ 1, 2, 3 };
    stack<int, list<int>> my_stack(values);
    //查看 my_stack 存储元素的个数
    cout << "size of my_stack: " << my_stack.size() << endl;
    //将 my_stack 中存储的元素依次弹栈，直到其为空
    while (!my_stack.empty())
    {  
        cout << my_stack.top() << endl;
        //将栈顶元素弹栈
        my_stack.pop();
    }
    return 0;
}
运行结果为：
size of my_stack: 3
3
2
1

表 1 中其它成员函数的用法也非常简单，这里不再给出具体示例，后续章节用法会做具体介绍。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，
专注于分享创业故事+学习历程+工作记录+生活日常+编程资料。


前面章节中，已经对 stack 容器适配器及其用法做了详细的讲解。本节将利用 stack 适配器实现一个简单的计算机程序，
此计算机支持基本的加（+）、 减（-）、乘（*）、除（/）、幂（^）运算。

这里，先给大家展示出完整的实现代码，读者可先自行思考该程序的实现流程。当然，后续也会详细的讲解：

#include <iostream>
#include <cmath>       // pow()
#include <stack>       // stack<T>
#include <algorithm>   // remove()
#include <stdexcept>   // runtime_error
#include <string>      // string
using std::string;
// 返回运算符的优先级，值越大，优先级越高
inline size_t precedence(const char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    throw std::runtime_error{ string {"表达中包含无效的运算符"} +op };
}
// 计算
double execute(std::stack<char>& ops, std::stack<double>& operands)
{
    double result{};
    double rhs{ operands.top() }; // 得到右操作数
    operands.pop();                                   
    double lhs{ operands.top() }; // 得到做操作数
    operands.pop();                                    
    switch (ops.top()) // 根据两个操作数之间的运算符，执行相应计算
    {
    case '+':
        result = lhs + rhs;
        break;
    case '-':
        result = lhs - rhs;
        break;
    case '*':
        result = lhs * rhs;
        break;
    case '/':
        result = lhs / rhs;
        break;
    case '^':
        result = std::pow(lhs, rhs);
        break;
    default:
        throw std::runtime_error{ string{"invalid operator: "} +ops.top() };
    }
    ops.pop(); //计算完成后，该运算符要弹栈
    operands.push(result);//将新计算出来的结果入栈
    return result;
}
int main()
{
    std::stack<double> operands; //存储表达式中的运算符
    std::stack<char> operators; //存储表达式中的数值
    string exp;  //接受用户输入的表达式文本
    try
    {
        while (true)
        {
            std::cout << "输入表达式(按Enter结束):" << std::endl;
            std::getline(std::cin, exp, '\n');
            if (exp.empty()) break;
            //移除用户输入表达式中包含的无用的空格
            exp.erase(std::remove(std::begin(exp), std::end(exp), ' '), std::end(exp));
            size_t index{};
            //每个表达式必须以数字开头,index表示该数字的位数
            operands.push(std::stod(exp, &index)); // 将表达式中第一个数字进栈
            std::cout << index << std::endl;
            while (true)
            {
                operators.push(exp[index++]); // 将运算符进栈
                size_t i{};
                operands.push(std::stod(exp.substr(index), &i));  //将运算符后的数字也进栈,并将数字的位数赋值给 i。
                index += i;  //更新 index
                if (index == exp.length())                  
                {
                    while (!operators.empty())  //如果 operators不为空，表示还没有计算完
                        execute(operators, operands);
                    break;
                }
                //如果表达式还未遍历完，但子表达式中的运算符优先级比其后面的运算符优先级大，就先计算当前的子表达式的值
                while (!operators.empty() && precedence(exp[index]) <= precedence(operators.top()))
                    execute(operators, operands);
            }
            std::cout << "result = " << operands.top() << std::endl;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "计算结束" << std::endl;
    return 0;
}
下面是一些示例输出：
输入表达式(按Enter结束):
5*2-3
result = 7
输入表达式(按Enter结束):
4+4*2
result = 12
输入表达式(按Enter结束):↙   <--键入Enter

计算结束

计算器程序的实现流程
了解一个程序的功能，通常是从 main() 函数开始。因此，下面从 main() 函数开始，给大家讲解程序的整个实现过程。

首先，我们创建 2 个 stack 适配器，operands 负责将表达式中的运算符逐个压栈，operators 负责将表达式的数值逐个压栈，
同时还需要一个 string 类型的 exp，用于接收用户输入的表达式。

正如上面代码中所有看到的，所有的实现代码都包含在一个由 try 代码块包裹着的 while 循环中，这样既可以实现用户可以多次
输入表达式的功能（当输入的表达式为一个空字符串时，循环结束），还可以捕获程序运行过程中抛出的任何异常（在 catch 代码
块中，调用异常对象的成员函数 what() 会将错误信息输出到标准错误流中）。

当用户输入完要计算的表达式之后，由于整个表达式是以字符串的形式接收的，考虑到字符串中可能掺杂空格，影响后续对字符串
的处理，因此又必须借助 remove() 函数来移除输入表达式中的多余空格（第 70 行代码处）。

得到统一格式的表达式之后，接下来才是实现计算功能的核心，其实现思路为：
1) 因为所有的运算符都需要两个操作数，所以有效的输入表达式格式为“操作数 运算符 操作数 运算符 操作数...”，即序列的
第一个和最后一个元素肯定都是操作数，每对操作数之间有一个运算符。由于有效表达式总是以操作数开头，所以第一个操作数在
分析表达式的嵌套循环之前被提取出来。

2) 在循环中，输入字符串的运算符会被压入 operators 栈。在确认没有到达字符串末尾后，再从 exp 提取第二个操作数。这时 
stod() 的第一个参数是从 index 开始的 exp 字符串，它是被压入 operators 栈的运算符后的所有字符。此时字符串中第一个
运算符的索引为 i，因为 i 是相对于 index 的，所以我们会将 index 加上 i 的值，使它指向操作数后的一个运算符（如果是 
exp 中的最后一个操作数，它会指向字符串末尾的下一个位置）。

3) 当 index 的值超过 exp 的最后一个字符时，会执行 operators 容器中剩下的运算符。如果没有到达字符串末尾，operators 
容器也不为空，我们会比较 operators 栈顶运算符和 exp 中下一个运算符的优先级。如果栈顶运算符的优先级高于下一个运算符，
就先执行栈顶的运算符。否则，就不执行栈顶运算符，在下一次循环开始时，将下一个运算符压入 operators 栈。通过这种方式，
就可以正确计算出带优先级的表达式的值。

以“5-2*3+1”为例，以上程序的计算过程如下：
1) 取  5 和 2 进 operands 栈容器，同时它们之间的 - 运算符进 operators 栈容器，判断后续是否还有表达式，显然还有“*3+1”，
这种情况下，取 operators 栈顶运算符 - 和后续的 * 运算符做优先级比较，由于 * 的优先级更高，此时继续将后续的 * 和 3 
分别进栈；此时，operands 中从栈顶依次存储的是 3、2、5，operators 容器中从栈顶依次存储的是 *、-。

2) 继续判断后续是否还有表达式，由于还有“+1”，则取 operators 栈顶运算符 * 和 + 运算符做优先级比较，显然前者的优先级
更高，此时将 operands 栈顶的 2 个元素（2 和 3）取出并弹栈，同时将 operators 栈顶元素（*）取出并弹栈，计算它们组成
的表达式 2*3，并将计算结果再入 operands 栈。计算到这里，operands 中从栈顶依次存储的是 6、5，operators 中从栈顶依次
存储的是 -。

3) 由于 operator 容器不空，因此继续取新的栈顶运算符“-”和“+”做优先级比较，由于它们的优先级是相同的，因为继续将 
operands 栈顶的 2 个元素（5 和 6）取出并弹栈，同时将 operators 栈顶元素（-） 取出并弹栈，计算它们组成的表达式“5-6”，
并将计算结果 -1 再入 operands 栈。此时，operands 中从栈顶依次存储的是 -1，operator 为空。

4）由于此时 operator 栈为空，因此将后续“+1”表达式中的 1 和 + 分别进栈。由于后续再无其他表达式，此时就可以直接取 
operands 位于栈顶的 2 个元素（-1 和 1），和 operator 的栈顶运算符（+），执行 -1+1 运算，并将计算结果再入 operands 
栈。

通过以上几步，最终“5-2*3+1”的计算结果 0 位于 operands 的栈顶。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于4
分享创业故事+学习历程+工作记录+生活日常+编程资料。

*/

using namespace std;
static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();

// solution


// main
int main() {
    // STL stack adaptor study
    // The std::stack class is a container adaptor that gives the programmer the functionality of a stack - specifically, a LIFO 
    // (last-in, first-out) data structure.
    // The class template acts as a wrapper to the underlying container - only a specific set of functions is provided. The stack 
    // pushes and pops the element from the back of the underlying container, known as the top of the stack.

    stack<int> myIntStack;
    stack<vector<string>> myStringVectorStack;

    myIntStack.push(5);
    myIntStack.push(4);
    myIntStack.push(3);
    myIntStack.push(2);
    myIntStack.push(1);

    // top(), get current top element from stack, this is the only way to access one element from stack
    // STL: Returns reference to the top element in the stack. This is the most recently pushed element. This element will be removed 
    // on a call to pop(). Effectively calls c.back().

    // Note 1: stack/queue/priority_queue adaptors have no iterator, so there is no way to use for(...) loop
    // Note 2: it will be tricky that if we use stack.size() as condition in the for loop, and pop item out,
    //         it will cause unexpected result. it's safer to use while loop with stack.empty() check instead
    //         to loop through all elements in the stack
    cout << "Size of stack: " << myIntStack.size() << endl;
    while (!myIntStack.empty()) {
        cout << myIntStack.top() << endl;
        myIntStack.pop();
    }

    // size(), return the current size of stack
    // STL: Returns the number of elements in the underlying container, that is, c.size().
    cout << "Size of stack: " << myIntStack.size() << endl;

    myIntStack.push(5);
    myIntStack.push(1);
    myIntStack.push(4);
    myIntStack.push(2);
    myIntStack.push(3);

    for (int i = 0; i < 5; i++) {
        vector<string> tmpV;
        string s = "string";
        // use std::to_string() to convert given input to string
        s = s + std::to_string(i);
        tmpV.push_back(s);
        myStringVectorStack.push(tmpV);
    }

    // empty(), check if the stack is empty
    // STL: Checks if the underlying container has no elements, i.e. whether c.empty().
    while (!myStringVectorStack.empty()) {
        vector<string> tmpV = myStringVectorStack.top();
        for (int i = 0; i < tmpV.size(); i++) {
            cout << "items in the vector from top stack is " << tmpV[i] << endl;
        }
        myStringVectorStack.pop();
    }

    // push()/pop()/emplace() are all most used above
    // STL: Pushes the given element value to the top of the stack.
    // 1) Effectively calls c.push_back(value)
    // 2) Effectively calls c.push_back(std::move(value))
    // STL: Removes the top element from the stack. Effectively calls c.pop_back()
    // STL: Pushes a new element on top of the stack. The element is constructed in-place, i.e. no copy or move operations are performed. 
    // The constructor of the element is called with exactly the same arguments as supplied to the function.
    // Effectively calls c.emplace_back(std::forward<Args>(args)...);
    myIntStack.emplace(5);
    myIntStack.emplace(1);
    myIntStack.emplace(4);
    myIntStack.emplace(2);
    myIntStack.emplace(3);
    cout << "Size of stack: " << myIntStack.size() << endl;
    while (!myIntStack.empty()) {
        cout << myIntStack.top() << endl;
        myIntStack.pop();
    }

    // swap()/std::swap(), swap content from one stack to another stack. This is similar to all other containers
    deque<double> myDoubleDeque = {1.1, 2.2, 3.3};

    // overload from deque to stack
    stack<double> myDoubleStack1(myDoubleDeque);
    stack<double> myDoubleStack2;

    myDoubleStack2.swap(myDoubleStack1);
    std::swap(myDoubleStack1, myDoubleStack2); 

    return 0;
}
