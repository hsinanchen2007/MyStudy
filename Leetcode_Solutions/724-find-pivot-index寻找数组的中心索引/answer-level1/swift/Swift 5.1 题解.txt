### 解题思路
数组从左到右依次遍历做为中心索引，注意左右两侧不能在每次遍历反复求和，只进行一个数的增减。

### 代码

```swift
class Solution {
    func pivotIndex(_ nums: [Int]) -> Int {
        let length = nums.count
        guard length > 1 else { return -1 }
        var middle = 0
        // Start form the left
        var sumLeft = 0
        var sumRight = nums.suffix(length - 1).reduce(0, +)
        while sumLeft != sumRight {
            // Refresh sum of left
            sumLeft += nums[middle]
            middle += 1 
            guard middle < length else { return -1 }
            // Refresh sum of right
            sumRight -= nums[middle]
        }
        return middle
    }
}
```