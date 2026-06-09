```
class Solution(object):
    def wiggleSort(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        nums.sort()
        for i in range(1,len(nums),2):
            if i+1 <len(nums):
                nums[i],nums[i+1] = nums[i+1],nums[i]

        return 
```
