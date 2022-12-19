```python []
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        if not nums:    return -1
        bit = 0
        for n in nums:
            if (1<<n)&bit:  return n
            else:   bit |= (1<<n)
```
时间复杂度排名靠后233
