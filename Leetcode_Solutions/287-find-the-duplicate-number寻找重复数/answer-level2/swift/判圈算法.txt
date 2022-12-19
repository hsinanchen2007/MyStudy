```
class Solution {
    func findDuplicate(_ nums: [Int]) -> Int {
        var tor = nums[0]
        var har = nums[nums[0]]
        // 求相遇的点
        while har != tor {
            tor = nums[tor]
            har = nums[nums[har]]
        }
        
        tor = 0
        while tor != har {
            tor = nums[tor]
            har = nums[har]
        }
        return tor
    }
}
```