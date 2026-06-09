### 解题思路
熟练掌握快排。
执行用时 :204 ms, 在所有 Swift 提交中击败了96.58%的用户

### 代码

```swift
class Solution {
    func sortArray(_ nums: [Int]) -> [Int] {
        var newNums = nums

        //快速排序
        quickSort(&newNums, 0, newNums.endIndex - 1)

        return newNums
    }

    // 快速排序
    func quickSort(_ nums: inout [Int], _ start: Int, _ end: Int) {
        if start >= end {
            return
        }

        var i = start, j = end
        let temp = nums[i]
        
        while i < j {
            while i < j && temp <= nums[j]{
                j -= 1
            }

            nums[i] = nums[j]

            while i < j && nums[i] <= temp {
                i += 1
            }

            nums[j] = nums[i]
        }

        nums[i] = temp
        quickSort(&nums, start, i-1)
        quickSort(&nums, i+1, end)
    }
}
```