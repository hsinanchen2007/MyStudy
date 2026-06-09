## 思路
将入栈序列的每个元素入栈，如果栈顶元素等于出栈序列当前poped[i]元素，则弹出栈元素并移动出栈序列（++i），最后如果栈为空，则有效。

### 代码
时间复杂度：O(n)
空间复杂度：O(n)
```cpp
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {                
        stack<int> st;
        int i = 0;
        for (int n : pushed) {
            st.push(n);           
            while (!st.empty() && st.top() == popped[i]) {
                st.pop();
                ++i;
            }            
        }
        return st.empty();
    }
};
```