### 解题思路
遍历数组，碰到下一个数字是逆序数字的时候观察：
1.如果上一个数字比下一个数字大，则只能修改下一个数字为当前数字；
2.如果上一个数字比下一个数字小（或者想等），则只能修改当前数字为上一个数字或者下一个数字；
3.如果不存在上一个数字（当前数字为nums[0])，则按2处理。

### 代码

```swift
class Solution {
    func checkPossibility(_ nums: [Int]) -> Bool {
        
        
        var count = 0
        var nums = nums
        
        //遍历原数组
        for index in 0..<nums.count - 1 {
            
            //如果 当前项 大于 后项
            if nums[index] > nums[index + 1] {
                
                if index - 1 >= 0 {
                    //如果 前项 存在且 前项 大于 后项，则修改 后项 为 当前项
                    if nums[index - 1] > nums[index + 1] {
                        nums[index + 1] = nums[index]
                    } else {
                        //如果 前项 存在且 前项 小于等于 后项，则修改 当前项 为 后项
                        nums[index] = nums[index + 1]
                    }
                
                } else {
                    //如果 前项不存在，则修改当前项为后项
                    nums[index] = nums[index + 1]
                }
                
                count += 1
            }

            
            if count > 1 {
                return false
            }
            
        }
        
        return true

    }
}
```