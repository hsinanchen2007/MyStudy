### 解题思路
二分查找

### 代码

```swift
class Solution {
    func search(_ nums: [Int], _ target: Int) -> Int {
        
        //初始化两个指针分别指向原数组的头和尾
        var head = 0
        var tail = nums.count - 1
        
        //探查头尾中间的元素，如果中间元素比目标值大，则下一步应该往头部方向查找，此时新的尾巴为现在中间元素下标的前一位；
        //如果中间元素比目标值小，则下一部应该朝尾巴方向查找，此时新的头部为现在中间元素的后一位；
        while head <= tail {
            
            let mid = (head + tail) / 2
            
            if nums[mid] == target {
                return mid
            }
            else if nums[mid] > target {
                
                tail = mid - 1
            }
            else if nums[mid] < target {
                
                head = mid + 1
            }
        }
        
        return -1
        
    }
}
```