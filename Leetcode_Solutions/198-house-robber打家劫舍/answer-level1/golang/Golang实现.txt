典型动态规划类问题
```
func rob(nums []int) int {
    lenNums := len(nums)
    if lenNums == 0{
        return  0
    }
    if lenNums == 1{
        return nums[0]
    }
    dp := make([]int, lenNums+1)
    dp[1] = nums[0]
    for i := 2; i <= lenNums; i++{
        dp[i] = max(dp[i-1],dp[i-2]+nums[i-1])
    }
    return dp[lenNums]
}
func max(a, b int)int{
    if a>= b{
        return a
    }
    return b
}
```

![image.png](https://pic.leetcode-cn.com/a5429ecf90bf50302447d936889861fad81fd6c4a59f20f6bafad2c01d8bf91f-image.png)