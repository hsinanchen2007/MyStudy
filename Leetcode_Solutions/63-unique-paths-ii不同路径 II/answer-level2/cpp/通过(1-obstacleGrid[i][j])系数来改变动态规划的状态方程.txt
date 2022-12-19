## 63.不同路径II

继62题不同路径I的解法。由于存在障碍，故只需要特别处理障碍的单元。
由于存在障碍，则障碍处的路径数应该为 0 。由从题目中可以得到obstacleGrid，且网格中的障碍物和空位置分别用 1 和 0 来表示。所以只需要在62.不同路径I的状态方程的基础上乘上
(1-obstacleGrid[i][j])
若此处为障碍物，则该项值为0；若不为障碍物，则该项值为1，对于状态转移方程不存在影响。

同时考虑到int相加溢出的问题，这里使用long类型。

__代码如下：__
```c++
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(), n=obstacleGrid[0].size();
        vector<vector<long>> dp(m, vector<long>(n));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0) {
                    if(j==0) dp[i][j]=1*(1-obstacleGrid[i][j]);
                    else dp[i][j]=dp[i][j-1]*(1-obstacleGrid[i][j]);
                }else{
                    if(j==0) dp[i][j]=dp[i-1][j]*(1-obstacleGrid[i][j]);
                    else dp[i][j] = (dp[i-1][j] + dp[i][j-1])*(1-obstacleGrid[i][j]);
                }
            }
        }
        return int(dp[m-1][n-1]);
    }
};
```
