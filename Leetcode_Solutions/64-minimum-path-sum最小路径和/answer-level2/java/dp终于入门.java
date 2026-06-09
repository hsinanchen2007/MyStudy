### 解题思路
此处撰写解题思路
小白思路简单

### 代码

```java
class Solution {
    public int minPathSum(int[][] grid) {
        int m = grid.length;
		int n = grid[0].length;
		
		int[][] dp = new int[m][n]; //dp[i][j]表示到达(i,j)坐标的路径和
		
		//初始化
		dp[0][0] = grid[0][0];
		for(int i = 1;i < m;i ++) {
			dp[i][0] = dp[i-1][0] + grid[i][0];
		}
		for(int j = 1;j < n;j ++) {
			dp[0][j] = dp[0][j-1] + grid[0][j];
		}
		
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				dp[i][j] = Math.min(dp[i][j-1], dp[i-1][j]) + grid[i][j];
			}
		}
		return dp[m-1][n-1];
    }
}
```
![image.png](https://pic.leetcode-cn.com/ee7ca8853a8ca0ac443ae9a9a8d8451350e08ea659b40c355bc97029a75de2f0-image.png)
