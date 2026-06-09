```
#define min(a,b) ((a)<(b)?(a):(b))
int minPathSum(int** grid, int gridSize, int* gridColSize)
{
    int m = gridSize;
    int n = *gridColSize;
    
    int **dp = (int**)malloc(sizeof(int*)*m);
    for(int i=0;i<m;i++)
    {
        dp[i] = (int*)malloc(sizeof(int)*n);
    }
    
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        {
            if(i==0 && j==0)dp[0][0]=grid[0][0];
            else if(i==0 && j!=0)dp[i][j] =grid[i][j]+ dp[i][j-1];
            else if(i!=0 && j==0)dp[i][j] =grid[i][j]+ dp[i-1][j];
            else
            {
                dp[i][j]=grid[i][j] + min(dp[i][j-1],dp[i-1][j]);
            }
        }
    
    return dp[m-1][n-1];
}
```
