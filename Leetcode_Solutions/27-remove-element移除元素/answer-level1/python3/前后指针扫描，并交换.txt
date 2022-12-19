```
class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        i = 0;
        j = len(nums) - 1
        while i<=j:
            while j>=i and nums[j] == val:
                j -= 1
            if j>=i and nums[i] == val:
                nums[i], nums[j] = nums[j], nums[i]
                j -= 1
            i += 1
        print(i,j, nums)
        return j+1
            
            
```

优化
```
class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        i = 0;
        j = len(nums) - 1
        while i<=j:
            if nums[i] == val:
                nums[i] = nums[j]
                j -= 1
            else:
                i += 1
        print(i,j, nums)
        return i
```

