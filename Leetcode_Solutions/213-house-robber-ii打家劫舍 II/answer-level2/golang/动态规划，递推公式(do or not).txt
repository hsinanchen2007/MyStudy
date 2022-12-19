首尾不能同时存在，这个思维啊
![image.png](https://pic.leetcode-cn.com/f96972a5529576546af6fb3fdd69d46fdf683a2d728e5d681e66c0a760ad82e3-image.png)

```
// 首尾成环，第一个和最后一个不能同时抢
func rob(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	if len(nums) == 1 {
		return nums[0]
	}
	return getMax(robLine(nums[:len(nums)-1]), robLine(nums[1:]))
}

// 定义状态：dp[n]表示前n个房间能rob的最大值
// 如果第n个房间被抢(价值为nums[n-1])，那么第n-1个房间就不能抢，最大价值为dp[n-2]+nums[n-1]
// 如果第n个房间不被抢，那么最大价值为dp[n-1]
// 则最大价值为: max(dp[n-2]+nums[n-1], dp[n-1])
func robLine(nums []int) int {
	dp := make([]int, len(nums)+1)
	dp[0] = 0
	dp[1] = nums[0]

	for i := 2; i <= len(nums); i++ {
		dp[i] = getMax(dp[i-1], nums[i-1]+dp[i-2])
	}
	return dp[len(nums)]
}

func getMax(a, b int) int {
	if a >= b {
		return a
	}
	return b
}

```
