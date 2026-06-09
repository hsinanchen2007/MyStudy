### 解题思路
思路：辅助栈。自己用一个例子走一遍方便理解。
定义`j`，指向`popped`中第`j`个元素；
把`pushed `数据压入辅助栈，每次压入一个都要比较当前栈顶元素是否与`poped`序列中的元素相同` popped[j] == helper.top()`，相同则弹出栈顶元素，`j++`，然后继续比较，直到不同或者辅助栈为空。继续压栈。
最后如果如果辅助栈为空，则说明OK。
注意，输入为`[] []`、`[] [1,2,3]`、`[1,2,3] []`等特殊情况。

### C++代码

```cpp
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size() != popped.size())
            return false;
        stack<int> helper;
        int j = 0;
        for(int i = 0;i<pushed.size();++i)
        {
            helper.push(pushed[i]);
            while((!helper.empty()) && popped[j] == helper.top() && j<popped.size() )
            {
                helper.pop();
                ++j;
            }
        }
        return helper.empty();
    }
};
```