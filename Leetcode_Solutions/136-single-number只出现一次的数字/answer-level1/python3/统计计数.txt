### 解题思路
时间复杂度：O（n）
空间复杂度：O（n）

### 代码

```python3
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        from collections import defaultdict
        d = defaultdict(int)
        for i in nums:
            d[i] += 1
        for k, v in d.items():
            if v == 1:
                return k
        return 0
```