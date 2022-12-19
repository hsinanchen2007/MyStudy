执行用时36ms，内存消耗13.9MB
```
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        n = len(nums)
        i = 0
        while i <= n-1:
            if nums[i] == val:
                nums.pop(i)
                n = len(nums)
            else:
                i += 1
        return n

```
