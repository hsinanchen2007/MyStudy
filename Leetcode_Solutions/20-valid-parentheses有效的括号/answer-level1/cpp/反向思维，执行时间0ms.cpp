### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    //第一种为大家平时都会选用的方法
    /*bool isValid(string s)
    {
        stack<char> _stack;
        if(s.size()%2!=0) return false;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i]=='(' || s[i]=='{' ||s[i]=='[')
                _stack.push(s[i]);
            else if(s[i]==')' || s[i]=='}' ||s[i]==']')
            {
                if(s[i]==')')
                {
                    if(_stack.empty() || _stack.top()!='(')
                        return false;
                }
                else if(s[i]==']')
                {
                    if(_stack.empty() || _stack.top()!='[')
                        return false;
                }
                else
                {
                    if(_stack.empty() || _stack.top()!='{')
                        return false;
                }
                _stack.pop();
            }else{
                return false;
            }

        }
        return _stack.empty();
    }*/
    //思维转换
    //1.向栈中压入反向值
    //2.弹出是只有比较相等，不用去区分
    bool isValid(string s)
    {
        stack<char> _stack;
        for(auto &ch : s)
        {
            if(ch=='(')
                _stack.push(')');
            else if(ch=='{')
                _stack.push('}');
            else if(ch=='[')
                _stack.push(']');
            else if(_stack.empty() || _stack.top() != ch)
                return false;
            else
                _stack.pop();
            
        }
        return _stack.empty();
    }
};
```