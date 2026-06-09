### 解题思路
按size筛组后分裂，最后组装

### 代码

```python3
class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        out = []
        for i in set(groupSizes):
            t = [idx for idx, size in enumerate(groupSizes) if size == i]
            out += [t[j:j+i] for j in range(0, len(t), i)]
        return out
```