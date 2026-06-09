

```swift
class Solution {
    func rob(_ nums: [Int]) -> Int {
        if nums.count == 0 {
            return 0
        }else if nums.count == 1 {
            return nums[0]
        }
        let r1 = Array(nums[1...nums.count - 1])
        let r2 = Array(nums[0...nums.count - 2])
        
        return max(myRob(r1), myRob(r2))
    }
    
    func myRob(_ nums: [Int]) -> Int {
        var prevMax = 0
        var currMax = 0
        for v in nums {
            let tmp = currMax
            currMax = max(prevMax + v, currMax)
            prevMax = tmp
        }
        return currMax
    }
}
```