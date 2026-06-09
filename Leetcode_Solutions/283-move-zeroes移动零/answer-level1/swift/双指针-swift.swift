### 解题思路
1.变量j永远指向下一个待交换元素0的位置

### 代码

```swift
class Solution {
    func moveZeroes(_ nums: inout [Int]) {
        var j = 0
        for (key,_) in nums.enumerated() {
            if nums[key] != 0 {
                if key != j {
                    nums[j] = nums[key]
                    nums[key] = 0
                }
                j+=1
            }
        }
        
    }
}
```