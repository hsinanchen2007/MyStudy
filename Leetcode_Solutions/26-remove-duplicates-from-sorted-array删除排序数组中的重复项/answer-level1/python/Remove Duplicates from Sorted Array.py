```
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        index_i = 0
        for index_j in range(1, len(nums)):
            if nums[index_i] != nums[index_j]:
                index_i += 1
                nums[index_i] = nums[index_j]
        
        return index_i + 1
```
