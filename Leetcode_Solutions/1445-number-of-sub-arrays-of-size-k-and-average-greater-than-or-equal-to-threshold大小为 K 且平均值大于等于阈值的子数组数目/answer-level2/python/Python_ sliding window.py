### 解题思路
Sliding window, 一次历遍。

### 代码

```python
class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        n = len(arr)
        if n < k: return 0
        k_sum = sum(arr[:k])
        res = 1 if k_sum >=k*threshold else 0
        for i in range(k, n):
            k_sum = k_sum - arr[i-k] + arr[i]
            res += 1 if k_sum >=k*threshold else 0
        return res
```