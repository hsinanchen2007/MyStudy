### 解题思路
定义dp[i][j]：在第i行的第j列的这个格子，到右下角的重点有多少条路径可走。
1、采用DP进行求解，得状态转移方程： dp[i][j] = dp[i+1][j] + dp[i][j+1];
2、进行状态初始化：  1、dp[m][n] = 1; 2、所有obstacleGrid[i-1][j-1] == 1的，对应的dp[i][j] = 0(因为是障碍物所在地);
3、用例优化：<PS:私下认为这个用例限制不可取，其在做DP累加时，超出了Int的限制大小，需要将DP内的数组改为long long 才可以存储>;
### 代码

```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<long long>> dp(obstacleGrid.size() + 1, vector<long long>(obstacleGrid[0].size() + 1, 0));
        for (int i = obstacleGrid.size(); i > 0; i--) {
            for (int j = obstacleGrid[0].size(); j > 0; j--) {
                if (i == obstacleGrid.size() && j == obstacleGrid[0].size() && obstacleGrid[i - 1][j - 1] != 1) {
                    dp[obstacleGrid.size()][obstacleGrid[0].size()] = 1;
                    continue;
                }
                if (obstacleGrid[i - 1][j - 1] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                long long downCount = 0;
                long long rightCount = 0;
                if (i + 1 <= obstacleGrid.size()) {
                    downCount = dp[i + 1][j];
                }
                if (j + 1 <= obstacleGrid[0].size()) {
                    rightCount = dp[i][j + 1];
                }
                dp[i][j] = downCount + rightCount;
            }
        }
        return static_cast<int>(dp[1][1]);
    }
};
```