### 解题思路 动态规划
与[不同路径](https://leetcode-cn.com/problems/unique-paths/solution/dong-tai-gui-hua-zu-he-shu-xue-_62bu-tong-lu-jing-/)相同

    /*
     * 动态规划
     *
     * 1. 将该问题分解为较小的子问题：
     *    因为是求矩阵从第一个点到最后一个点的礼物最大值，不妨先求第一点到第二点的礼物最大值，
     *    而第二点的礼物最大值，又由第二点礼物的值和第一点礼物的最大值的和决定。因为只能向右或向下走，
     *    所以取上面点或下面点中较大的礼物最大值再加上当前点的礼物值，即为当前点的礼物最大值。以此类推。
     * 2. 初始化
     *    定义礼物最大值矩阵，对应于礼物值矩阵。初始化礼物最大值矩阵的第一行和第一列。
     * 3. 状态转移方程：
     *    dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]) + grid[i][j]
     * */
### 代码

```cpp
int maxValue(std::vector<std::vector<int>> &grid) {
    if (grid.empty()) {
        return 0;
    }

    // 矩阵的行数和列数
    int m = grid.size();
    int n = grid[0].size();

    // 存储当前礼物最大值的矩阵，
    // 对应礼物矩阵的每个点
    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));

    // 对礼物最大值矩阵的第一行和第一列初始化
    dp[0][0] = grid[0][0];

    for (int i = 1; i < m; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for (int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    // 当前点的礼物最大值是当前礼物的值加上左点或上点礼物最大值中较大的值
    // 状态转移方程:
    // dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]) + grid[i][j]
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }

    // 返回礼物最大值矩阵的最后一个点的值
    return dp[m - 1][n - 1];
}
```

### 优化 ： 动态规划+压缩空间
    /*
     * 动态规划+空间压缩
     *
     * 根据上面动态规划的方法，可以将礼物最大值矩阵即状态矩阵压缩为一维矩阵。
     * 因为dp[j]的值在更新前仍然为该点上面点的礼物最大值，所以将dp[j]与dp[j-1]比较，
     * 和dp[i-1][j]与dp[i][j-1]的比较结果是相同的。
     * 所以状态转移方程修改为：
     * dp[j + 1] = std::max(dp[j], dp[j + 1]) + grid[i][j];
     *
     * 注意：如果状态转移方程修改为：
     * dp[j] = std::max(dp[j], dp[j - 1]) + grid[i][j];
     * 需要初始化dp[j]的值，并且在遍历礼物矩阵时也要初始化左侧的值，即：
     * dp[j] = dp[j-1] + grid[0][j]     // 初始化时，0 <= j < n
     * dp[0] += dp[i][0]                // 遍历i时， 1 <= i < m
     * */
### 代码

```cpp
int maxValue2(std::vector<std::vector<int>> &grid) {
    if (grid.empty()) {
        return 0;
    }

    // 矩阵的行数和列数
    int m = grid.size();
    int n = grid[0].size();

    // 存储当前礼物的最大值
    std::vector<int> dp(n + 1, 0);

    // dp[j+1]保存上一点的最大值
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            dp[j + 1] = std::max(dp[j], dp[j + 1]) + grid[i][j];
        }
    }

    return dp[n];

//    // 初始化第一行的礼物最大值
//    for (int j = 0; j < n; j++) {
//        dp[j] = dp[j - 1] + grid[0][j];
//    }
//
//    for (int i = 1; i < m; i++) {
//        // 初始化第一列的礼物最大值
//        dp[0] += grid[i][0];
//
//        // 因为dp[j]在更新前仍然是上面点的礼物最大值，
//        // 所以可以利用此压缩空间
//        for (int j = 1; j < n; j++) {
//            dp[j] = std::max(dp[j], dp[j - 1]) + grid[i][j];
//        }
//    }
//
//    return dp[n - 1];
}
```