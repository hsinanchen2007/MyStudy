python中的list和dict都可以做，dict做得快一些

```python3
class Solution:
    def findRepeatNumber(self, nums: [int]) -> int:
        r = {}
        for i in nums:
            if i in r:
                return i
            r[i] = i
```
击败100%用户的时间和空间
