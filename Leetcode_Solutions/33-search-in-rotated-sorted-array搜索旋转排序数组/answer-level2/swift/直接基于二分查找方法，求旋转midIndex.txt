### 解题思路
1. 找到最小数字的位置minIndex
2. 二分法求mid（相当于当前数组的mid索引），然后根据当前mid求rotateMidIndex（也就是完整排好顺序的数组index）
3. 将数组当成排好顺序的数组，使用对应的rotateMidIndex比较。

注意
`mid = low + ((high - low) >> 1)` 跟`mid = (high + low) / 2` 一样。但是前者效率更高。

### 代码

```swift
class Solution {
    func search(_ nums: [Int], _ target: Int) -> Int {
        guard nums.count > 0 else {
            return -1
        }
        var minIndex = 0
        for i in 0..<nums.count {
            if nums[i] < nums[minIndex] {
                minIndex = i
                break
            }
        }
        
        var low = 0
        var high = nums.count - 1
        var mid = 0
        var rotateMidIndex = 0
        while low <= high {
            mid = low + ((high - low) >> 1)

            rotateMidIndex = mid + minIndex
            if rotateMidIndex >= nums.count { rotateMidIndex -= nums.count }

            if nums[rotateMidIndex] == target {
                return rotateMidIndex
            }
            if nums[rotateMidIndex] > target {
                high = mid - 1
            } else {
                low = mid + 1
            }
        }
        return -1
    }
}
```