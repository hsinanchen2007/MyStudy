### 解题思路
定义一个int类型的变量flag
分三种情况讨论：
1.S[i-1]和S[i]相同且为'('时，flag++。
2.S[i-1]和S[i]相同且为')'时，flag--。
3.S[i-1]和S[i]不同时，flag不变。
最后判断flag是否不为0，不为0的时候，s+=S[i]；

### 代码

```cpp
class Solution {
public:
    string removeOuterParentheses(string S) {
        string s;
        int flag=0;
        for(int i=1;i<S.size();i++)
        {
            
            if(S[i]==S[i-1])
            {
                if(S[i]=='(')
                flag++;
                else
                flag--;
            }
            if(flag)
            s+=S[i];
            
        }
        return s;
    }
};
```