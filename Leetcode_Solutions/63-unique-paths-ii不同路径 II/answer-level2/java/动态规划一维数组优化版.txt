### 解题思路
凡是这种二维数组的都可以用一维数组来优化：

### 代码

```java
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m=obstacleGrid.length;
        int n=obstacleGrid[0].length;
        int[] dp=new int[n];
        dp[0]=1;//初始dp[0]=1
        for(int i=0;i<m;i++){
            if(obstacleGrid[i][0]==0)  dp[0]=dp[0];//如果当前方格元素为0，则dp[0]为1，一旦某一行第一个元素为1，则它它连同它之后的都为0，表示之后的都没有路径
            else dp[0]=0;
            for(int j=1;j<n;j++)
            {
                if(obstacleGrid[i][j]==0)
                    dp[j]=dp[j-1]+dp[j];
                else{
                    dp[j]=0;
                }
            }
        }
        return dp[n-1];
    }
}
```