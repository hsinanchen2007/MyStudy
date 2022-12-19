### 解题思路
双栈，一个保存'('另一个保存'*'
### 代码

```cpp
class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st, star;
        int count = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {st.push(i);}
            else if(s[i] == ')')    {
                if(!st.empty())   {
                    st.pop();
                }
                else{
                    if(!star.empty())   {star.pop();}
                    else return false;
                }
            }
            else if(s[i] == '*')    {star.push(i);}
        }
        while(!st.empty() && !star.empty()) {
            int left = st.top();
            int right = star.top();
            if(left < right)    {
                st.pop();
            }
            star.pop();
        }
        if(st.empty())    return true;
        return false;
    }   
};
```