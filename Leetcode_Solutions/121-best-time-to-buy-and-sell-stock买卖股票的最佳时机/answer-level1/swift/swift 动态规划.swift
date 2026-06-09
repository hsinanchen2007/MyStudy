### 解题思路
找最大差值,且最小值排在最大值前面
profit = prices[j] - prices[i] , i<j
也就是 profit = prices[j] - min(prices[...j])

dp[i] 为今天的获利
dp[i] = max(dp[i-1],prices[i]-minPrice) 
今天的获利是 昨天的获利 与 今天卖出获利 的最大值

### 代码

```swift
class Solution {
    func maxProfit(_ prices: [Int]) -> Int {
        
        guard !prices.isEmpty else {
            return 0
        }
        
        var minPrice = prices.first!
        var dp = [Int](repeating: 0, count: prices.count)
        for i in 1..<prices.count {
            dp[i] = max(dp[i-1], prices[i] - minPrice)
            
            minPrice = min(minPrice, prices[i])
        }
        
        
        return dp.last!
    }
}
```