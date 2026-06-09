```python []
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if not nums: return 0
        n = len(nums)
        i = 0
        while nums[i]<target and i<n:
            i += 1
            if i==n: break
        return i
```



