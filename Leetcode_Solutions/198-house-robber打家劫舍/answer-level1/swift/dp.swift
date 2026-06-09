
```swift
class Solution {
    func rob(_ nums: [Int]) -> Int {
        var prev = 0
        var curr = 0
        for i in nums {
            let tmp = curr
            curr = max(prev + i, curr)
            prev = tmp
        }
        return curr
    }
}
```