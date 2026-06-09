```
class Solution:
    def smallestK(self, arr: List[int], k: int) -> List[int]:
        nums = sorted(arr)
        return nums[:k]
```
