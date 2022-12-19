### 解题思路
将所有左括号入栈，然后遇到右括号判断栈顶是不是对应的左括号，如果不是则返回false，如果是就将栈顶弹出。
注意判断结束的时候如果栈不为空则返回false，还有遇到右括号的时候栈里有没有元素。
代码上还可以简化一下判断，不过这么写虽然复杂但清晰。

### 代码

```cpp
class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 0)   return true;
        if(s.size()%2 == 1) return false;

        stack<char> tempStack;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == ')') 
            {
                if(tempStack.empty() == false && tempStack.top() == '(')
                {
                    tempStack.pop();
                }
                else
                {
                    return false;
                }
            }
            else if (s[i] == ']')
            {
                if(tempStack.empty() == false && tempStack.top() == '[')
                {
                    tempStack.pop();
                }
                else
                {
                    return false;
                }
            }
            else if (s[i] == '}')
            {
                if(tempStack.empty() == false && tempStack.top() == '{')
                {
                    tempStack.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                tempStack.push(s[i]);
            }
        }
        return tempStack.empty();
    }
};
```