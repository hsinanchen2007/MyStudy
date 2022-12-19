### 解题思路
序列型动态规划

### 代码

```java
class Solution {
    public int longestPalindromeSubseq(String ss) {
        if (ss == null || ss.length() == 0) {
            return 0;
        }

        char[] s = ss.toCharArray();
        int n = s.length;
        int[][] dp = new int[n][n];

        //init
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = 2;
            } else {
                dp[i][i + 1] = 1;
            }
        }

        //注意这里的遍历方式
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                dp[i][j] = Math.max(dp[i + 1][j], dp[i][j - 1]);
                if(s[i] == s[j]){
                    dp[i][j] = Math.max(dp[i][j], dp[i + 1][j - 1] + 2);
                }
            }
        }

        return dp[0][n - 1];
    }
}
```