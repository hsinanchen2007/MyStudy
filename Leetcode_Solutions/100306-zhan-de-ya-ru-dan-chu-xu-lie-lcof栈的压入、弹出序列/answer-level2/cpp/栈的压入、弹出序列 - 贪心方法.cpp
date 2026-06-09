### 解题思路
**模拟栈的压入弹出过程**：
1. 使用一个栈，开始为空
2. 持续压入`pushed`数组元素到栈中，直到栈顶元素和`popped`首元素相同，开始弹出，若弹出后还是匹配，继续弹出
3. 最后判断栈是否为空，空则`true`，否则`false`

### 代码

```cpp
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = popped.size();
        int m = pushed.size();
        if(n != m) return false;
        stack<int> sk;
        int j = 0;
        for(int i = 0; i < m; i++){
            sk.push(pushed[i]);
            while(!sk.empty() && j < n && popped[j] == sk.top()){
                sk.pop();
                j++;
            }
        }
        return sk.empty();
    }
};
```