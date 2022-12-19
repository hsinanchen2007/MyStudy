```swift
class Solution {
    func findLengthOfLCIS(_ nums: [Int]) -> Int {
        let numsCount = nums.count
        if numsCount <= 1 { return numsCount }
        var ans = 1
        var i = 0
        while i < numsCount - 1 {
            let left = nums[i]
            var last = left
            var count = 1
            for j in (i + 1)..<numsCount {
                let right = nums[j]
                if right <= last {
                    i = j
                    break
                }
                last = right
                count += 1
                if j == numsCount - 1 {
                    return max(count, ans)
                }
            }
            ans = max(ans, count)
        }
        return ans
    }
}
```