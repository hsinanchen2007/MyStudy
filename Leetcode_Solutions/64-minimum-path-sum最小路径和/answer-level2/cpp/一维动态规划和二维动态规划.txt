### 二维动态规划

- `dp[i][j]` 表示到达 `[i][j]` 位置的最小路径和，对于第一行，其路径只能是从左到右；对于第一列，其路径只能是从上到下
- 对于其他位置，要到达 `[i][j]` 可以从 `[i-1][j]` 到达，也可以从 `[i][j-1]` 到达，所以，选择其中的更小者到达 `[i][j]`即可

### 一维动态规划

- 二维动态规划的化简版本，同样要注意第一行和第一列的特殊处理

**可能存在着数值越界的情况，这里的测试案例没有包含数值越界的情况**

```c++ []
// 二维动态规划
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        // 第一行和第一列处理
        for (int i = 1; i < n; i++) {
            grid[0][i] += grid[0][i - 1];
        }
        for (int i = 1; i < m; i++) {
            grid[i][0] += grid[i - 1][0];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[m - 1][n - 1];
    }
};
```

```c++ []
// 一维动态规划
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        // 初始化为第一行的数值
        vector<int> dp(grid[0]);
        for (int i = 1; i < n; i++) {
            dp[i] = grid[0][i] + dp[i - 1];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 第一列要进行特殊处理
                if (j == 0) {
                    dp[j] = grid[i][j] + dp[j];
                } else {
                    dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
                }
            }
        }
        return dp[n - 1];
    }
};
```