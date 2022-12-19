### 解题思路

想法比较简单，虽然效率不是太高

### 代码

```swift
class Solution {
    func maxProfit(_ prices: [Int]) -> Int {
        let c = prices.count
        if c < 2 {
            return 0
        }
        var buy:Int = prices[0]
        var income:Int = 0
        for i in 1..<c {
            let t = prices[i]
            if t > buy {
                let new = t - buy
                if new > income {
                    income = new
                }
            }
            if t < buy {
                buy = t
            }
        }
        return income;
    }
}
```