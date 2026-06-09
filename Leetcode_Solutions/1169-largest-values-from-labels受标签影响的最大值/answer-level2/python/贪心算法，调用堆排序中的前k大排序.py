调用堆排序中的前k大排序，避免全部排序额外开销
```python
from heapq import nlargest
class Solution:
    def largestValsFromLabels(self, values: List[int], labels: List[int], num_wanted: int, use_limit: int) -> int:
        label_value = {}
        for v, l in zip(values, labels):
            label_value[l] = label_value.get(l, [])+[v]
        res = []
        for k, v in label_value.items():
            res.extend(nlargest(use_limit, v))
        return sum(nlargest(num_wanted, res))
```
