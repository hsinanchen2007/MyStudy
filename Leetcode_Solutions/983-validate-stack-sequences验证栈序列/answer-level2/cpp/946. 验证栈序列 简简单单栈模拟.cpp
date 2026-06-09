### 解题思路
此处撰写解题思路
![946.jpg](https://pic.leetcode-cn.com/272d1208c6dc24fa7caa267bc8895043f4ca7e626e599da4c64b46d937cd818a-946.jpg)

### 代码

```cpp
#include <stack>
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> myStack;
        vector<int>::iterator itePop = popped.begin();
        for(auto p:pushed)
        {
            myStack.push(p);
            while(!myStack.empty() && myStack.top() == *itePop)
            {
                myStack.pop();
                itePop++;
            }
        }
        return myStack.empty();
    }
};




```