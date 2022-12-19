### 代码

```python
class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0: return -1
        cumsum = [0]
        for i in range(n):
            cumsum.append(cumsum[-1] + nums[i])
        for i in range(n):
            if cumsum[-1] - cumsum[i+1] == cumsum[i]:
                return i
        return -1
```