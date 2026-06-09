### 动态规划
![WechatIMG553.jpeg](https://pic.leetcode-cn.com/440e80f256507200667c6dc1c01057e41f873ac4edc509797689a2003c2bc5ee-WechatIMG553.jpeg)



### 代码

```swift
class Solution {
    func maxProfit(_ prices: [Int]) -> Int {
        
        if prices.count == 0 {
            return 0
        }
        var hold = Int.min
        var rest = 0
        var sale = 0
        for p in prices {
            let pre_sale = sale
            sale = hold + p
            hold = max(hold, rest - p)
            rest = max(pre_sale, rest)
        }
        return max(rest, sale)
    }
}
```