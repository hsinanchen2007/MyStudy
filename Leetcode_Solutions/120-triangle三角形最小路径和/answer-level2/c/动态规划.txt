### 解题思路
此处撰写解题思路
才开始用dfs做了好久，超时了
### 代码

```c
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
    int min,i,j,dp[triangleSize][triangleSize];
    dp[0][0]=triangle[0][0];
    for(i=1;i<triangleSize;i++){
        for(j=0;j<triangleColSize[i]-1;j++){
            if(j>0)
                dp[i][j]=dp[i-1][j]<dp[i-1][j-1]?dp[i-1][j]:dp[i-1][j-1];
            else if(j==0) dp[i][j]=dp[i-1][j];
            dp[i][j]+=triangle[i][j];
            //printf("%d ",dp[i][j]);
        }
        dp[i][j]=dp[i-1][j-1]+triangle[i][j];
        //printf("%d\n",dp[i][j]);
    }
    min=dp[triangleSize-1][0];
    for(i=1;i<triangleSize;i++)
        if(dp[triangleSize-1][i]<min) min=dp[triangleSize-1][i];
    return min;
}
```