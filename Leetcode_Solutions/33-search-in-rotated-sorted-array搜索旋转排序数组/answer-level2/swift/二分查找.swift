### 解题思路

就是变种的二分查找，仔细分析题会发现 数组是分两段 升序的
比如 【4， 5， 0，1，2】  4 -> 5 为升序 并且 0 -> 2 为升序 
这样其实 仔细 分析 比较 target  first  和 midValue  就能找到下一步 是选择 左半边， 还是选择右半边了

### 代码

```swift
class Solution {
func search(_ nums: [Int], _ target: Int) -> Int {
    guard nums.count > 2 else {
        return nums.firstIndex(of: target) ?? -1
    }
    
    let first = nums.first!
    var l = nums.startIndex
    var r = nums.endIndex - 1
    
    while l <= r {
        let mid = (l + r) / 2
        let midValue = nums[mid]
        
        if target > first {
            if midValue < first {
                r = mid - 1
            } else {
                if target > midValue {
                    l = mid + 1
                } else if target < midValue {
                    r = mid - 1
                } else {
                    return mid
                }
            }
        } else if target < first {
            if midValue >= first {
                l = mid + 1
            } else {
                if target < midValue {
                    r = mid - 1
                } else if target > midValue {
                    l = mid + 1
                } else {
                    return mid
                }
            }
        } else {
            return 0
        }
     }
    return -1
}

}
```