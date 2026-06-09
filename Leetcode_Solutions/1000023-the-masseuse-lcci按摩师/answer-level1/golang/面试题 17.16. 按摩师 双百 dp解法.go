额，话不多说直接上dp。
![image.png](https://pic.leetcode-cn.com/63d9089fbaea6a7b5734704eadd48faa28ad4e682e6eafb9e89a94667fa2c45c-image.png)

```
func GetMax(val1 int, val2 int) int {
    if val1 > val2 {
        return val1
    }
    return val2
}
func massage(nums []int) int {
    size := len(nums)
    if size == 0 {
        return 0
    }
    if size == 1 {
        return nums[0]
    }
    if size == 2 {
        return GetMax(nums[0], nums[1])
    }
    // dp[i]表示当前最大值，dp[i] = max(dp[i-1], dp[i-2])
    dp := make([]int, size)
    // 初始底
    dp[0] = nums[0]
    dp[1] = GetMax(nums[0], nums[1])
    for i := 2; i < size; i++ {
        dp[i] = GetMax(dp[i-1], dp[i-2] + nums[i])
    }

    return dp[size - 1]
}
```
