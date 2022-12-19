### 解题思路
说实话我到现在还没看懂题...

### 代码

```swift
class Solution {
    func minCostToMoveChips(_ chips: [Int]) -> Int {
        
        //原数组奇数多就返回偶数个数，反之则返回奇数个数
        let odd = chips.filter{ $0 % 2 == 0 }.count
        let even = chips.count - odd
        
        return min(odd,even)
    }
}
```