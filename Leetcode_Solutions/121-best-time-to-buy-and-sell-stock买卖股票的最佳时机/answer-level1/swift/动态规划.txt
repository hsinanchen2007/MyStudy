### 解题思路
此处撰写解题思路

### 代码

```swift
class Solution {
    func maxProfit(_ prices: [Int]) -> Int {
        if prices.count < 2 {
            return 0
        }
        
        var minPrice = prices.first!
        var newPrices = [Int](repeating: 0, count: prices.count)
        for i in 1..<prices.count {
            newPrices[i] = max(newPrices[i-1], prices[i] - minPrice)
            
            minPrice = min(minPrice, prices[i])
        }
        return newPrices.last!
    }
}
```