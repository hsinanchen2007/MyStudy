```python
class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        if k > len(arr) or arr == []: return 0
        temp_sum = 0
        res = 0
        for i in range(len(arr)):
            temp_sum += arr[i]
            if i >= k - 1:
                if temp_sum  >=  threshold * k:
                    res += 1
            if i >= k - 1:
                temp_sum -= arr[i - k + 1]
        return res
```