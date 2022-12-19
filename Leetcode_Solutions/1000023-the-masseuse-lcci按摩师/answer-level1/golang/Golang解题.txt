### 解题思路
此处撰写解题思路

### 代码

```golang
func massage(nums []int) int {
    length := len(nums)
	if length == 0 {
		return 0
	}
	dp0 := 0
	dp1 := nums[0]

	for i := 1; i < length; i++ {
		tdp0 := int(math.Max(float64(dp0), float64(dp1))) // 计算 dp[i][0]
		tdp1 := dp0 + nums[i] // 计算 dp[i][1]

		dp0 = tdp0 // 用 dp[i][0] 更新 dp_0
		dp1 = tdp1 // 用 dp[i][1] 更新 dp_1
	}
	return int(math.Max(float64(dp0), float64(dp1)))
}
```