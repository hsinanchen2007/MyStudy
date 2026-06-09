![image.png](https://pic.leetcode-cn.com/f305f8e7d9ae705eebfca20267f76788a66c5fc7042678828ce8cbcdf48e2692-image.png)

dp[i]表示第i位必选情况下的最大值，则`dp[i] = max(dp[i-2], dp[i-3]) + nums[i]`，含义为要么上一位服务的人为往前第二个，要么服务的人往前第三个，i最多只跟i-3的位置有关，所以不需要用数组，直接用变量存一下就好了。


```go
    func massage(nums []int) int {
        prev1 := 0
        prev2 := 0
        prev3 := 0
        max := 0
        for i:=0; i<len(nums); i++ {
            tmp := 0
            if prev2 > prev3 {
                tmp = prev2 + nums[i]
            } else {
                tmp = prev3 + nums[i]
            }
            if tmp > max {
                max = tmp
            }
            prev3 = prev2
            prev2 = prev1
            prev1 = tmp
        }
        return max
    }
```
