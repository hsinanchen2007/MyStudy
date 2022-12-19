### 解题思路
- 注意只有右括号的情况，stack.top()
- 遇到左括号压入栈中，遇到右括号判断与栈顶元素是否配对
- 最后判断一下栈是否为空即可

### 代码

```cpp
class Solution
{
public:
    bool isValid(string s)
    {
        if (s == "")
            return true;
        if (s.size() % 2)
            return false;
        stack<char> temp;
        for (int i = 0; i < s.size(); i++)
        {
            if (!temp.empty()) //需要注意只有右括号的情况
            {
                if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                    temp.push(s[i]);
                else
                {
                    //()差1，{}[]差2
                    if (s[i] == temp.top() + 1 || s[i] == temp.top() + 2)
                        temp.pop();
                    else 
                        return false;
                }
            }
            else 
                temp.push(s[i]);
        }
        return temp.size()==0;
    }
};
```