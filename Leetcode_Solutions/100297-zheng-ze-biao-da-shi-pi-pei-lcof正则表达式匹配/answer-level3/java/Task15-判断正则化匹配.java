### 解题思路
利用动态规划

### 代码

```java
class Solution {
    public boolean isMatch(String s, String p) {
        // 创建DP状态, 因为有可能是空串，所以需要多创建一位，因为dp会用来表示前m个和前n个。
        int m = s.length();
        int n = p.length();
        boolean[][] dp = new boolean[m + 1][n + 1];
        dp[0][0] = true;

        // 初始化DP状态：
        // 判断什么情况下s为空串的时候，p能够匹配：
        // 感谢@王小二的答案，初始化的时候必须为.*.*.*.*.*.*.*.*的格式，只要偶数位不是*，都无法匹配
        // 所以只有这些状态为True
        for (int j = 2; j <= n; j += 2) {
            if (p.charAt(j-1) == '*') {
                dp[0][j] = dp[0][j-2];
            }
        }

        // 开始进行确定状态转移方程：
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                // 获取当前字符
                char s_i = s.charAt(i-1);
                char p_j = p.charAt(j-1);

                // 状态1: s_i == p_j: dp[i][j] = dp[i-1][j-1]
                // 状态2: p_j == '.': dp[i][j] = dp[i-1][j-1]
                // 状态3: p_j == '*':
                    // 状态3.1: dp[i][j-2] == true: dp[i][j] = dp[i][j-2]
                    // 状态3.2: 如果p的前一位和现在相等或者p的前一位为'.',也可以与前一位匹配
                if (s_i == p_j || p_j == '.') {
                    dp[i][j] = dp[i-1][j-1];
                } else if (p_j == '*') {
                    if (dp[i][j-2]) {
                        dp[i][j] = dp[i][j-2];
                    } else if (s_i == p.charAt(j-2) || p.charAt(j-2) == '.') {
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
        }

        return dp[m][n];

    }
}
```