### 解题思路
使用栈的思想；O(n);遍历一次string
思路：发现是‘{’，‘{’，‘(’，则push入栈；
如果不是上述三个字符，则先判断栈内是否为空，如果为空，直接return false；
如果不为空，则判定当前字符和top的字符是否位一组，若为一组括号，pop栈，如果部位一组，reuturn false；

遍历完成后，如果栈为空，则true；
### 代码

```cpp
class Solution {
public:
    bool isValid(string s) {
        size_t len=s.size();
        if(len==0)return true;
        if(len&1)return false;
        stack <char> temp;
        std::map<char,char>sign{{'}','{'},{']','['},{')','('}};
        for(size_t i=0;i<len;++i)
        {
            if(s[i]=='{'||s[i]=='['||s[i]=='(')
            {
                temp.push(s[i]);
                continue;
            }
            if(temp.empty())return false;
            if(sign[s[i]]==temp.top())
                temp.pop();
            else
                return false;
        }
        return temp.empty();
    }
};
```