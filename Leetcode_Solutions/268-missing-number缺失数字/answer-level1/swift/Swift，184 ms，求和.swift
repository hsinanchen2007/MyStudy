```swift
class Solution {
    func missingNumber(_ nums: [Int]) -> Int {
        let sumShould = (nums.count + 1) * (0 + nums.count) / 2
        let sumNow = nums.reduce(0, +)
        return sumShould - sumNow
    }
}
```