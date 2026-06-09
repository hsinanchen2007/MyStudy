```
class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        return len(list(filter(lambda x : len(x)%2 == 0, map(str, nums))))
```
