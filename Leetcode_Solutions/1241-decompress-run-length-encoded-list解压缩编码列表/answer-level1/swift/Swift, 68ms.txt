```swift
class Solution {
    func decompressRLElist(_ nums: [Int]) -> [Int] {
        let count = nums.count
        var ans: [Int] = []
        for index in 0..<(count / 2) {
            ans += [Int](repeating: nums[2 * index + 1], count: nums[2 * index])
        }
        return ans
    }
}
```