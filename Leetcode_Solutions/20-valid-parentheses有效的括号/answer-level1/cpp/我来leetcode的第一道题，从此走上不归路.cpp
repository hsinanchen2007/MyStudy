### 解题思路
此处撰写解题思路
用栈来做
### 代码

```cpp
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> *p_stack=new stack<char>();
        for(auto c:s)
        {
            if(c=='('||c=='{'||c=='[')
                p_stack->push(c);
            else
            {
                if(p_stack->empty())
                {
                    return false;
                }
                char topChar = p_stack->top();
                if(c==')'&&topChar!='(')
                {
                    return false;
                }
                if(c=='}'&&topChar!='{')
                {
                    return false;
                }
                if(c==']'&&topChar!='[')
                {
                    return false;
                }
                p_stack->pop();
            }
        }
        return p_stack->empty();
    }
};
```