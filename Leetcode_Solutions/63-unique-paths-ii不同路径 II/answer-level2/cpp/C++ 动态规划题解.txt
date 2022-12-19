```
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    	int n = obstacleGrid.size();
    	if(n==0) return 0;
    	int m = obstacleGrid[0].size();
		if(obstacleGrid[0][0] == 1) return 0;
		long long int dp[n][m];
		dp[0][0] = 1;
    	for(int i=1;i<n;i++)
    	dp[i][0] = obstacleGrid[i][0] == 0 ? dp[i-1][0] : 0;
    	
    	for(int i=1;i<m;i++)
    	dp[0][i] = obstacleGrid[0][i] == 0 ? dp[0][i-1] : 0;
    	
    	for(int i=1;i<n;i++)
    	for(int j=1;j<m;j++)
    		dp[i][j] = obstacleGrid[i][j]==0?dp[i-1][j] + dp[i][j-1] : 0;


    	
        return dp[n-1][m-1];
    }
};
```
