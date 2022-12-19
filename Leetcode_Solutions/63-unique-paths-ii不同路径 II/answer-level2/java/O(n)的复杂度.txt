### 解题思路
记录上一行的结果

### 代码

```java
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        int[] cur = new int[n];
        int i = 1;
        if(obstacleGrid[0][0] == 1)
            cur[0] = 0;
        else
            cur[0] = 1;
        while(i<n)
        {
            if(obstacleGrid[0][i] == 1)
                cur[i] = 0;
            else
                cur[i] = cur[i-1];
            i++;
        }
        for(i=1; i<m; i++)
        {
            if(obstacleGrid[i][0] == 1)
                cur[0] = 0;
            for(int j = 1; j<n; j++)
            {
                if(obstacleGrid[i][j] == 1)
                    cur[j] = 0;
                else
                {
                    cur[j] += cur[j-1];
                }
            }
        }
        return cur[n-1];
    }
}
```