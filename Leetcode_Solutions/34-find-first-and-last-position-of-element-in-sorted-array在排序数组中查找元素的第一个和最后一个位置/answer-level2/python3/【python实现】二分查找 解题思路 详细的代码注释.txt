解题思路：
因为数组`nums`已经排好序，需要查找两次的目标值，因此可以用二分搜索，达到O(logn)的复杂度
1. 对于查找`target`出现的开始位置，我们需要判断3个条件
+ `nums[middle] == target`
+ `middle == 0` or `nums[middle-1]  < target`

2. 对于查找`target`的结束位置，我们需要判断3个条件
+ `nums[middle] == target`
+ `middle == len(nums)-1` or `nums[middle+1]  > target`

![1.png](https://pic.leetcode-cn.com/456b48dadd7e25b57a92fbc6c281dbc9e5205c53156660862acaa49f5179c85d-1.png)

```
from typing import List
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        # 二分查找下边界
        def lowerbound(low, high):
            # 判断是否越界
            if low > high:
                return -1
            # 获取中位数
            middle = low + int((high - low) / 2)
            
            # 判断是否找到：与target相同的值，并且：middle就是第一个元素 or 前一个值比target小
            if nums[middle] == target and (middle == 0 or nums[middle-1] < target):
                return middle
            
            # 判断搜索方向
            if nums[middle] < target:  
                return lowerbound(middle+1, high)  # 若比目标数小，则往右搜索
            else: 
                # 否则，往左搜索。等于target的也往左，是因为下边界在相同值的最左边
                return lowerbound(low, middle-1)
            
        # 查找上边界
        def upperbound(low, high):
            # 判断是否越界
            if low > high:
                return -1
            # 获取中位数
            middle = low + int((high - low) / 2)
            
            # 判断是否找到
            if nums[middle] == target and (middle == len(nums)-1 or nums[middle+1] > target):
                return middle
            
            # 判断搜索方向
            if nums[middle] <= target:
                # 比目标数小，则向右搜索
                # 等于目标数也向右，因为上边界在相同值的最右边
                return upperbound(middle+1, high)  
            else:
                return upperbound(low, middle-1)  # 否则，向左搜索
            
        l = lowerbound(0, len(nums)-1)  # 获取下边界
        h = upperbound(0, len(nums)-1)  # 获取上边界
        
        return [l, h]
```