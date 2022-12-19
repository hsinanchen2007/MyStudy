### 解题思路
#此处撰写解题思路
菜鸟
题目中说 给定一个排序数组，所以考虑用二分法进行查找。
### 代码

```python3
import math
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if target in nums:
            return nums.index(target)

        if target > nums[-1]:
            return len(nums)
        if target < nums[0]:
            return 0

        left = 0
        right = len(nums)-1
        while right > left:
            middle = math.floor((left+right)/2)
            if nums[middle] > target:
                right = middle   
            else:
                left = middle + 1
            
        #print('left = {}, right = {}, mid = {}'.format(left, right, middle))
        return right
            
```