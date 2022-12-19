### 解题思路
1、dp[i] 标识在i位置的最大时间 ， 动态转移方程：dp[i] = max(这一次选择的话 dp[i-2]+num[i],这一次不选择的话dp[i-1])

### 代码

```golang
func massage(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	if len(nums) == 1 {
		return nums[0]
	}
	var dp = make([]int, len(nums))
	dp[0] = nums[0]
	if nums[0] > nums[1] {
		dp[1] = nums[0]
	} else {
		dp[1] = nums[1]
	}
	for i := 2; i < len(nums); i++ {
		//这一次选择的话 dp[i-2]+num[i]
		//这一次不选择的话dp[i-1]
		if dp[i-2]+nums[i] > dp[i-1] {
			dp[i] = dp[i-2] + nums[i]
		} else {
			dp[i] = dp[i-1]
		}
	}
	return dp[len(nums)-1]
}
```
![image.png](https://pic.leetcode-cn.com/89344d6ef06cdbc3829e7cd6a82fe6cbf85f96a41f741f1f65ca0970989ef379-image.png)
