啊哈

```python []
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        l = 0
        r = n - 1
        while(l<=r):
            mid = (l+r)//2
            if target == nums[mid]:
                mid_l = mid-1
                mid_r = mid+1
                while(mid_l>=0 and nums[mid_l]==target):
                    mid_l -= 1
                mid_l += 1
                while(mid_r<= n-1 and nums[mid_r]==target):
                    mid_r+=1
                mid_r -= 1
                return [mid_l,mid_r]
            elif target<nums[mid]:
                r = mid - 1
            elif target>nums[mid]:
                l = mid + 1
        return [-1,-1]
```
