### 解题思路
1，单调栈记录遍历过的左侧下边界
2，随着从左到后遍历字符逐渐更新单调栈

### 代码
```cpp
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for (auto c : num) {
            while (!st.empty() && st.top() > c && k > 0) {
                st.pop();
                --k;
            }
            if (st.empty() && c == '0') continue;
            st.push(c);
        }
        while (!st.empty() && k > 0) {
            st.pop();
            --k;
        }
        string res;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res.empty() ? "0" : res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/704f987d1e198dbe0bcef7ac5db3a1e74e3c99fec5c554010788a6c162904414-image.png)


