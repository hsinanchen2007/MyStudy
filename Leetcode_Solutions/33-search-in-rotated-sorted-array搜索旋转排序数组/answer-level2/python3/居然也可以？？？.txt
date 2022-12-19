```
class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if len(nums) == 0:return -1
        else:
            for i in range(len(nums)):
                if (nums[i] == target): return i
                if i == len(nums)-1 and nums[i] != target: return -1
```
