### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n = popped.size();
        int j = 0;
        for (int i = 0; i < pushed.size(); ++i){
            st.push(pushed[i]);
            while(!st.empty() && j < n && st.top() == popped[j]){
                st.pop();
                ++j;
            }
        }
        return st.empty();

    }
};
```