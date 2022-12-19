```python
import bisect
class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        # binary search
        if nums == []: return 0
        ans, arr = 0, []
        for num in reversed(nums):
            ans += bisect.bisect_left(arr, num)
            bisect.insort(arr, num * 2) # O(N) but actually it's very fast
        return ans
```