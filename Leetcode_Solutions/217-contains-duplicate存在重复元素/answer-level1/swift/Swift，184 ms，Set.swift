```swift
class Solution {
    func containsDuplicate(_ nums: [Int]) -> Bool {
        return Set<Int>(nums).count != nums.count
    }
}
```