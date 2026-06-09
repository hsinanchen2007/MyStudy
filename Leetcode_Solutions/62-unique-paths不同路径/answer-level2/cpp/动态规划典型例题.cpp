## 动态规划
状态转移方程：
$f[i][j] = f[i-1][j] + f[i][j-1]$

## 代码
```
int uniquePaths(int m, int n) {
      int f[m][n];
      for (int i = 0; i < m; ++i) {
	    for (int j = 0; j < n; ++j){
		  if (i == 0 || j == 0)
			f[i][j] = 1;
		  else
			f[i][j] = f[i-1][j] + f[i][j-1];
	    }
      }
      return f[m-1][n-1];
}

```
