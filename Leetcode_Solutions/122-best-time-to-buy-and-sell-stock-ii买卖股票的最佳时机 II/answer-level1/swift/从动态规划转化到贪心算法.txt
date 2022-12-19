### 解题思路
这道题一开始我们可以用动态规划的思想想这道题，假如我们考虑第N天卖掉股票，只是考虑，但手里不一定有，那么动态转移方程就应该是 f(n) = max(prices[n] - prices[n - 1] + f(n - 1), f(n - 1)),意思就是说如果我第N天卖掉的话，那么我需要计算第N天的收益+昨天最大的收益，与第N天手里没有股票取最大值，那么代码如下：

### 代码

```swift
class Solution {
    func maxProfit(_ prices: [Int]) -> Int {
         guard prices.count > 0 else {return 0}
        guard prices.count > 1 else {return 0}
        var dp = [Int](repeating: 0, count: prices.count)
        for i in 1 ..< prices.count {
            dp[i] = max(prices[i] - prices[i - 1] + dp[i - 1], dp[i - 1])
        }
        return dp[prices.count - 1]
    }
}
```
### 解题思路
但是我们观察这个转移方程，只要保证prices[n] - prices[n - 1] > 0 就是f(N)最大的收益。代码变为：
### 代码

```swift
class Solution {
    func maxProfit(_ prices: [Int]) -> Int {
        guard prices.count > 0 else {return 0}
        guard prices.count > 1 else {return 0}
        var preProfit = 0
        var maxP = 0
        for i in 1 ..< prices.count {
            maxP = max(prices[i] - prices[i - 1] + preProfit, preProfit)
            preProfit = maxP
        }
        return maxP
    }
}
```

### 解题思路
继续优化
### 代码

```swift
class Solution {
    func maxProfit(_ prices: [Int]) -> Int {
        guard prices.count > 0 else {return 0}
        guard prices.count > 1 else {return 0}
        var maxP = 0
        for i in 1 ..< prices.count {
            var todayP = prices[i] - prices[i - 1]
            if todayP > 0 {
                maxP +=  todayP
            }
        }
        return maxP
    }
}
```
### 解题思路
这样就变成了贪心算法，哈哈哈哈😀
### 