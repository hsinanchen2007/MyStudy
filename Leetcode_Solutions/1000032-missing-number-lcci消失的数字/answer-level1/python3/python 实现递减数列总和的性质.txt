```
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        _len = len(nums)
        _sum = (0 +_len)*(_len+1)/2
        real_sum = sum(nums)
        return int(_sum - real_sum)
```
