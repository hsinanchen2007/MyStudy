```swift
class Solution {
    func rob(_ nums: [Int]) -> Int {
        if nums.isEmpty {
            return 0
        }
        if nums.count <= 1 {
            return nums[0]
        }
        let numsCount = nums.count
        var neg2 = nums[0]
        var neg1 = max(nums[0], nums[1])
        for i in 2..<numsCount {
            let temp = neg2
            neg2 = neg1
            neg1 = max(neg1, temp + nums[i])
        }
        return neg1
    }
}
```