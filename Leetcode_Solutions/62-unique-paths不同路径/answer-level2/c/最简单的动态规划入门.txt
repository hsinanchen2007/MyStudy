动态规划要确认几个东西
1、最终怎么来？这个从左上角走到右下角只能往下走和右走，那么
DP[M][N] = DP[M - 1][N] + DP[M][N-1];
2、上式M = 0 或者N = 0会越界，考虑M = 0和N = 0 ，分别相当于靠着边走，那么DP[0][N]和DP[M][0]均为1

#define MAXROW 100
#define MAXCOL 100
int uniquePaths(int m, int n){

    int dp[MAXROW][MAXCOL];
    for (int i = 0; i < n; i++) {
        dp[0][i] = 1;
    }
    for (int i = 0; i < m; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}