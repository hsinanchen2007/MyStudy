假设最小组合中最后一枚硬币是c：
1. c 可能是 coins 中任何一个；
2. 去除 c 后剩下的部分，一定也是当前总额的一个最小组合（否则加上c不可能构成最小组合）

或者用以下思路：
如果 `dp[i]` 表示组成金额i的最小组合，`dp[i]+1` 一定是组成金额 `i+c` 的最小组合。

```go
func coinChange(coins []int, amount int) int {
        dp := make([]int, amount + 1)
        for i := 1; i <= amount; i++ {
                dp[i] = -1
                for _, c := range coins {
                        if i < c || dp[i-c] == -1 {
                                continue
                        }
                        
                        count := dp[i-c] + 1
                        if dp[i] == -1 || dp[i] > count {
                                dp[i] = count
                        }
                }
        }
        
        return dp[amount]
}
```
