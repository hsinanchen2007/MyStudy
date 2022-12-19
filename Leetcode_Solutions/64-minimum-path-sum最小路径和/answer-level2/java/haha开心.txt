### 解题思路
此处撰写解题思路
入门之路如此艰难

### 代码

```java
class Solution {
    public int minPathSum(int[][] grid) {
        int m = grid.length;
		int n = grid[0].length;
		
//		int[][] dp = new int[m][n]; //dp[i][j]表示到达(i,j)坐标的路径和
		
		//初始化
		//grid[i][j]表示到达(i,j)坐标的路径和
		for(int i = 1;i < m;i ++) {
			grid[i][0] += grid[i-1][0];
		}
		for(int j = 1;j < n;j ++) {
			grid[0][j] += grid[0][j-1];
		}
		
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				grid[i][j] += Math.min(grid[i][j-1], grid[i-1][j]);
			}
		}
		return grid[m-1][n-1];
    }
}
```
![image.png](https://pic.leetcode-cn.com/4a5a2b08945d60a639c826b5ca5d3f5c74ed26e8ec5eb378f54907ea6395413b-image.png)
