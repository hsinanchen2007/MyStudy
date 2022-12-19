状态变量和状态方程都很好考虑
**状态变量**
dp[i][j] 移动到(i,j)位置有几个方案
**状态转移方程**：
两种情况  如果当前位置有障碍   dp[i][j]=0;
         如果当前位置没有障碍  dp[i][j]=dp[i][j-1]+dp[i-1][j];

还有一个从**初始状态**
dp[0][0] 这里的值我一开始以为是2，但是并不是，移动到初始位置的方案只有1，比较有毒的是正常人谁会在起点处放障碍啊。。但是还是需要加个判断   
接着就是上边界和左边界的情况，都是只有一种情况，也就是从它上一个格子走过来。


```
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid[0].size(),n=obstacleGrid.size();
        if(m==1&&n==1)
            return !obstacleGrid[0][0];
        vector<vector<long long> >dp(n,vector<long long>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(obstacleGrid[i][j])
	                dp[i][j]=0;
                else if(i==0&&j==0)
                    dp[i][j]=1;   //初始位置比较特殊
                else if(i==0)
                    dp[i][j]=dp[i][j-1];
                else if(j==0)
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=dp[i][j-1]+dp[i-1][j];
            }
        }
        return dp[n-1][m-1];
    }
};
```
