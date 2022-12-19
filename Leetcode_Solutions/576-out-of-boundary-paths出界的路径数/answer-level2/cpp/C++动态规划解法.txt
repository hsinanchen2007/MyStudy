状态：DP[i][j][N]为在(i,j)位置上走N步刚好走出边界的路径数
初始：处于边界的网格能走一步出边界
状态转移：(i,j)可以向上下左右四个方向走，从(i,j)走N步出边界的路径数 = (向上走一步，从(i-1,j)走N-1出边界的路径数)+ (向下走一步，从(i+1,j)走N-1出边界的路径数)+ (向左走一步，从(i,j-1)走N-1出边界的路径数)+ (向右走一步，从(i,j+1)走N-1出边界的路径数)
所求答案:等于(i,j)点走0-N次能出边界的路径数总和

时间复杂度O(m*n*N),空间复杂度O(m*n*N)
```C++ []
int findPaths(int m, int n, int N, int I, int J) {
        if(!N) return 0;
        vector<vector<vector<long> > > dp(m+2, vector<vector<long> >(n+2, vector<long>(N+1, 0))); //为了方便处理，在周围多一圈单元格
        #初始值
        for(int i = 1; i <= m; ++i){
            ++dp[i][1][1];
            ++dp[i][n][1];
        }
        for(int j = 1; j <= n; ++j){
            ++dp[1][j][1];
            ++dp[m][j][1];
        }
        #状态转移
        for(int k = 2; k <= N; ++k){
            for(int i = 1; i <= m; ++i){
                for(int j = 1; j <= n; ++j){
                    dp[i][j][k] = dp[i-1][j][k-1]+dp[i][j-1][k-1]+dp[i+1][j][k-1]+dp[i][j+1][k-1]; 
                    dp[i][j][k] %= 1000000007;
                }
            }
        }
        #求和
        long ans = 0;
        for(int i = 1; i <= N; ++i) ans += dp[I+1][J+1][i];
        return ans % 1000000007;
    }
```

优化空间复杂度为O(m*n)
```C++ []
int findPaths(int m, int n, int N, int I, int J) {
        if(!N) return 0;
        vector<vector<long> > pre(m+2, vector<long>(n+2, 0)), cur(m+2, vector<long>(n+2, 0));
        for(int i = 1; i <= m; ++i){
            ++pre[i][1];
            ++pre[i][n];
        }
        for(int j = 1; j <= n; ++j){
            ++pre[1][j];
            ++pre[m][j];
        }
        long ans = pre[I+1][J+1];
        for(int k = 2; k <= N; ++k){
            for(int i = 1; i <= m; ++i){
                for(int j = 1; j <= n; ++j){
                    cur[i][j] = pre[i-1][j]+pre[i][j-1]+pre[i+1][j]+pre[i][j+1]; 
                    cur[i][j] %= 1000000007;
                }
            }
            pre = cur;
            ans += pre[I+1][J+1];
        }
        return ans % 1000000007;
    }
```


