### 解题思路
此处撰写解题思路

### 代码

```golang
func coinChange(coins []int, amount int) int {
    memo := make([]int, amount + 1)
    // 对数组赋初始值
    for i := 0; i<len(memo); i++ {
        memo[i] = -2
    }
    return recursion(coins, amount, memo)
}

func recursion(coins []int, amount int, memo []int) int {
    if amount == 0 {
        return 0
    }
    if memo[amount] != -2 {
        return memo[amount]
    }
    const INT_MAX = int(^uint(0) >> 1)
    ant := INT_MAX
    for _, v := range coins {
        // 硬币金额大于总金额，没有解
        if amount < v {
            continue 
        }
        // 继续转为子问题
        subCoins := recursion(coins, amount - v, memo)
        if subCoins == -1 {
            // 无解
            continue
        }
        ant = int(math.Min(float64(ant), float64(subCoins + 1)))
    }
    if ant == INT_MAX {
        // 没有找到解
        memo[amount] = -1
        return memo[amount]
    } else {
        memo[amount] = ant
        return memo[amount]
    }
}
```