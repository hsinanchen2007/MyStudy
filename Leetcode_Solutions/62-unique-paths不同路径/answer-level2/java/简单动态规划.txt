```
	public int uniquePaths(int m, int n) {
        int dp[][] = new int[m][n];
		//初始化左边路径
        for(int i =0;i<m;i++){
            dp[i][0] =1;
        }
		//初始化上边路径
        for(int j=1;j<n;j++){
            dp[0][j]=1;
        }
		//状态方程：终点的值等于左边格的路径和加上上边格的路径和~
        for(int i =1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = dp[i-1][j] + dp [i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
```
[与之相似的63题](https://leetcode-cn.com/problems/unique-paths-ii/solution/javadai-ma-zai-62ti-ji-chu-shang-shao-zuo-xiu-gai-/)
