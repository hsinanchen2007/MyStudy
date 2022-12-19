
因为只能向右后者向下，所以初始化dp数组时 ,最上边和最左边的值都为1 
dp的值为到当前点的路径数

dp公式为 ：dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
```
public int uniquePaths(int m, int n) {
 int[][] map = new int[n][m];
        for (int i = 0;i < n;i++) {
            map[i][0] = 1;
        }
        for (int i = 0;i < m;i++) {
            map[0][i] = 1;
        }
        for (int i = 1;i < n;i++) {
            for (int j = 1;j < m;j++) {
                map[i][j] = map[i - 1][j] + map[i][j - 1] + map[i][j];
            }
        }
        return map[n - 1][m -1];
    }
```
