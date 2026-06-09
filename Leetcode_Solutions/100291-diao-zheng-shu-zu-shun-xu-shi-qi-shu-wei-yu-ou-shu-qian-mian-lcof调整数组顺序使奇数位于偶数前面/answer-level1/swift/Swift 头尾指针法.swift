### 解题思路

如果s 和 e 没有相遇，则一直执行
- 头指针s 一直遇到偶数停下来
- 尾指针e 一直遇到奇数停下来

如果s < e 则，进行元素互换

### 代码

```swift
class Solution {
    func exchange(_ nums: [Int]) -> [Int] {
        var nums = nums
        var s = 0
        var e = nums.count - 1        
  
        while s < e {
            while s < e && nums[s] % 2 != 0 {
                s += 1
            }
            
            while s < e && nums[e] % 2 == 0  {
                e -= 1
            }
            if  s < e {
                let t = nums[s]
                nums[s] = nums[e]
                nums[e] = t
            }
        }
        return nums
    }
}
```