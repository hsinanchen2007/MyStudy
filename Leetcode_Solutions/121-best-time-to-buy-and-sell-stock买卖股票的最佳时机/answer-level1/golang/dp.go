func maxProfit(prices []int) int {
   // 每天有两种状态 持有股票或者没有持有股票
   // 持有股票，两种选择，1）之前持有 2）当天买入
   // 没有持有股票，两种选择，1） 之前没有持有 2）当天卖出
   // 最后没有持有时，利润最大
   n := len(prices)
   dp := make([][]int, 0, n+1)
   for i := 0; i <= n; i++ {
       dp = append(dp, make([]int, 2))
   }
   // 第0天没有持有利润为0，持有不可能，利润为-inf
   dp[0][0] = 0
   dp[0][1] = math.MinInt32
   for i := 1; i <= n; i++ {
       dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i-1])
       dp[i][1] = max(dp[i-1][1], 0 - prices[i-1]) // 按道理 应该时 dp[i-1][0] - prices[i-1]，由于只能交易一次，所以前面没有持有时的利润都是0
   }
   return dp[n][0]
}