
### 代码

```cpp
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s1;
        stack<char> s2;
        string str1 = fun(s1,S);
        string str2 = fun(s2,T);
        if(str1 == str2)
        return true;
        return false;
    }
    string fun(stack<char> &s1,string S)
    {   
        for(int i = 0;i < S.length();i++)
        {   
            if(S[i] != '#')
            {
                //入栈
                s1.push(S[i]);
            }
            else
            { 
                //出栈
                if(!s1.empty())
                s1.pop();
            }
        }
        //退格后的字符串
        string str1 = "";
        while(!s1.empty())
        {
            str1 += s1.top();
            s1.pop();
        }
        return str1;
    }
};
```