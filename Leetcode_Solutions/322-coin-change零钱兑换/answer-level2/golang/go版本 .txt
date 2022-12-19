```
/*
322. 零钱兑换
输入: coins = [1, 2, 5], amount = 11
输出: 3 \解释: 11 = 5 + 5 + 1
解题思路：
1、构建dp，dp[0]=0, dp[1~amount]= math.MaxInt32
2、1~amount每一个面额去获取可以兑换的最小零钱方案
3、dp[i] = min(dp[i], dp[i-coins[j]]+1)

*/
func coinChange(coins []int, amount int) int {
    dp := make([]int, amount+1) // 注意长度是钱币的总数
    for i:=0 ;i< amount+1; i++ {
        dp[i] = amount + 1 // 加1的原因是求最小值，也可以 初始赋值dp[i]= math.MaxInt32
    }
    dp[0] = 0
    for i:=1; i< amount+1; i++ {// 每个面额的钱,都用零钱去试探
        for j:=0; j< len(coins); j++ {
            if i>= coins[j] {
                // 例如dp[11] = min(dp[11], dp[10]+1, dp[9]+1, dp[6]+1)
                // 利用内层循环实现上面多个值的求min
                dp[i] = min(dp[i], dp[i-coins[j]]+1) 
            }
        }
    }
    if dp[amount] == amount +1 {
        return -1
    } 
    return dp[amount]   
}


func min(a, b int) int{
    if a > b{
        return b
    }
    return a
}
```
