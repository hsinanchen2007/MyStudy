### 解题思路
1. 遇到左括号，就进栈
2. 遇到右括号，看栈顶是否为左括号，若是则弹出栈顶元素且右括号不仅栈；否则右括号进栈
3. 结果返回栈的长度

### 代码

```cpp
class Solution {
public:
    stack<char> sk;
    int minAddToMakeValid(string S) {
        for(char c: S){
            if(c == '(') sk.push(c);
            else{
                if(!sk.empty() && sk.top() == '(') sk.pop();
                else sk.push(c);
            }
        }
        return sk.size();
    }
};
```