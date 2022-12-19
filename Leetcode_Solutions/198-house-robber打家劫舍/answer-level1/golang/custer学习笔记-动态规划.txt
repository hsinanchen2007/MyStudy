学习自[@guanpengchn](/u/guanpengchn)

# 思考-动态规划
动态规划方程: `dp[n] = MAX( dp[n-1], dp[n-2] + num)`  

- 由于不可以在相邻的房屋闯入，所以在当前位置n房屋可盗窃的最大值，
- 要么就是 `n-1` 房屋可盗窃的最大值，要么就是 `n-2` 房屋可盗窃的最大值加上当前房屋的值，
- 二者之间的最大值

举例：

- 1号房间可盗窃最大值为3，即 `dp[1] = 3` ，2号房间可盗窃最大值为4，即 `dp[2] = 4` ，
- 3号房间自身的值为2，即 `num = 2` ，
- 那么 `dp[3] = MAX( dp[2], dp[1] + num) = MAX(4, 3+2) = 5` ，
- 3号房间可盗窃最大值为5。

时间复杂度：O(n)，n为数组长度

```go
func rob(nums []int) int {
	l := len(nums)
	if l == 0 {
		return 0
	}
	dp := make([]int, l+1)
	dp[1] = nums[0]
	for i := 2; i <= l; i++ {
		dp[i] = max(dp[i-1], dp[i-2]+nums[i-1])
	}
	return dp[l]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
```
