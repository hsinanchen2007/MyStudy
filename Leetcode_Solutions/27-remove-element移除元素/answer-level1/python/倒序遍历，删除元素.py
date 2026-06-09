倒着遍历，这样删除的时候尽管删除，前面的不受影响
```
class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        for i in range(len(nums),0,-1):
            if(nums[i-1]==val):
                nums.pop(i-1)
        return len(nums)
```
