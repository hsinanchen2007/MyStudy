```
func rob(nums []int) int {
	var (
		i      int
		length = len(nums)
		dp     = make([]int, length)
	)
	switch len(nums) {
	case 0:
		return 0
	case 1:
		return nums[0]
	case 2:
		return max(nums[0], nums[1])
	}

	dp[length-1] = nums[length-1]
	dp[length-2] = max(nums[length-1], nums[length-2])
	for i = length - 3; i >= 0; i-- {
		dp[i] = max(dp[i+2]+nums[i], dp[i+1])
	}
	return dp[0]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
```
