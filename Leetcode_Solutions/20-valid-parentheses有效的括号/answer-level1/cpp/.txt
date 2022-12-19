### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for(char c:s)
        {
            if(c=='('||c=='{'||c=='[')
                stack.push(c);
            else
            {
                if(stack.empty())
                    return false;
                char cStack = stack.top();
                stack.pop();
                bool b1 = c == ')'&&cStack!='(';
                bool b2 = c == ']'&&cStack!='[';
                bool b3 = c == '}'&&cStack!='{';
                if(b1||b2||b3)
                    return false;
            }
        }
        return stack.empty();
        
    }
};
```