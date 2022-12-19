> 执行用时 : 0 ms, 在Valid Parentheses的C++提交中击败了100.00% 的用户

> 内存消耗 : 8.6 MB, 在Valid Parentheses的C++提交中击败了70.24% 的用户

 初版的提交记录执行用时在8ms，后来根据 陈乐乐 的题解的启发，添加了 __line 6__ ，也就是判断长度是否为奇数，然后执行用时就降到了 __0 ms__ (!!??)

具体的思路就跟主流的思路一样，使用栈。

一. 判断前括号还是后括号
  1. 前括号，压入。
  2. 后括号，判断是否可以pop和是否有匹配的前括号

二. 此时循环结束，判断栈里是否还有残留


当然，中间的if对比还有可以优化的地方（可以有效减少对比的次数）

```cpp
class Solution {
public:
    bool isValid(string s) {
    if(s=="") return true;
    if(s.length()%2!=0) return false;
    stack<char> ss;
    for(auto i:s) {
        if (i=='{' || i=='('|| i=='[') ss.push(i);
        else {
            if (ss.size() == 0 && (i == ']' || i == '}' || i == ')')) return false;
            else if ((i == '}' && ss.top() != '{') || (i == ']' && ss.top() != '[') || (i == ')' && ss.top() != '(') )
                return false;
            else
                ss.pop();
        }
    }
    if (ss.size() != 0 ) return false; 
    return true;
}
};
```