### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<long>> dp(m,vector<long>(n,0));
        
        if(m == 1 && n == 1 && obstacleGrid[0][0] == 0) return 1;
        if(obstacleGrid[0][0] == 1) return 0;
        

        for(int i = 1; i <= m-1; ++i){
            if(obstacleGrid[i][0] == 0) dp[i][0] = 1;
            else break;         
        }
        for(int j = 1; j <= n-1; ++j){
            if(obstacleGrid[0][j] == 0) dp[0][j] = 1;
            else break;
        }
        for(int i = 1; i <= m -1; ++i){
            for(int j = 1; j <= n - 1; ++j){
                if(obstacleGrid[i][j] != 1)
                 dp[i][j] = dp[i][j-1] + dp[i-1][j];    
            }
        }
        return dp[m-1][n-1];
    }
};
```