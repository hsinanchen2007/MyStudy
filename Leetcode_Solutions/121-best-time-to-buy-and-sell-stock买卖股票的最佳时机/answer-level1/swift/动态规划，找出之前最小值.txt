### 解题思路
动态规划
1. 设置为i，找出i前部分的最小值，并算出差值做比较
2. 若大于之前值，则保留
时间复杂度O(n)

### 代码

```swift
class Solution {
    func maxProfit(_ prices: [Int]) -> Int {
        if prices.count == 0 {
            return 0
        }
        var i = 1
        var maxPrice = 0
        var lessIndex = 0
        
        while i < prices.count {
            if prices[i] < prices[lessIndex] {
                lessIndex = i
            } else {
                let priceTemp = prices[i] - prices[lessIndex]
                if priceTemp > maxPrice {
                    maxPrice = priceTemp
                }
            }
            i += 1
        }
        return maxPrice
    }
}
```