只要涉及到 数都比数组长度小的题  都利用数组元素可以当数组index用的方法，把相应位置弄成负的。

比如 448. Find All Numbers Disappeared in an Array 找到所有数组中消失的数字
https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/



```
class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        for i in range(0,len(nums)):
            if (nums[abs(nums[i])] < 0):
                return abs(nums[i])
            else:
                nums[abs(nums[i])] = -nums[abs(nums[i])]
```
