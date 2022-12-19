
```
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        s = set(nums)
        v = 1
        
        while True:
            if v not in s:
                return v
            v += 1
        
```

或者：

```
class Solution:
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n=1
        # nums = set(nums)
        while n in nums:
            n=n+1
        return n
```