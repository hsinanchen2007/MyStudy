### 解题思路
括号匹配的水题，用栈解决..

### 代码

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char>p;
        for(int i=0;s[i];i++)
        {
            if(!p.empty()&&p.top()=='('&&s[i]==')')p.pop();
            else if(!p.empty()&&p.top()=='['&&s[i]==']')p.pop();
            else if(!p.empty()&&p.top()=='{'&&s[i]=='}')p.pop();
            else p.push(s[i]);
        }
        return p.empty();
    }
};
```