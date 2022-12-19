### 解题思路
首先预处理第一行和第一列的边界，在碰到障碍物之前的位置都置为1。之后在遇到障碍物时将此处的dp置为0，因为没有一条路可以到这里，剩下的地方就是常规处理了。

### 代码

```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            long long dp[120][120] = {0};
    
        if(obstacleGrid[0][0] == 1)
        {
         return 0;
        }
        else
            dp[0][0] = 1;
        for(int i = 0 ; i < obstacleGrid[0].size() ; ++i)
         {
            if(obstacleGrid[0][i] == 1)
            break;
            dp[0][i] = 1;
         }
        for(int i = 0 ; i < obstacleGrid.size() ; ++i)
        {
            if(obstacleGrid[i][0] == 1)
             break;
            dp[i][0] = 1;
         }
        for(int i = 1 ; i < obstacleGrid.size() ; ++i)
         {
             for(int j = 1 ; j < obstacleGrid[0].size(); ++j)
            {
                 if(obstacleGrid[i][j] != 1)
                 {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                //cout<<i<<" "<<j<<endl;
                //cout<<dp[i][j]<<endl;
                 }
               else
                    dp[i][j] = 0;
             }
         }
        return dp[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }
};
```