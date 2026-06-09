### 解题思路
此处撰写解题思路
遇见'('进栈，进栈前栈不空时内容为原语，见')'出栈，出栈后栈空时内容为原语。

### 代码

```cpp
class Solution {
public:
    string removeOuterParentheses(string S) {
        if(S.empty())
        {
            return S;
        }
        string strTarget;
        std::stack<char> chStack;
        for(auto strIter = S.cbegin();strIter != S.cend();++strIter)
        {
            if(*strIter == '(')
            {
                if(!chStack.empty()) //进栈前栈不空时内容为原语
                {
                    strTarget += '(';
                }
                chStack.push(*strIter);
            }
            else
            {
                chStack.pop();
                if(chStack.empty()) //出栈后栈空时内容为原语。
                {
                    strTarget += ')'; 
                }
            }
        }
        return strTarget;
    }
};
```