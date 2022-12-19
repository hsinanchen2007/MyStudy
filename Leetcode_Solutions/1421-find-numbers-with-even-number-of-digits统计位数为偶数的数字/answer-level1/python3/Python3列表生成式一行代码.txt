```
class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        return sum([1 for item in nums if len(str(item)) % 2 == 0])
```
