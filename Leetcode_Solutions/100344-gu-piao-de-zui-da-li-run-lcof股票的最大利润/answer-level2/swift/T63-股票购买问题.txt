### 解题思路
假设该点是最低买进的，然后计算max值。

### 代码

```swift
class Solution {
    func maxProfit(_ prices: [Int]) -> Int {
        if prices.count == 0 {
            return 0
        }
        
        // 假设最低买进的
        var min = prices[0]
        var max = 0 

        for num in prices {
            if num < min {
                min = num
            }
            max = max < num - min ? num - min : max
        } 

        return max
    }
}
```