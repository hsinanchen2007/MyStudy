1.动态规划
```
    public int uniquePaths(int m, int n) {
        if (m < 1 || n < 1) {
            return 0;
        }
        int[][] dp = new int[m][n];
        //初始化
        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }
        for (int i = 0; i < n; i++) {
            dp[0][i] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        for (int i = 0; i < m; i++) {
            System.out.println(Arrays.toString(dp[i]));
        }
        return dp[m - 1][n - 1];
    }
```

2.规律法
因为这种题有规律，而且其实可以直接转换成排列组合法，直接输出结果。

例如矩阵
```
[1, 1, 1, 1, 1]
[1, 2, 3, 4, 5]
[1, 3, 6, 10, 15]
[1, 4, 10, 20, 35]
[1, 5, 15, 35, 70]
```
第m行的第n列的值，等于第m-1行第1列至第n列的值的和。行和列的规律是一模一样的。我们可以把矩阵简化为一个n * 1或者m * 1的矩阵。
```
    public int uniquePaths(int m, int n) {
        int[] res = new int[m];
        Arrays.fill(res,1);
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                res[j] = res[j - 1] + res[j];
            }

        }
        return res[m - 1];
    }
```