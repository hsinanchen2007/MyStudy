枚举上一行的状态，搜索这一行所有可能的填写情况。
```
class Solution {
    int [][]dp;
    boolean [][]vis;
    void dfs(int sta, int cur, int row, int col, int m, int now) {
        if (col == m) {dp[row][cur] = Math.max(dp[row][cur], now + dp[row - 1][sta]);return;}
        if (vis[row][col]) {
            dfs(sta, cur | (1 << col), row, col + 1, m, now);
        } else {
            if (col + 2 <= m && vis[row][col + 1] == false) {
                int tmp = cur | (1 << col);
                tmp = tmp | (1 << (col + 1));
                dfs(sta, tmp, row, col + 2, m, now + 1);
            }
            if (((sta >> col) & 1) != 1) {
                dfs(sta, cur | (1 << col), row, col + 1, m, now + 1);
            } else {
                dfs(sta, cur, row, col + 1, m, now);
            }
        }
    }
    public int domino(int n, int m, int[][] broken) {
        dp = new int[n + 1][(1 << m)];
        vis = new boolean[n + 1][m];
        for (int[]tmp : broken) {vis[tmp[0] + 1][tmp[1]] = true;};
        for (int i = 0; i <= n; ++i) Arrays.fill(dp[i], -99999);
        dp[0][(1 << m) - 1] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int sta = 0; sta < (1 << m); ++sta) {
                dfs(sta, 0, i, 0, m, 0);
            }
        }
        int ans = -99999;
        for (int i = 0; i < (1 << m); ++i) ans = Math.max(dp[n][i], ans);
        return ans;
    }
}
```
