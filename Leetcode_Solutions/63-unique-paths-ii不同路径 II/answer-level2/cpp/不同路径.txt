### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size() == 0)
            return 0;
        int row = obstacleGrid.size();      //行 
        int col = obstacleGrid[0].size();   //列
        if(obstacleGrid[0][0] == 1 || obstacleGrid[row-1][col-1] == 1)
            return 0;                      //排除终点和起点有障碍物的情况
        //dp[i][j]:到达坐标（i,j）的路径数
        //dp[i][j] = dp[i-1][j]+dp[i][j-1] 
        vector<vector<unsigned long long>>dp(row,vector<unsigned long long>(col,0));   
        dp[0][0]=1;
        for(int i = 1;i < row;i++){          //第一行和第一列需要单独判断
            if(obstacleGrid[i][0])          //行和列上路径数只跟上一行或列相同，或者为0
                dp[i][0] = 0;
            else dp[i][0] = dp[i-1][0];
        }
         for(int i = 1;i < col;i++){
            if(obstacleGrid[0][i])
                dp[0][i] = 0;
            else dp[0][i] = dp[0][i-1];
        }     
        
        for(int i = 1;i < row;i++){
            for(int j = 1;j < col;j++){
                if(obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[row-1][col-1];
    }
};
```