```
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty()||obstacleGrid[0][0]==1)
            return 0;
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        long ans[m][n];
        ans[0][0]=1;
        for(int i=1;i<n;i++)
        {
            if(obstacleGrid[0][i]!=1&&ans[0][i-1]==1)
                ans[0][i]=1;
            else
                ans[0][i]=0;
        }
        for(int i=1;i<m;i++)
        {
            if(obstacleGrid[i][0]!=1&&ans[i-1][0]==1)
                ans[i][0]=1;
            else
                ans[i][0]=0;
        }
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
            {
                if(obstacleGrid[i][j]!=1)
                    ans[i][j]=ans[i-1][j]+ans[i][j-1];
                else
                    ans[i][j]=0;
            }
        return ans[m-1][n-1];
    }
};
```
