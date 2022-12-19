### 解题思路
之前用C语言来写链栈比较麻烦，要自己构建结构体以及相关函数，而且存在一些写法和我在vs上不兼容；没想到C++竟然有链栈的包，原谅我无知...
既然可以直接用C++中的栈包，这题就相当好写了，首先得了解链栈的基本知识，其次就是如何使用栈包。
stack的定义：stack<typename> name;
压栈：name.push(i);
出栈：name.pop();因为出栈是弹出栈顶元素，所以无需传入参数
获取栈顶元素：name.top();
判断栈是否为空：name.empty();如果为空返回true，否则返回false
最后就是解题的核心思想：ASCII码对应的字符，如果扩后闭合，即对应的ASCII码相邻1或2；否则不闭合。

### 代码

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> linkstack;
        int length=s.size();
        if(length==0)
            return true;
        if(length%2)
            return false;
        linkstack.push(s[0]);
        for(int i=1;i<length;i++){
            if(linkstack.empty())
                linkstack.push(s[i]);
            else if(s[i]-linkstack.top()==1||s[i]-linkstack.top()==2)
                linkstack.pop();
            else
                linkstack.push(s[i]);
        }
        return linkstack.empty(); 
    }
};
```