```
class Solution {
    func findPeakElement(_ nums: [Int]) -> Int {
        if nums.count == 1 {
            return 0
        }
        var result = 0
        for i in 0...nums.count-1 {
            if i == 0 {
                let second = nums[i]
                let third = nums[i+1]
                if second > third {
                    result = i
                    break
                }
            } else if i == nums.count-1 {
                let first = nums[i-1]
                let second = nums[i]
                if second > first {
                    result = i
                    break
                }
            } else {
                let first = nums[i-1]
                let second = nums[i]
                let third = nums[i+1]
                if second > first && second > third {
                    result = i
                    break
                }
            }
        }
        return result

    }
}
```
