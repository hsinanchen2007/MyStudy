### 解题思路
C++

### 代码

```cpp
class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2 != 0)return false;
        if(s[0]==')'||s[0]==']'||s[0]=='}') return false;
        map<char,char> m;
        m['(']=')';
        m['[']=']';
        m['{']='}'; 
        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{') st.push(s[i]);//左括号进栈
            if((s[i]==')'||s[i]==']'||s[i]=='}')&&(st.empty()==false))//右括号出栈，且栈不为空
            {
                if(m[st.top()]==s[i]) st.pop();
            }
        }
        if(st.empty()) return true;
        else return false;
    }
};
```