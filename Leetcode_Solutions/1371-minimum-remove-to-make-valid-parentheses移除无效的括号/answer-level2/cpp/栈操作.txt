### 解题思路
此处撰写解题思路..
其实这里也就是对栈的具体运用.
在看到题目的第一眼时我怎么也不会想到用栈来解决.
这只是系统的分类提示才有了点眉目.
这里建议好好看看做做关于栈的基础题.
完事之后会发现这个很简单.
但是思维要清晰,千万要注意一些罕见的情况,,不能让代码运行时出错或者超出预判.
简而言之就是要逻辑清晰且全面.
这在算法当中是非常重要的.
以下是具体的代码.
### 代码

```cpp
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        int len=s.length();
        string ss="";
        for(int i=0;i<len;i++)
        {////栈操作
            if(s[i]=='('||s[i]==')')
            {
                if(!st.empty())
                {
                    if(s[i]=='(') st.push(i);
                    else st.pop();
                }
                else
                {
                    if(s[i]=='(') st.push(i);
                    else s[i]='0';
                }
            }
        }
        while(!st.empty())
        {////针对(符号太多的代码.
            s[st.top()]='0';
            st.pop();
        }
        for(int i=0;i<len;i++) if(s[i]!='0') ss+=s[i];
        return ss;
    }
};
```
ok