```python
class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        i, a, r = 0, 0, float('inf')
        for j in range(len(nums)):
            a += nums[j]
            while a >= s:
                r = min(r, j - i + 1)
                a -= nums[i]
                i += 1
        return 0 if r == float('inf') else r
```
- i, j 双指针滑窗，O(N)时间复杂度，O(1)空间复杂度
- a 代表 i 到 j 的总和