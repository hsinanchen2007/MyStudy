### 解题思路
> 求最大公约数
- 先找出每张牌的个数
- 对牌的个数求最大公约数，只要最大公约数为`1`则`false`

### 代码

```swift
class Solution {
    func hasGroupsSizeX(_ deck: [Int]) -> Bool {
        
        let count = deck.count
        if count < 2 {
            return false
        }
        var items = [Int: Int]()
        for i in deck {
            if let num = items[i] {
                items[i]! = num + 1 
            } else {
                items[i] = 1
            }
        }
        var arr = [Int]()
        for num in items.values {
            arr.append(num)
        }
        var temp = arr.first!
        for i in 1..<arr.count {
            if gcd(temp, arr[i]) == 1 {
                return false
            }
        }
        return true
    }

    func gcd(_ x: Int, _ y: Int) -> Int {
        return x % y == 0 ? y : gcd(y, x % y)
    }
}
```