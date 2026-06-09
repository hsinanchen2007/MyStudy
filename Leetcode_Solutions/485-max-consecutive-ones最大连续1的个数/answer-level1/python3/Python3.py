```
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        return len(max("".join([str(i) for i in nums]).split("0"), key=len))
```
