### 解题思路
判断顺子就两个原则：最大和最小不能超过5，且不能出现对子。

### 代码

```swift
class Solution {
    func isStraight(_ nums: [Int]) -> Bool {
        // 1. 将数组排序，确保最后一个是最大值
        var newNums = nums.sorted()

        // 2. 对数组进行遍历，如果最大和除0的最小超过5，则不会顺子，如果有对子，也不是顺子
        for i in 0..<4 {
            if newNums[i] != 0 {
                if newNums[4] - newNums[i] >= 5 {
                    return false
                }
                if newNums[i] == newNums[i+1] {
                    return false
                }
            }
        }
        return true
    }
}
```