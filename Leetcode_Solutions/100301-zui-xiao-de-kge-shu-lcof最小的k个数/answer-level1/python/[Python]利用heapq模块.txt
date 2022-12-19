```python
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        from heapq import nsmallest
        return nsmallest(min(k, len(arr)), arr)
```
