```
public static int minDistance(String word1, String word2) {
        int m = word1.length(), n = word2.length();
        if(m == 0 || n == 0){
            return m + n;
        }
        int[][] dp = new int[m + 1][n + 1];

        //初始化dp
        for (int i = 1; i < n + 1; i++) {
            dp[0][i] = i;
        }
        for (int i = 1; i < m + 1; i++) {
            dp[i][0] = i;
        }
        //处理dp
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                //如果当前字符相等
                if( word1.charAt(i-1) == word2.charAt(j-1))
                    dp[i][j] = dp[i-1][j-1];
                //不等就取三种情况中最小的值
                else
                    dp[i][j] = Math.min(dp[i-1][j],Math.min(dp[i][j-1],dp[i-1][j-1]) ) + 1;
            }
        }

        return dp[m][n];
    }
```
