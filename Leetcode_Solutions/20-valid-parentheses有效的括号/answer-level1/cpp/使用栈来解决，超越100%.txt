### 解题思路
使用栈来解决

### 代码

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char>  symbols;
        int n=s.size();
        if(n==0) return true;
        else if(n==1) return false;
        for(int i=0;i<s.size();i++)
        {
            if(!symbols.empty())
            {
                 if(s[i]==')'&&symbols.top()=='(')
            symbols.pop();
            else   if(s[i]=='}'&&symbols.top()=='{')
            symbols.pop();
             else   if(s[i]==']'&&symbols.top()=='[')
            symbols.pop();
            else
            symbols.push(s[i]);
            }
            else
           symbols.push(s[i]);
        }
        if( symbols.empty())
        return true;
        else return false;
    }
};
```