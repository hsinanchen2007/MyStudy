### 解题思路
利用queue和stack之间的特性关系
stack栈：
s.empty();         //如果栈为空则返回true, 否则返回false;
s.size();          //返回栈中元素的个数

s.top();           //返回栈顶元素, 但不删除该元素

s.pop();           //弹出栈顶元素, 但不返回其值
s.push();          //将元素压入栈顶

queue容器：
s.empty();         //如果容器为空则返回true, 否则返回false;
s.size();          //返回容器中元素的个数

s.front()           //返回 queue 中第一个元素的引用
s.back()：          //返回 queue 中最后一个元素的引用。

s.push(T&& obj)     //在尾部添加元素
s.pop()             //删除queue中的第一个元素。

所以两者间的pop（）是不相同的，其他基本相同，queue相当于末尾，stack相当于在头部，
所以我们在初始化push（）的时候利用queue，就将其倒置放入，这样pop（）就满足了stack的要求了。