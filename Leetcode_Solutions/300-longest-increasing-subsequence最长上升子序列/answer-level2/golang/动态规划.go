### 解题思路
dp数组中的dp[i]表示以nums[i]结尾的最长升序子序列。
dp[i] = max[dp[0], dp[1], dp[2]...dp[i]) + 1
结果即为计算dp数组过程中出现的最大dp值。
### 代码

```golang
func lengthOfLIS(nums []int) int {
    if len(nums) == 0 {
        return 0
    }
    dp := make([]int, len(nums))
    res := dp[0]
    for i := 0; i < len(nums); i++ {
        last := 0
        for j := 0; j < i; j++ {
            if last < dp[j] && nums[j] < nums[i] {
                last = dp[j]
            }
        }
        dp[i] = last + 1
        if dp[i] > res {
            res = dp[i]
        }
    }
    return res
}
```