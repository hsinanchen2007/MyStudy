int min(int a,int b)
{
     return a<b?a:b;
}
  int minPathSum(int** grid, int gridSize, int* gridColSize){
      int m = gridSize;
      int n =* gridColSize;
      int i=0;
      int j=0;
      int **dp=(int **)malloc(m*sizeof(int*));
      for(i=0;i<m;i++)
      { 
       dp[i]=(int *)malloc(n*sizeof(int));
      }
      dp[0][0]= grid[0][0];
      //第一行只能是向右走
      for(j=1;j<n;j++)
      {
           dp[0][j]=grid[0][j]+dp[0][j-1];
      }
      //第一列只能是向下走
      for(i=1;i<m;i++)
      {
            dp[i][0]=grid[i][0]+dp[i-1][0];
      }
      for(j=1;j<n;j++)
      {
          for(i=1;i<m;i++)
        {
             dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
        }
      }
      return dp[m-1][n-1];
}