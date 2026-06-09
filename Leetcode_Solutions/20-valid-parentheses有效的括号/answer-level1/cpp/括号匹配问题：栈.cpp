### 解题思路
使用栈。注意不匹配的情况有三种：一种是多出了右括号（栈为空时，来了右括号），一种是左右不匹配，一种是多出了左括号（最后栈不为空）。

### 代码

```cpp
class Solution {
private:
    stack<char> stack;
    unordered_map<char, char> map1;

public:
    bool isValid(string s) {
        map1['['] = ']';
        map1['{'] = '}';
        map1['('] = ')';
        for(auto c : s){
            if(map1.count(c)) stack.push(c);
            if(c == ']' || c == '}' || c == ')'){
                if(stack.empty()) return false;  //多余右括号
                if(map1[stack.top()] == c){
                    stack.pop();
                    continue;
                }
                else return false;  //未成功匹配
            }
        }
        return stack.empty();
    }
};
```