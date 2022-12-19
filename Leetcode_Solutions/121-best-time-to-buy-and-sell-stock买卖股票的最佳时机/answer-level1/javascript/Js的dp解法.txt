// dp[i]记录以价格prices[i]卖出所能得到的最大利润
// 状态转移：dp[i] = max(dp[i-1], prices[i]-minPrice)
var maxProfit = function(prices) {
    var dp = []
    dp[0] = 0
    var minPrice = prices[0]
    for (var i=1; i<prices.length; i++) {
        dp[i] = Math.max(dp[i-1], prices[i] - minPrice)
        if (prices[i] < minPrice) minPrice = prices[i]
    }
    console.log(dp)
    return dp.pop()
}