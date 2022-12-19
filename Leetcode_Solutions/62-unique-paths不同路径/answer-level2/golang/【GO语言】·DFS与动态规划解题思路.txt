### 解题思路
这道题拿到手里的第一反应是DFS回溯法。每个点判断往下或者往右一步是不是到边界，到边界计数加一，没到边界更换当前点为基准点。
```
	//DFS : Runtime Error if m or n is a large number.
	func uniquePaths(m int, n int) int {
		cnt:=0
		var dfs func(x int,y int)
		dfs = func(x int,y int){
			if x==(m-1)||y==(n-1){
				cnt++
				return
			}else{
				dfs(x+1,y)
				dfs(x,y+1)
			}
		}
		dfs(0,0)
		return cnt
	}
```
但是看到数据范围，m=100,n=100时，应该是会超时的，所以转念想到DP动态规划方法。可以很容易的知道，针对非边界的点，dp[x,y]=dp[x-1,y]+dp[x,y-1]，而左边界与上边界的点dp值都为1，因为仅有一直往那个方向走一种方法。最后[m-1,n-1]这个点的dp值就是我们需要的结果。

### 代码

```golang
func uniquePaths(m int, n int) int {
    dp:=make([][]int,m)
	for i:=0;i<m;i++{
		dp[i] = make([]int,n)
		for j:=0;j<n;j++{
			if i==0||j==0 {
				dp[i][j] = 1
			}else{
				dp[i][j]=dp[i-1][j]+dp[i][j-1]
			}
		}
	}
	return dp[m-1][n-1]
}
```