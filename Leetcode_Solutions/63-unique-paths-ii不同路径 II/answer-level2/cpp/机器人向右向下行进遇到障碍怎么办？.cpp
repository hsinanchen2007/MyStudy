### 解题思路
因为完成了机器人不同路径I的题，这个题上来就有思路，就是在整型范围上出了差错。
还是从最小问题出发：单行、单列的情况，如果单行（列）中有障碍，有0条路径,
    初始状态 dp[row-1][j]、dp[i][col-1]可根据上面的考虑确定
        以dp[row-1][j]为起点向右行进，途中没有障碍，dp[row-1][j]=1,否则=0;
    同理，以dp[i][col-1]为起点向下行进，途中没有障碍，dp[i][col-1]=1,否则=0;
之后的状态方程与不同路径I中相同：
    dp[i][j]=dp[i+1[j]]+dp[i][j+1], (i,j)位置不是路障
    dp[i][j]=0, (i,j)位置为路障

### 代码

```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row=obstacleGrid.size(), col=obstacleGrid[0].size();
        if(row<1 || col<1 || row>100 || col>100) return 0;
        long dp[row][col];
        for(int j=col-1; j>=0; j--){
            dp[row-1][j]=1;
            if(obstacleGrid[row-1][j]==1){
                while(j>=0) dp[row-1][j--]=0;
            }
        }
        for(int i=row-1; i>=0; i--){
            dp[i][col-1]=1;
            if(obstacleGrid[i][col-1]==1){
                while(i>=0) dp[i--][col-1]=0;
            }
        }
        for(int i=row-2; i>=0; i--){
            for(int j=col-2; j>=0; j--){
                if(obstacleGrid[i][j]==1) dp[i][j]=0;
                else dp[i][j]=dp[i+1][j]+dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};
```