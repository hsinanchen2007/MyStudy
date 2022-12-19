### 解题思路
首先将数组进行排序；
排序完成后从左到右找到第一个原数组与排序数组不一致的位置，记为l；
从右到左找到第一个原数组与排序数组不一致的位置，记为r；
相减结果即为最短子数组的长度

### 代码

```swift
class Solution {
    func findUnsortedSubarray(_ nums: [Int]) -> Int {
        let sortArray = nums.sorted()
    var l = 0
    var r = 0
    for item in nums.enumerated() {
        if nums[item.offset] > sortArray[item.offset] {
            l = max(l, item.offset)
            break
        }
    }
    for item in nums.enumerated().reversed() {
        if nums[item.offset] < sortArray[item.offset] {
            r = max(r, item.offset+1)
            break
        }
    }
    return r - l
    }
}
```