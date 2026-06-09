### 解题思路

投票啦

### 代码

```swift
class Solution {
    func majorityElement(_ nums: [Int]) -> Int {
        var m = nums[0]
        var c = 1
        for i in 1..<nums.count {
            let t = nums[i]
            if c == 0 {
                m = t
            } else
            if m == t {
                c += 1
            } else {
                c -= 1
            }
        }
        return m
    }
}
```