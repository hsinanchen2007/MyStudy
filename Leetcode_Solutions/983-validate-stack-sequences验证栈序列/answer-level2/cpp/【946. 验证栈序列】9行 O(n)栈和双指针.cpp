## 思路
从pushed[i]将元素压入栈，如果栈顶元素等于pop[j]则弹出。
最后如果栈为空，那么序列就是有效的。

### 代码
时间复杂度：O(n)
空间复杂度：O(n)
```c++
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        for (int i = 0, j = 0; i < pushed.size(); ++i) {
            s.push(pushed[i]);
            while (!s.empty() && s.top() == popped[j]) {
                s.pop();
                ++j;
            }
        }
        return s.empty();
    }
};
```
