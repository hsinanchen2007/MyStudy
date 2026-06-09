障碍点看起来很麻烦，其实如果深刻理解dp数组的含义，就很简单

- dp[][]二维数组的含义是站在该点上，到end的距离为表示的值，故我们在初始化和开始动归时，进行是否为障碍点的判断，若是，将这一点的值人工置零即可


```
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        int[][] dp = new int[m][n];
        
        if(obstacleGrid[0][0] == 1){return 0;}
        
        for(int i=0; i<n; i++)
        {
            if(obstacleGrid[0][i] == 1)
            {
                for(;i<n;i++){dp[0][i] = 0;}
            }
            else
            {
                dp[0][i] = 1;
            }
        }
        
        for(int i=0; i<m; i++)
        {
            if(obstacleGrid[i][0] == 1)
            {
                for(;i<m;i++){dp[i][0] = 0;}
            }
            else
            {
                dp[i][0] = 1;
            }
        }
        
        for(int k=1; k<m; k++)
        {
            for(int j=1; j<n; j++)
            {
                if(obstacleGrid[k][j]==1){dp[k][j] = 0;}
                else
                {
                   dp[k][j] = dp[k-1][j]+dp[k][j-1]; 
                }
            }
        }
        
        return dp[m-1][n-1]; 
    }
}
```
