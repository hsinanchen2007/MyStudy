### Unique Paths II for DP
I have finished the Unique paths I and II .The unique difference between them is either have the obstacles.It is easy for us to think that there is  a obstacle that we can not through the grid.It means the dp[i][j]=0 (zero path!);

summary:
1.if m==0 and n==0,there are two situations: there is a obstacle,we can not pass.(dp[0][0]=0);
there is not a obstacle ,we can pass.(dp[0][0]=1);
2.We can not define the array dp by int ;Because when m and n >100 ,the figures are so large;
3.Judge the grid ,if there is a obstacle ,push 0 into the array dp directly;

Code：
```
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        long long  dp[m][n];
        if(obstacleGrid[0][0]==0) dp[0][0]=1;
        else dp[0][0]=0;
        for(int i=1;i<m;i++){
            if(obstacleGrid[i][0]==0&&dp[i-1][0]==1){
                dp[i][0]=1;
            }
            else dp[i][0]=0;
        }
        for(int i=1;i<n;i++){
            if(obstacleGrid[0][i]==0&&dp[0][i-1]==1){
                dp[0][i]=1;
            }
            else dp[0][i]=0;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==0){
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
                else dp[i][j]=0;
            }
        }
        return dp[m-1][n-1];
    }
};
```
