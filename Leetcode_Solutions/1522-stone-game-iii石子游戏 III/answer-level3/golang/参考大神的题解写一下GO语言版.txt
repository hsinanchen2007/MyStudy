
`dp[i] = sum(i...n) - min(dp[i+1],dp[i+2],dp[i+3])` //dp[i]表示剩余i到n石子时，i位置先手者最佳策略的最终得分值

```
    func stoneGameIII(stoneValue []int) string {
        dp := make([]int, len(stoneValue) + 2) // 为了最后全拿的时候不再多作判断，多分配2个空间
        n := len(stoneValue) - 1
        dp[n] = stoneValue[n]
        sum := stoneValue[n]
        for i := n - 1; i >= 0; i-- {
            sum += stoneValue[i]
            minDP := dp[i+1]
            if dp[i+2] < minDP {
                minDP = dp[i+2]
            }
            if dp[i+3] < minDP {
                minDP = dp[i+3]
            }
            dp[i] = sum - minDP
        }
        if dp[0] == sum - dp[0] {
            return "Tie"
        } else if dp[0] > sum - dp[0] {
            return "Alice"
        }
        return "Bob"
    }
```
