提供一个简单的解决思路
```
func maxProfit(_ prices: [Int]) -> Int {
    var maxPrice = 0
    if prices.count < 2 {
        return maxPrice
    }
    if prices.count == 2 {
        return (prices[1] > prices[0] ? (prices[1] - prices[0]) : 0)
    }
    for i in 1..<prices.count {
        for j in i..<prices.count {
            if prices[j] > prices[i-1] {
                if maxPrice < prices[j] - prices[i-1] {
                    maxPrice = prices[j] - prices[i-1]
                }
            }
            else {
                break
            }
        }
    }
    
    return maxPrice
}
```
