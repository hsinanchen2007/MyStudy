```
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        l = 0
        r = len(nums) #这里值得注意可以稍微扩大一点
        while l < r:
            mid = (l+r)>>1
            if nums[mid] >= target:
                r = mid
            else:
                l = mid+1
        return l
```
