### 解题思路
此处撰写解题思路

### 代码

```swift
class Solution {
    func findRepeatNumber(_ nums: [Int]) -> Int {
        var set: Set<Int> = []
        for (_, value) in nums.enumerated() {
            let (result, value) = set.insert(value)
            if !result {
                return value
            }
        }
        
        assert(false, "no repeat numbers")
    }
}
```