![image.png](https://pic.leetcode-cn.com/bab931d3e34fb1e6e33277688a6bda2f4b3388f2138e91175835f15ea793de57-image.png)
重新申请一个矩阵用来保存该点所在的矩阵的最大的边长是多少，
该方法可以用动态规划简单实现，假如该点所在的最大的边长为3，
则让结果+3即可，也就是该点可作为边长为1，为2，为3的三种结果，
所以是加3。直接看代码吧，代码很简单。
```
public int countSquares(int[][] matrix) {
		int m = matrix.length;
		int n = m == 0 ? 0 : matrix[0].length;
		int res = 0;
		int[][] ans = new int[m + 1][n + 1];
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (matrix[i - 1][j - 1] == 1) {
					ans[i][j] = Math.min(Math.min(ans[i - 1][j], ans[i][j - 1]),
							ans[i - 1][j - 1]) + 1;
					res += ans[i][j];
				}
			}
		}
		return res;
	}
```
