```
class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        count = len(nums)
        if count == 0 or k == 0:
            return
        i = 0
        start = 0
        t = nums[start]
        while count>0:
            i = (i+k)%len(nums)
            t, nums[i] = nums[i], t
            if i == start:
                i = (i+1)%len(nums)
                t = nums[i]
                start = i
            count -= 1
```
