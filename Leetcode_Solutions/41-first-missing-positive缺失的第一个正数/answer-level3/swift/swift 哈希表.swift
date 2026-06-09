```
class Solution {
    func firstMissingPositive(_ nums: [Int]) -> Int {
        guard nums.count > 0 else {
            return 1
        }
        var dic = [Int: Int]()
        for i in 0..<nums.count {
            dic[nums[i]] = 1
        }
        for i in 1...nums.count {
            if dic[i] == nil {
                return i
            }
        }
        return nums.count + 1
    }
}
```