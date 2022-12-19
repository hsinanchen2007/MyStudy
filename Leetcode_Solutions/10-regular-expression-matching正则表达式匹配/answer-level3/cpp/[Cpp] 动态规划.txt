### 解题思路
dp[i][j]表示s的前i个字符是否能被p的前j个字符匹配

### 代码

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        int n1 = s.size(), n2 = p.size();
        if (n1 == 0 && n2 == 0) return true;
        if (n1 > 0 && n2 == 0) return false;
        // dp[i][j]表示s的前i个字符是否能被p的前j个字符匹配
        vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n2; i++) {
            if (i > 1 && p[i - 1] == '*' && dp[0][i - 2]) {
                dp[0][i] = true;
            }
        }

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (p[j - 1] == '*') {
                    // p的第j个字符为*时
                    // dp[i][j] 由*匹配0个前一个字符
                    dp[i][j] = dp[i][j] || (j > 2 && dp[i][j - 2]);
                    // dp[i][j] 由*匹配1个或多个前一个字符
                    // 只匹配1个时，直接由dp[i][j-1]决定
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
                    // 1个或多个时，判断s前i-1个和p的前j个是否匹配，匹配的情况下，在判断s的第i个和p的第j - 1个是否匹配
                    dp[i][j] = dp[i][j] || (dp[i - 1][j] && j > 1 && (p[j - 2] == '.' || s[i - 1] == p[j - 2]));
                } else {
                    // 不为*时，由dp[i - 1][j - 1]和s第i个字符是否与p的第j个字符匹配决定dp[i][j]
                    dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }

        return dp[n1][n2];
    }
};
```