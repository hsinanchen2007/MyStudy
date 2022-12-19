### 思路一：DP
类似[62. 不同路径](https://leetcode-cn.com/problems/unique-paths/solution/62-bu-tong-lu-jing-jian-dan-dong-tai-gui-hua-ji-yo/)
添加障碍物判断，如果有障碍物则设置为0.
**注意**：使用long int防止溢出

### 代码
时间复杂度：O(mn)
空间复杂度：O(mn)
```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty()) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<long int>> dp(m, vector<long int>(n));
        //1. 设置第一列
        for (int i = 0; i < m; ++i) {
            if (obstacleGrid[i][0] == 0) {
                dp[i][0] = 1;
            } else {
                dp[i][0] = 0;
                while (i < m) {
                    dp[i++][0] = 0;
                }
            }
        }
        //2. 设置第一行
        for (int j = 0; j < n; ++j) {
            if (obstacleGrid[0][j] == 0) {
                dp[0][j] = 1;
            } else {
                dp[0][j] = 0;
                while (j < n) {
                    dp[0][j++] = 0;
                }
            }
        }
        //3. 一行一行设置
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
```

### 简化代码
```c++
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty()) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<long int>> dp(m + 1, vector<long int>(n + 1, 0));
        dp[0][1] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (obstacleGrid[i - 1][j - 1] != 0) { //注意是i - 1 和 j - 1
                    continue;
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};
```
