简单记录一下
应该都看得懂
```
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int i = 0;
        char tempc;
        bool flag;
        while (i < s.size())
        {
            if (s[i] == '{' || s[i] == '(' || s[i] == '[')  //左括号，直接压入
                st.push(s[i]);
            else {
                if (!st.empty())
                {
                    tempc = st.top();
                    if (!match(s[i], tempc)) //方便判断，简单写了个函数
                        return false;
                    else
                        st.pop();
                }
                else
                    return false;
            }
            i++;
        }
        if (st.empty())
            return true;
        else
            return false;
    }

    bool match(char c, char m)  //是右括号时，是否和对应的栈顶括号匹配
    {
        if (c == ')')
            return (m == '(');
        else if (c == ']')
            return (m == '[');
        else if (c == '}')
            return (m == '{');
        else
            return false; 
    }
};
```
