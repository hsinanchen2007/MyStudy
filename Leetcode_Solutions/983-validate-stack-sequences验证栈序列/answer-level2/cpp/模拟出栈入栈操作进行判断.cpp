### 解题思路
利用题中给出的数组模拟出栈入栈操作，如果最后栈为空，表示给出的栈序列正确。
### 代码

```cpp
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stacks;
        int len = pushed.size(), i = 0, j = 0;
        while(j < len)
        {
            if(stacks.empty() || stacks.top() != popped[j] )  //如果栈为空或栈顶元素不等于此时popped数组的首元素，则需将pushed数组首元素进栈
            {
                if(i < len)
                stacks.push(pushed[i ++]);  //如果pushed数组i位置元素存在，进栈，否则出栈
                else
                break;
            }
            else if(stacks.top() == popped[j])  //如果栈顶元素等于此时popped数组首元素，表示可以出栈。
            {
                stacks.pop();
                j ++;
            }
        }
        return stacks.empty();
    }
};
```