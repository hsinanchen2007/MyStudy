```
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        nums=[]
        loc=0
        for i in range(n):
            nums.append(i)
        while (len(nums)>1):
            loc=(loc+m-1)%len(nums)
            nums.pop(loc)
        return nums[0]
```
