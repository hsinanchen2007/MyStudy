```
class Solution {
	private int dp[][];
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
    	int m=obstacleGrid.length;
    	int n=obstacleGrid[0].length;
        if(m==1&&n==1&&obstacleGrid[0][0]==1)return 0;
    	else if(m==1&&n==1&&obstacleGrid[0][0]==0)return 1;
        else if(m==1&&n==2&&obstacleGrid[0][1]==1)return 0;
        else if(m==2&&n==1&&obstacleGrid[1][0]==1)return 0;
    	dp=new int[m+1][n+1];
    	if(obstacleGrid[m-1][n-1]==0)
    	dp[m-1][n-1]=1;
    	if(obstacleGrid[m-1][n-1]==1)
        	dp[m-1][n-1]=0;
    	for(int i=n-2;i>=0;--i)
    	{
    		if(obstacleGrid[m-1][i]==1)
    			dp[m-1][i]=0;
    		else
    		{
    			dp[m-1][i]=dp[m-1][i+1]+dp[m][i];
    		}
    	}
    	for(int i=m-2;i>=0;--i)
    	{
    		if(obstacleGrid[i][n-1]==1)
    			dp[i][n-1]=0;
    		else
    		{
    			dp[i][n-1]=dp[i+1][n-1]+dp[i][n];
    		}
    	}
    	for(int i=m-2;i>=0;--i)
    	{
    		for(int j=n-2;j>=0;--j)
    		{
    			if(obstacleGrid[i][j]==1)
    				dp[i][j]=0;
    			else
    			{
    				dp[i][j]=dp[i][j+1]+dp[i+1][j];
    			}
    		}
    	}
    	return dp[0][0];
        
    }
}


```
