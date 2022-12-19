没想到通过了
```
class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        nums.sort()
        res = []
        i = 0
        while i<=len(nums)-2:
            min_i = min(nums[i],nums[i+1])
            res.append(min_i)
            i += 2
        return sum(res)

```
