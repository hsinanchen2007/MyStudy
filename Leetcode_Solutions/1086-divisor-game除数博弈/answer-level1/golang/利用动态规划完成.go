### 解题思路
用动态规划会快一些，还可以用递归

### 代码

```golang
func divisorGame(N int) bool  {
	if N == 0{
		return true
	}
	dp := make([]bool,N+2)
	dp[0] = true
	dp[2] = true
	for i:=3;i<=N;i++{
		for j:=1;j<i;j++{
			if dp[i-j] == false && (i%j==0){
				dp[i] = true
				break
			}
		}
	}
	return dp[N]
}
```