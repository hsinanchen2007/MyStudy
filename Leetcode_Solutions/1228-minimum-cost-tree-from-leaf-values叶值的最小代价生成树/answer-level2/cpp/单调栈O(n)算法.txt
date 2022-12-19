### 解题思路
每个元素都选择左右第一个比它大的元素中较小的那个去合并。

### 代码

```cpp
const int INF = 100;

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        stack<int> st;
        int ans = 0;
        for (int i : arr) {
            while (!st.empty() && st.top() < i) {
                int top = st.top();
                st.pop();
                ans += top * min(st.empty() ? INF : st.top(), i);
            }
            st.push(i);
        }
        while (st.size() >= 2) {
            int top = st.top();
            st.pop();
            ans += top * st.top();
        }
        return ans;
    }
};
```