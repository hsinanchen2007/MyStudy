```python
from heapq import nsmallest
class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        counts = {}
        for i, w in enumerate(words):
            counts[w] = counts.get(w, 0) + 1
        return nsmallest(k, counts, lambda i: (-counts[i], i))
```
