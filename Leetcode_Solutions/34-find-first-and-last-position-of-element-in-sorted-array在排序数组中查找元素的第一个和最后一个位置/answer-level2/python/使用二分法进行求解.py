思路就是按照二分法求解

```
class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if nums == []:return [-1,-1]
        start = 0
        end = len(nums) -1
        while start <= end:
            mid = (start + end) //2
            if nums[mid] == target:
                start,end = mid,mid
                while start >= 0 and nums[start] == target:
                    start = start - 1
                while end <= len(nums)-1 and nums[end] == target:
                    end = end + 1
                return [start+1,end-1]
            elif nums[mid] < target:
                start = mid + 1
            else:
                end = end - 1
        return [-1,-1]
```
