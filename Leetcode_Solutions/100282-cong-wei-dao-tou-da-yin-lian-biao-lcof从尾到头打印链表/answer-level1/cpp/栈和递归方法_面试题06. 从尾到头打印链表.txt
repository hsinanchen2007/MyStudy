看到题首先想到的思路就是使用栈先进后出的特性去逆序链表中的数据。

编写程序时出现一个错误，判断栈是否为空时我是这样写的`stk.top != 0` ，这样会一直报“**引用绑定到未对齐的地址**“的错误：
`runtime error: reference binding to misaligned address 0xbebebebebebec0ba for type 'int',which requires 4 byte alignment (stl_deque.h)`。

查阅资料找到的方法并不能解决问题，但是提醒自己在赋值拷贝上的问题：
[**C++深拷贝和浅拷贝**](https://www.cnblogs.com/ohazyi/p/7520938.html) 
此文写的蛮好的，学到很多～

说回引用绑定到未对齐的地址错误，实际上是因为**STL的stack容器的函数top()返回的是引用类型**，具体的内容可看C++官方指导手册[**STL:STACK_top()**](https://zh.cppreference.com/w/cpp/container/stack/top)。在leetcode报错中也能发现是“reference”的问题，而从“stl_deque.h“能知道STL的stack内部顺序容器实现是STL的**deque**。于是这里就清楚了，我们无法将引用和int类型进行比较，也无法将引用赋值给int类型的变量。这里面涉及到引用的知识，关于引用官方给出了部分说明是[**reference引用**](https://zh.cppreference.com/w/cpp/language/reference_initialization)，因为引用和指针很重要，后面我会抽空对它进行总结。

所以判断STL的stack栈为空的直接使用提供的**empty()**函数即可（我也不知道我为啥一开始没用:P）

后面看其他人的题解，发现可以使用递归方法解决该问题，递归方法的思路是先不断递归访问链表到最后一个结点，然后从链表的尾部结点开始出递归栈，出栈前将链表结点的值存储到数组中。这里使用递归本质还是使用了栈，无非一个是对数据入栈和出栈，一个是对函数入栈和出栈。两种方法的运行时间也相差不大。

    /*
     * 方法1 栈
     * 创建一个栈，将链表中的数据push到栈中，
     * 再将栈中数据pop到数组中，
     * 即完成了链表数据的反转
     * */
```
std::vector<int> reversePrint(ListNode *head) {
    if (head == nullptr) {
        return {};
    }

    std::stack<int> stk;
    while (head) {
        stk.push(head->val);
        head = head->next;
    }

    std::vector<int> vec;
    // WARNing : stk.top != 0 is wrong!!!
    while (!stk.empty()) {
        vec.push_back(stk.top());
        stk.pop();
    }

    return vec;
}
```

    /*
     * 方法2 递归
     * 使用递归访问链表的最后一个结点，
     * 再依次递归出栈，访问每个结点的值，
     * 存储到数组中完成反转
     * */
```
std::vector<int> reversePrint2(ListNode *head) {
    std::vector<int> vec;
    reverse(head, vec);

    return vec;
}
```

    /*
     * 递归反转函数
     *  WARNing : std::vector<int>& vec
     * 设置为引用&表示传入的数组(实参)与函数内使用的数组(形参)指向相同的内存空间
     * 因此函数内数组的值改变，函数外的数组值也会改变
     */
```
void reverse(ListNode *head, std::vector<int>& vec) {
    if(!head) {
        return;
    }
    reverse(head->next, vec);
    vec.push_back(head->val);
}
```
