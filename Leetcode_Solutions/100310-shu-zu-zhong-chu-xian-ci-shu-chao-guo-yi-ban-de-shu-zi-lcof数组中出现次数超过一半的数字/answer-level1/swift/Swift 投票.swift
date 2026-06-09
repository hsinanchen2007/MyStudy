### 解题思路

比较简单的投票思路

### 代码

```swift
class Solution {
    func majorityElement(_ nums: [Int]) -> Int {

        var e:Int = nums[0]
        var c = 1
        for i in 1..<nums.count {
            let t = nums[i]
            if e == t {
                c += 1
            } else {
                c -= 1
            }
            if c == 0 {
                e = t
                c = 1
            } 
        }
        return e
    }
}
```