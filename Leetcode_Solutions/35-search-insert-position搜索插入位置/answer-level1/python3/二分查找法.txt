```
class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        i = 0
        j = len(nums)-1
        while i<=j:
            m = (i+j)//2
            if target==nums[m]:
                return m
            elif target>nums[m]:
                i = m + 1
            else:
                j = m - 1
        return i

```
