```python
class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        # sliding window
        ans = 0
        arr = [-1]
        for i, value in enumerate(nums):
            if value & 1 :
                arr.append(i)
        arr.append(len(nums))
        for i in range(1, len(arr) - k):
            ans += (arr[i] - arr[i - 1]) * (arr[i + k] - arr[i + k - 1])
        return ans
```