小弟太菜了，本来是学中医的，现在打算暴力转码，各位多多包涵。很多地方都是hard-code

1. 当list长度为1或者2的时候，直接暴力解法，硬写
2. 当长度为3或者以上的时候，使用递归的方法来进行二分查找
3. 
```
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:

        #直接暴力解法，强行设置list长度为1或者为2的情况
        if len(nums) == 1:
            if nums[0] >= target:
                return 0
            else:
                return 1
        
        if len(nums) == 2:
            if target <= nums[0]:
                return 0
            if target > nums[1]:
                return 2
            if target> nums[0] and target < nums[1]:
                return 1


        #长度为3的时候，开始使用二分查找法
        midpoint = len(nums) // 2

        if nums[midpoint] == target:
            return midpoint

        #开始递归
        elif nums[midpoint] < target:
            temp = self.searchInsert(nums[midpoint+1:], target)
            return midpoint + temp + 1
        else:
            temp = self.searchInsert(nums[0:midpoint],target)
            return temp
```

