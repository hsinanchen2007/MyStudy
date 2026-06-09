```
class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        i = 0
        d = len(nums)
        while i < d:
            if nums[i]==val:
                nums.remove(val)
                d -=1
            else:
                i +=1
        return len(nums)
```
