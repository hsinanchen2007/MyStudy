### 代码

```python3
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        from collections import Counter
        cnt = Counter(nums)
        for k, v in cnt.items():
            if v == 1:
                return k
```