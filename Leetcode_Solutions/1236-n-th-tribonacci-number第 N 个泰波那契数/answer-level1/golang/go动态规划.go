### 解题思路
这道题其实是斐波那契数列的变种题

区别在于，斐波那契数列是两个表达式相加得到新的表达式
```
f[0] = 0
f[1] = 1
f[i] = f[i - 1] + f[i - 2]
```
这道题是三个表达式相加，相应的初始化值也要多一个
```
    dp[0] = 0
    dp[1] = 1
    dp[2] = 1
	dp[3] = 2
```
使用动态规划。dp[i]表示第i个泰波那锲数

动态方程：
```
dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] 
```
### 代码

```golang
func tribonacci(n int) int {
	if n == 0{
		return 0
	}
	if n == 1 || n == 2{
		return 1
	}
	dp := make([]int,n+1)
    dp[0] = 0
    dp[1] = 1
    dp[2] = 1
	dp[3] = 2
	for i := 4;i <= n;i++{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] 
	}
	return dp[n]
}
```