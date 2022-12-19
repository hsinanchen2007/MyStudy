### 解题思路
// 1、原问题 与 子问题

// 2、确认状态

// 3、确认边界状态值

// 4、动态转移方程

//dp[i] = max(dp[i-1] , dp[i-2]+nums[i])

同样的问题

### 代码

```golang
func rob(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	if len(nums) == 1 {
		return nums[0]
	}
	var dp = make([]int, len(nums))
	dp[0] = nums[0]
	dp[1] = int(math.Max(float64(nums[0]), float64(nums[1])))
	for i := 2; i < len(nums); i++ {
		dp[i] = int(math.Max(float64(dp[i-1]), float64(dp[i-2]+nums[i])))
	}
	return dp[len(nums)-1]
}
```