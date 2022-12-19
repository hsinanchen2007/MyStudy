### 代码

```python3
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        lo, hi = 0, len(nums)-1
        while lo <= hi:
            mid = lo + ((hi - lo) >> 1)
            if nums[mid] != mid:
                if mid == 0 or nums[mid-1] == mid-1:
                    return mid
                hi = mid - 1
            else:
                lo = mid + 1
        return lo
```