### 解题思路
跳台阶的dp思路

### 代码

```golang
func coinChange(coins []int, amount int) int {
    if len(coins) == 0 {
        return -1
    }
    var (
        dp = make([]int,amount+1)
    )
    dp[0] = 0
    for i := 1; i < amount+1; i ++ {
        min := math.MaxInt32
        for _,val := range coins {
            if i - val >= 0 && dp[i-val] >= 0 && dp[i-val] < min{
                min = dp[i-val]
            }
        }
        if min == math.MaxInt32 {
            dp[i] = -1
        }else {
            dp[i] = min+1
        }
    }
    return dp[amount]
}
```