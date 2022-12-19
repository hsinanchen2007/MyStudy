### 解题思路
dp就dp，非要卡个空数组。。

### 代码

```golang
func massage(nums []int) int {
    if len(nums) == 0 {
        return 0
    }
	dp := make([]int, len(nums))
	for i := range nums {
		switch i {
		case 0:
			dp[i] = nums[i]
		case 1:
			dp[i] = max(nums[0], nums[1])
		default:
			dp[i] = max(dp[i-1], dp[i-2]+nums[i])
		}
	}
	return dp[len(dp)-1]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

```