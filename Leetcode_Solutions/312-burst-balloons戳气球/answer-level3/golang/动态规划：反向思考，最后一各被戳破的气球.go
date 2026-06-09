- 动态规划：反向思考，最后一各被戳破的气球
- 首先在数组前后各加一个元素1
- 定义dp[i][j]为数组nums[i:j+1]戳气球能得到的最大硬币数，且不能戳第i个和第j个气球
- 表达式 dp[i][j] = max(dp[i][k]+dp[k][i] + nums[k]*nums[i]*nums[j]), i<k<j
- 初始值：dp[i][i] = 0, dp[i-1][i] = 0, dp[i-2][i] = nums[i-2]*nums[i-1]*nums[i]
```
func maxCoins(nums []int) int {
	if nums == nil || len(nums) == 0 {
		return 0
	}
	nums = append([]int{1}, nums...)
	nums = append(nums, 1)
	n := len(nums)
	dp := make([][]int, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]int, n)
	}
	for i:=0;i<n;i++ {
		dp[i][i] = 0
		if i > 0 {
			dp[i-1][i] = 0
		}
		if i > 1 {
			dp[i-2][i] = nums[i-2] * nums[i-1] * nums[i]
		}
	}

	for i:=3;i<n;i++ {
		for j:=i-3;j>=0;j-- {
			for k:=j+1;k<i;k++ {
				dp[j][i] = max(dp[j][i],dp[j][k] + dp[k][i] + nums[k] * nums[i] * nums[j])
			}
		}
	}
	return dp[0][n-1]
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}
```
