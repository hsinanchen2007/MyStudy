动态规划 dp[i][j] 表示word1[0...i]到word2[0...j]的编辑距离
如果word1[i] == word2[j], 则dp[i][j] = max(dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1])
如果word1[i] != word2[j], 则dp[i][j] = max(dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + 1)

```
    public int minDistance(String word1, String word2) {
        int m = word1.length();
        int n = word2.length();
        int[][] dp = new int[m + 1][n + 1];
        // 初始化
        for (int i = 0; i < m + 1; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j < n + 1; j++) {
            dp[0][j] = j;
        }
        // 遍历求所有i到所有j的编辑距离
        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                    dp[i][j] = 1 + Math.min(dp[i - 1][j], Math.min(dp[i][j - 1], dp[i - 1][j - 1] - 1));
                } else {
                    dp[i][j] = 1 + Math.min(dp[i - 1][j], Math.min(dp[i][j - 1], dp[i - 1][j - 1]));
                }
            }
        }
        return dp[m][n];
    }
```