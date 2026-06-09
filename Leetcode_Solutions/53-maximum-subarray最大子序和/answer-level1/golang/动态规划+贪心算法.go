### 解题思路
此处撰写解题思路

### 代码
##### 动态规划
```golang
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func maxSubArray(nums []int) int {
	dp := make([]int, len(nums))
	if len(nums) == 0 {
		return 0
	}

	dp[0] = nums[0]
	res := dp[0]
	for i := 1; i < len(nums); i++ {
		dp[i] = max(nums[i], nums[i]+dp[i-1])
		res = max(res, dp[i])
	}
	return res
}

```

##### 贪心算法
```golang
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func maxSubArray(nums []int) int {
	res := math.MinInt32
	sum := 0
	for i := 0; i < len(nums); i++ {
		sum += nums[i]
		res = max(sum, res)
		if sum < 0 {
			sum = 0
		}
	}
	return res
}

```