### 解题思路
区间动态规划：
1. dp[i][j]表示s[i...j]是否为回文
2. span表示区间长度，先把所有较小的区间算出来，才能推算较大的区间。

![图片.png](https://pic.leetcode-cn.com/93d1338332a6fa4ff7dbd2b707e107cbd8c1102c652129db383c17429bce8b98-%E5%9B%BE%E7%89%87.png)

### 代码

```cpp
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));  // dp[i][j]表示s[i...j]是否为回文
        for (int span = 1; span <= n; ++span) {  // span表示区间长度，先把所有较小的区间算出来，才能推算较大的区间。
            for (int i = 0; i <= n - span; ++i) {
                int j = i + span - 1;
                if (s[i] == s[j] && (span <= 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    ++ans;
                }
            }
        }
        return ans;
    }
};
```