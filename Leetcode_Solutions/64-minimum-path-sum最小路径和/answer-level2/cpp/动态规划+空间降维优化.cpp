### 解题思路

首先，符合动态规划特征：1）求最优解问题；2）具有最优解子结构，从左上角点（0,0）-->(i,j)的最短
路径f[i,j] = min(f[i,j-1], f[i-1, j]) + grid[i][j]
其次：
   1)对于第一行i=0 只能从左往右走，f[0][0] = grid[0][0], f[0][j]=f[0][j-1] + grid[0][j] j>0;
   2)对于第一列j=0 只能从上往下走, 所以f[i][0] = f[i-1][0] + grid[i][0];
   3)其他位置f[i,j] = min(f[i,j-1], f[i-1, j]) + grid[i][j]
问题的解，即是f[m-1][n-1]，时间复杂度O(m*n)

降维度：上述解法中，空间复杂度为O(m*n)
如果我们按照列的顺序求f[i][j], 例如:
1) j=0, 我们发现f[i][j]只与f[i-1][j]+grid[i][j]相关，除了
f[0][0] = grid[0][0];
2) j>0时，f[i][j]也只与它的上面，左边的f值相关，除了f[0][j]（只与左边相关）

因此，我们只需要一个大小为m的数组记录f值即可。空间复杂度降为O(m),时间复杂度不变O(m*n)

### 代码

```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        if (n == 0)
            return 0;

        //dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + grid[i][j]
        //优化空间,降维

        //vector<int>dp(m);
        int *dp = new int[m];
        int ret;
        dp[0] = grid[0][0];
        //计算第一列的最短路径和
        for (int i=1; i<m; i++)
            dp[i] = dp[i-1] + grid[i][0];
        //其他列，依次计算
        for (int j=1; j<n; j++) {
            dp[0] = dp[0] + grid[0][j];
            for (int i=1; i<m; i++) {
                dp[i] = min(dp[i-1], dp[i]) + grid[i][j];
            }
        }
        //ret = dp[m-1];
        //delete[] dp;
        return dp[m-1];
    }
};
```