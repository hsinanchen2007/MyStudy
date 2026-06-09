### 解题思路
还是按照左侧跟上侧进行相加，转换成一维dp，然后对于obstacle的数据，先进行判断，等于1则直接将该处的dp赋值为0，
这里需要注意一个第一列的边界，每次循环需要进行判定。

### 代码

```java
class Solution{
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m=obstacleGrid.length;
        int n= m==0? 0:obstacleGrid[0].length;
        int[] dp=new int[n];
        for (int j=0;j<n;j++)
        {
            if (obstacleGrid[0][j]==0)
            {
                dp[j]=1;
            }
            else
            {
                break;
            }
        }
        for (int i=1;i<m;i++)
        {
            if (obstacleGrid[i][0]==1)
                dp[0]=0;
            for (int j=1;j<n;j++)
            {
                if (obstacleGrid[i][j]==1)
                {
                    dp[j]=0;
                    continue;
                }
                dp[j]=dp[j]+dp[j-1];

            }
        }
        return dp[n-1];
    }
}
```