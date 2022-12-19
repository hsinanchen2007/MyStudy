### 解题思路
此处撰写解题思路

### 代码

```golang
func massage(nums []int) int {
    if len(nums) == 0 {
        return 0
    }
    if len(nums) == 1 {
        return nums[0]
    }
    var (
        dp = make([]int,len(nums))
    )
    dp[0] = nums[0]
    dp[1] = getMax(dp[0],nums[1])
    for i := 2; i < len(nums); i ++ {
        dp[i] = getMax(dp[i-1],dp[i-2]+nums[i])
    }
    return dp[len(nums)-1]
}

func getMax(i,j int) int {
    if i < j {
        return j
    }
    return i
}
```