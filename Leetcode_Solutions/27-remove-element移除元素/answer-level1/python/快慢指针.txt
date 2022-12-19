```
class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        i=0
        for num in nums:
            if num!=val:
                nums[i]=num
                i+=1
        return i
```
