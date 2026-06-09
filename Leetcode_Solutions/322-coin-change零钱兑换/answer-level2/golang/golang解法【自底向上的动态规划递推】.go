```go
// 典型的动态规划问题，采用自底向上的递推公式
// 递推公式
// opt[amount] = min(opt[amount], 1+opt[amount-coin])
// base case
// amount = 0, opt[amount] = 0
// amount in coins, opt[amount] = 1
// 时间复杂度O(MN), M为总金额, N为硬币种类个数
// 空间复杂度O(M)

func coinChange(coins []int, amount int) int {
    opt := make([]int, amount+1)
    for i := 0; i <= amount; i++ { opt[i] = amount+1 }
    opt[0] = 0
    for i := 0; i < amount+1; i++ {
        for _, coin := range coins {
            if i < coin { continue }
            opt[i] = min(opt[i], 1+opt[i-coin])
        }
    }
    if opt[amount] == amount+1 { return -1 }
    return opt[amount]
}

func min(x, y int) int {
    if x < y { return x }
    return y
}
```