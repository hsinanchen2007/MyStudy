### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int uniquePaths(int m, int n) {
        //m行n列，右下角的坐标(m-1,n-1)
		//dp[i][j]表示走到(i,j)这个格子的不同路径的总和
		int[][] dp = new int[m][n];
		
		//初始化
		dp[0][0] = 1;
		for (int i = 1; i < m; i++) {
			dp[i][0] = 1;
		}
		for (int i = 1; i < n; i++) {
			dp[0][i] = 1;
		}
		
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
			}
		}
		
		return dp[m-1][n-1];
    }
}
```
![image.png](https://pic.leetcode-cn.com/03595d03ad62f9e5c62239669a71d960ea3c1a906b7576f89ac4be80b6f76c2e-image.png)
