主要是问题的转换，相当于是****每次**只有一个数字减1**，那么都减到最小值
```
class Solution:
    def minMoves(self, nums: List[int]) -> int:
        return sum(nums)-min(nums)*len(nums)
```
