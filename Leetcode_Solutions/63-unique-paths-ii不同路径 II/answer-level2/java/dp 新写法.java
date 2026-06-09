### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        //if(obstacleGrid.length < 2)
		//	return 1;
		
		int m = obstacleGrid.length;
		int n = obstacleGrid[0].length;
		
		if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1)
			return 0;
		
		int[][] dp = new int[m][n];
		dp[0][0] = 1;
		
		/*for (int i = 1; i < m; i++) {
			if(obstacleGrid[i][0] == 0 && obstacleGrid[i-1][0] == 1)
				obstacleGrid[i][0] = 1;
		}
		for (int j = 1; j < n; j++) {
			if(obstacleGrid[0][j] == 0 && obstacleGrid[0][j-1] == 1)
				obstacleGrid[0][j] = 1;
		}*/
	
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if(obstacleGrid[i][j] == 1)
					continue;
				if(i > 0) {
					dp[i][j] += dp[i-1][j];
				}
				if(j > 0)
					dp[i][j] += dp[i][j-1];
			}
		}
		
		return dp[m-1][n-1];
		
		
    }
}
```
![image.png](https://pic.leetcode-cn.com/4bba7bd45752396d804100f36f941d13510504e2e084f5a346bce524208b4b49-image.png)
