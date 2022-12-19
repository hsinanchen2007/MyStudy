```
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        return collections.Counter(nums).most_common(1)[0][0]
```

