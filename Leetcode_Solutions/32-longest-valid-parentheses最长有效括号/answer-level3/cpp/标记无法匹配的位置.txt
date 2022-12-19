### 解题思路
- 用栈模拟一遍，将所有阻隔的括号的位置全部置1
- 例如: "()(()"的mark为[0, 0, 1, 0, 0]
- 再例如: ")()((())"的mark为[1, 0, 0, 1, 0, 0, 0, 0]
- 经过这样的处理后, 此题就变成了**寻找最长的连续的0的长度**

### 代码

```cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        vector<bool> mark(s.length());
        for(int i = 0; i < mark.size(); i++) mark[i] = 0;
        int left = 0, len = 0, ans = 0;
        // 用栈模拟一遍
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') st.push(i);
            else {
                // 多余的右括号是不需要的，标记
                if(st.empty()) mark[i] = 1;
                else st.pop();
            }
        }
        // 未匹配的左括号是不需要的，标记
        while(!st.empty()) {
            mark[st.top()] = 1;
            st.pop();
        }
        // 寻找标记与标记之间的最大长度，即是答案
        for(int i = 0; i < s.length(); i++) {
            if(mark[i]) {
                len = 0;
                continue;
            }
            len++;
            ans = max(ans, len);
        }
        return ans;
    }
};
```