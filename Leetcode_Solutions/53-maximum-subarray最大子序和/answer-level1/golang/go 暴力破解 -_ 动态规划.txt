go 
1. 暴力破解
2. 动态规划

``` golang
func maxSubArray(nums []int) int {
    return method1(nums)
    return method2(nums)
}

//dp原理：dp[i] = max(dp[i-1] + nums[i], nums[i])

//方法一，暴力法
func method1(nums []int) int {
    temp, max := 0, nums[0]

    for i := 0; i < len(nums); i++ {
        temp = getMax(temp + nums[i], nums[i])
        if temp > max {
            max = temp
        }
    }

    return max
}

//方法2 dp
func method2(nums []int) int {
    var dp = map[int]int{}
    dp[0] = nums[0]
    max := nums[0]
    for i := 1; i < len(nums); i++ {
        dp[i] = getMax(dp[i - 1] + nums[i], nums[i])
        max = getMax(dp[i], max)
    }
    return max
}

func getMax(a, b int) int {
    if a > b {
        return a
    } else {
        return b
    }
}
```
