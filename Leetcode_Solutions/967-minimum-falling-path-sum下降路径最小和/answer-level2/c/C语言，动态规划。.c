```cpp
int minFallingPathSum(int** A, int ASize, int* AColSize){
    int dp[ASize][*AColSize];
       int result=INT_MAX;
    for(int i=0;i<*AColSize;i++)
    {
        dp[0][i]=A[0][i];
         if((0==ASize-1)&&(result>dp[0][i]))
            {
                result=dp[0][i];
            }
    }
    for(int i=1;i<ASize;i++)
    {
        for(int j=0;j<*AColSize;j++)
        {
            if(j==0)
            {
                dp[i][j]=dp[i-1][j]>dp[i-1][j+1]?dp[i-1][j+1]+A[i][j]:dp[i-1][j]+A[i][j];
            }
            else if(j==*AColSize-1)
            {
                dp[i][j]=dp[i-1][j-1]>dp[i-1][j]?dp[i-1][j]+A[i][j]:dp[i-1][j-1]+A[i][j];
            }
            else{
                int min=dp[i-1][j-1]>dp[i-1][j]?dp[i-1][j]:dp[i-1][j-1];
                min=min>dp[i-1][j+1]?dp[i-1][j+1]:min;
                dp[i][j]=min+A[i][j];
            }
            if((i==ASize-1)&&(result>dp[i][j]))
            {
                result=dp[i][j];
            }
        }
    }
 
  
    return result;
}
```
0.0.