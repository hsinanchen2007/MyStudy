### 解题思路
很慢
### 代码

```python3
class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        import itertools

        r = []
        for each in range(len(nums)):
            if each % 2 == 0:
                for each2 in itertools.repeat(nums[each+1], nums[each]):
                    r.append(each2)
        return r
```