### 解题思路
此处撰写解题思路
动态规划

### 代码

```golang

// dp[i]: 表示nums数组以i为结尾的sum最大的值

// dp[i] = max{dp[i-1] + nums[i], nums[i]}
func maxSubArray(nums []int) int {
    var dp []int = make([]int, len(nums))
    dp[0] = nums[0]
    var max = dp[0]
    for i := 1; i < len(nums); i++ {
        if dp[i - 1] + nums[i] > nums[i] {
            dp[i] = dp[i - 1] + nums[i]
        } else {
            dp[i] = nums[i]
        }
        if dp[i] > max {
            max = dp[i]
        }
    }
    return max
}
```