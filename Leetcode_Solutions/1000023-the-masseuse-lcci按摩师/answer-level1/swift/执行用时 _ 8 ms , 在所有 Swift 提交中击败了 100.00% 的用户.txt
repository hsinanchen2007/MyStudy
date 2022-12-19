### 解题思路
跟窃贼那题一样的。逻辑

### 代码

```swift
class Solution {
    func massage(_ nums: [Int]) -> Int {
        
        if nums.count == 0 {
            return 0
        }
        
        if nums.count == 1 {
            return nums[0]
        }
        
        if nums.count == 2 {
            return max(nums[0], nums[1])
        }
        
        if nums.count == 3 {
            return max(nums[0] + nums[2], nums[1])
        }
        
        var array = Array.init(repeating: 0, count: nums.count)
        
        array[0] = nums[0]
        array[1] = nums[1]
        array[2] = nums[2] + nums[0]
        
        for i in 3 ..< nums.count {
            
            array[i] = max(array[i-2] + nums[i], array[i-3] + nums[i])
            
        }
        
        return max(array[nums.count - 1], array[nums.count - 2])
        
    }
}
```