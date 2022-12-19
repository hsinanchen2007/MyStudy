这题用动态规划的话与[**Leetcode第十题**](https://leetcode-cn.com/problems/regular-expression-matching/)很类似，相对来说第十题甚至难很多，可以先去细看第十题的题解，理解之后这道题就很简单了，有兴趣的话请看[**我的第十题题解**](https://leetcode-cn.com/problems/regular-expression-matching/solution/kan-liao-jiu-ming-bai-de-dong-tai-gui-hua-by-stree/)，有什么不足的还望指出。
```c++
class Solution {
public:
    bool isMatch(string s, string p) {
        if (s == "" && (p == "" || p == "*")) {
            return true;
        }
        // m is row, n is column
        unsigned long m = s.length(), n = p.length();
        int dp[m + 1][n + 1];
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        //initiate first row
        for (int i = 1; i <= n; i++) {
            if (p[i - 1] == '*') {
                dp[0][i] = dp[0][i - 1];
            } else dp[0][i] = false;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    //dp[i][j - 1] means matching "empty string"
                    //dp[i - 1][j - 1] means matching "single char"(which can be equivalent to '?')
                    //dp[i - 1][j] means matching "multiple chars"
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j - 1] || dp[i - 1][j];
                }
            }
        }
        return dp[m][n];
    }
};
```