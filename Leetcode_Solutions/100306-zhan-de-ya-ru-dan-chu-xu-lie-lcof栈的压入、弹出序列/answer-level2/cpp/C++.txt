### 解题思路
官方题解，精辟

### 代码

```cpp
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int j=0;
        stack<int> st;
        for(auto n : pushed) {
            st.push(n);
            while (!st.empty() && j < popped.size() && st.top() == popped[j]) {
                st.pop();
                j++;
            }
        }
        return j == popped.size();
    }
};
```