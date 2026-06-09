

```
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        return (n **  2 + n) // 2 - sum(nums)
```
