### 解题思路
**基本上就是一个字符串匹配的问题，看过数据结构都知道用栈来解决就行哈**
  我做的时候遇到的问题，**如何判断输入一个“]”的问题**，如果输入第一个字符就是右括号，那么访问空栈m就会发生报错，具体报错是栈越界应该。
   为了解决这个问题，我在判断里先判断栈是否为空，这样栈为空且输入右括号的时候将直接返回false。
*else if(s[i]==')'&&!m.empty()&&m.top()=='(')*
   最后判断栈是否为空，为空就返回true，如果还有没有匹配的左括号，就返回错误，

### 代码

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> m;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{')
                m.push(s[i]);
            else if(s[i]==')'&&!m.empty()&&m.top()=='(')
                m.pop();
            else if(s[i]==']'&&!m.empty()&&m.top()=='[')
                m.pop();
            else if(s[i]=='}'&&!m.empty()&&m.top()=='{')
                m.pop();
            else 
            return false;
        }
        if(m.empty()) return true;//m为空则true
        else return false;
    }
};
```