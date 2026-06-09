### 解题思路

状态定义：首先考虑只有nums[0],nums[1],nums[2]三个下标时，又因为时间都是正数，所以最长时间为max(nums[1],nums[0]+nums[2])，dp[n-1]就是前一天的最长预约时间与前二天的最长预约时+当天预约时间较大者
dp公式：dp[i] = max(dp[i-1],dp[i-2] + nums[i])


### 代码

```golang
func massage(nums []int) int {
    l := len(nums)
    if l == 0 {
        return 0
    }
    if l < 2 {
        return nums[0]
    }
    m := 3
    dp := make([]int,m)
    dp[0] = nums[0]
    dp[1] = max(nums[0],nums[1])    
    for i := 2; i < l; i++ {
        //状态压缩        
        n1,n2,n3 := i % m,(i-1) % m,(i - 2)%m
        dp[n1] = max(dp[n2],dp[n3] + nums[i])
    }
    return dp[(l-1)%m]
}

func max(x,y int) int {
    if x > y {
        return x
    }
    return y
}
```