### 解题思路
每一个数字的路径和为左边加上上边的数字的路径之和，需注意第一行和第一列必定都是1，这个可以先初始化
递推转移方程为：
dp[i][j] = dp[i][j-1] + dp[i-1][j]

### 代码
Python
```python
class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        if n==1 or m==1:
            return 1
        dp = [[0]*m]*n #初始化n行m列
        for i in range(0,n):
            for j in range(0,m):
                if i==0 or j==0:
                    dp[i][j] = 1
                else:
                    dp[i][j] = dp[i][j-1] + dp[i-1][j]
        return dp[-1][-1]
```
golang
```golang
func uniquePaths(m int, n int) int {
	if n==1|| m==1{
		return 1
	}
	var dp = make([][]int,n)
	for i:=0;i<n;i++{
		dp[i] = make([]int,m)
	}
	for i:=0;i<n;i++{
		for j:=0;j<m;j++{
			if i==0 || j==0{
				dp[i][j] = 1
			}else{
				dp[i][j] = dp[i][j-1] + dp[i-1][j]
			}

		}
	}
	return dp[n-1][m-1]
}
```
java
```java
	public int uniquePaths(int m, int n) {
		 if (m==1 || n==1){
			 return 1;
		 }	 
		 int[][] dp = new int[n][m];
		 for (int i=0;i<n;i++){
			 for (int j=0;j<m;j++){
				 if (i==0 || j==0){
					 dp[i][j] = 1;
				 }else{
					 dp[i][j] = dp[i][j-1] + dp[i-1][j];
				 }
			 }
		 }
		 
		 return dp[n-1][m-1];
	 }
```