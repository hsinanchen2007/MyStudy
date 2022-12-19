### 解题思路
此处撰写解题思路

### 代码

```python
import math
class Solution(object):
    def searchRange(self, nums, target):
        ## 二分法查找target位置的左右边界
        if not nums:
            return [-1,-1]
        len_nums = len(nums)-1
        right = len_nums

        left=0

        res=[-1,-1]


        while left<right:
            index=int((right+left)/2)
   
            if nums[index] >= target:
                right=index
            else:
                left=index+1
        

        if nums[left]!=target:
             return res

        res[0]=left
        right=len_nums+1

        while left<right:
            index=int((right+left)/2)

            if nums[index] <= target:
                left=index+1
            else:
                right=index
        res[1]=left-1
        return res
           







        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
```