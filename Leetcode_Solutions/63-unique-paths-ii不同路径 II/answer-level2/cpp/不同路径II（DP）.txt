### 解题思路
- 与不同路径I相似，增加了障碍物。因为障碍物的存在，使得第一行或第一列若出现了障碍物，那么它之后的每个格子都无法到达。比如第一行第二个格子出现了障碍物，那么第一行第二个格子往后的所有格子都无法到达，dp[][]值应该设为0；
- 按照上述思路，先把第一行和第一列的dp数组值确定，也就是边界。然后遍历其他格子，如果没有障碍物，则使用状态转移方程计算dp值，如果有障碍物则不进行操作（dp数组已经初始化为0）

### 代码

```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        long dp[m][n];
        fill(dp[0], dp[0] + m * n, 0);  //dp数组初始化为0，方便边界的设定
        for(int i = 0; i < n; i++){     //设置第一行的边界
            if(obstacleGrid[0][i] == 0){
                dp[0][i] = 1;
            }else{
                break;
            }
        }
        for(int i = 0; i < m; i++){     //设置第一列的边界
            if(obstacleGrid[i][0] == 0){
                dp[i][0] = 1;
            }else{
                break;
            }
        }
        for(int i = 1; i < m; i++){     //遍历矩阵，计算dp值
            for(int j = 1; j < n; j++){
                if(obstacleGrid[i][j] == 0){
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
```