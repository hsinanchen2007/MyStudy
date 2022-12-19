### 解题思路
c++栈包的基本使用，左括号压栈，然后弹出和右括号匹配，如果不匹配返回false，如果最后栈空，返回true

### 代码

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                stk.push(s[i]);
            }
            else{
                if(stk.empty())return false;
                char tmp=stk.top();
                if(s[i]==')' && tmp=='('
                    ||s[i]==']' && tmp=='['
                    || s[i]=='}' && tmp=='{')
                    {
                    stk.pop();
                    continue;
                }
                else return false;
            }
        }
        return stk.empty();
    }
};
```
