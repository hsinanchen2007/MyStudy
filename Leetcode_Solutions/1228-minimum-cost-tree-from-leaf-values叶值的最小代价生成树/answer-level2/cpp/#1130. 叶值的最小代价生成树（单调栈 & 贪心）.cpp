### 解题思路
结论：用贪心算法，维护一个单调递减栈，每次用相邻的两个较小的叶节点合成中间节点，最终可以得到最小代价生成树。

***Talk is cheap. Show me the code.***
```cpp
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int result = 0;
        stack<int> stk;
        stk.push(INT_MAX);
        for (int e : arr) {
            while (e >= stk.top()) {
                int oldTop = stk.top();
                stk.pop();
                result += (oldTop * min(e, stk.top()));
            }
            stk.push(e);
        }
        while (stk.size() > 2) {
            int oldTop = stk.top();
            stk.pop();
            result += (oldTop * stk.top());
        }
        return result;
    }
};
```
