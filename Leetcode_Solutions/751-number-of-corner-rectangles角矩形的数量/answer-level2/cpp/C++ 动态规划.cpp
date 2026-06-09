也是看了题解，这里记录下，看自己能不能说明白。

* dp[j][k] 表示矩阵从第1行开始到当前正在处理的行，j点和k点两个点都为1的行的个数，比如下面的矩阵；
* 当i=0, dp[1][3]=0; 
* 当i=1, dp[1][3]=1; 
* 当i=2, dp[1][3]=2;
* 当i=3, dp[1][3]=3;
* 当i=3, dp[1][3]=3;
* 简单说dp[j][k]就是表示的截止到当前行 以j、k为顶点 的边数；记为边`j-k`
```
0 0 0 0 0
0 1 0 1 0
0 1 0 1 0
0 1 0 1 0
0 0 0 0 0
```
* 注意代码中的grid[i][j]和grid[i][k]；表示处理到第i行，发现这一行的j和k都为1；那我们以`j-k`为底边，往上找有几条边可以和这条边组成矩形；注意此时dp[j][k]  没有  更新，它正好表示的就是当前行之上的`j-k`边数
* 最后别忘了更新当前行的 dp[j][k]++，后面的行里可能还要用

```
int countCornerRectangles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    for (int k = j + 1; k < n; k++) {
                        if (grid[i][k]) {
                            ans += dp[j][k];
                            dp[j][k]++;
                        }
                    }
                }
            }
        }
        return ans;
    }
```
