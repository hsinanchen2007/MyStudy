```swift
class Solution {
    func findNumbers(_ nums: [Int]) -> Int {
        var ans: Int = 0
        for num in nums where "\(num)".count % 2 == 0 {
            ans += 1
        }
        return ans
    }
}
```