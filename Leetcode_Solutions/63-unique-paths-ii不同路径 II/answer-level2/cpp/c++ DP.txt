### 解题思路
在62题基础上增加了障碍物，所以在首先确定最后一行、最后一列的走法时需要特殊处理
1. 在最后一列或最后一行时，从最后的元素出发，第一个障碍之前的元素均为1，其后元素为0
2. 从倒数第二行，倒数第二列，统计从改点出发的走法

### 代码

```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) {
            return 0;
        }
        int row = obstacleGrid.size();
        int column = obstacleGrid[0].size();
        // 使用long，否则int类型提交溢出
        vector<vector<long>> dp(row, vector<long>(column, 0));
        // 每行最后一列，只有向下走一种方式
        for (int i = row - 1; i >= 0; --i) {
            if (obstacleGrid[i][column - 1] == 0) {
                dp[i][column - 1] = 1;
            } else {
                break;
            }
        }
        // 最后一行每一列，只有向右走一种方式
        for (int i = column - 1; i >= 0; --i) {
            if (obstacleGrid[row - 1][i] == 0) {
                dp[row - 1][i] = 1;
            } else {
                break;
            }
        }

        // DP[i, j] = DP[i-1, j] + DP[i, j-1];
        for (int i = row - 2; i >= 0; --i) {
            for (int j = column - 2; j >= 0; --j) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i + 1][j] + dp[i][j+1];
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[0][0];
    }
};
```