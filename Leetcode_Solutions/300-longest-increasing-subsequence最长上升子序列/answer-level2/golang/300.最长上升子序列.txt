### 解题思路

动态规划
状态转移方程：dp[i]=max(dp[j])+1,其中0≤j<i且num[j]<num[i]
维护dp表即可，dp[i]表示以第i个元素结尾的最长子序列长度。

### 代码

```golang
func lengthOfLIS(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	dp := make([]int,len(nums))
	dp[0] = 1
	res := 1
	for i := 0;i < len(nums);i++ {
		maxVal := 0
		for j := 0;j < i;j++ {
			if nums[j] < nums[i] {
				maxVal = max(maxVal,dp[j])
			}
		}
		dp[i] = maxVal + 1
		res = max(res,dp[i])
	}
	return res
}
func max(a int,b int) int {
	if a > b {
		return a
	}else {
		return b
	}
}
```