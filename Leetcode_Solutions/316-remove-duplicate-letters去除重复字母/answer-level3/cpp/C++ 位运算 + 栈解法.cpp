### 解题思路
1，利用26个bit来记录从后往前数该字符是否被包含进去
2，利用栈来贪心法逐渐更新记录，更新的条件是栈尾部的字符在后面出现过且比当前字符大

### 代码

```cpp
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int N = s.size();
        vector<int> status(N + 1, 0);
        for (int i = N - 1; i >= 0; --i) {
            status[i] = status[i + 1] | (1 << (s[i] - 'a'));
        }
        int M = 0;
        stack<int> st;
        s += 'z';
        for (int i = 0; i < N; ++i) {
            int k = s[i] - 'a';
            if (M >> k & 1) continue;
            while (!st.empty() && st.top() >= k && (status[i + 1] >> st.top() & 1)) {
                M ^= 1 << st.top();
                st.pop();
            }
            st.push(k);
            M |= 1 << k;
            if (M == status[0]) break;
        }
        string res;
        while (!st.empty()) {
            res += st.top() + 'a';
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/a48a654d9bfcb60f4d6fb3cf4edc1d2dbbb6806004e5096a41cc44b43fa02b97-image.png)
