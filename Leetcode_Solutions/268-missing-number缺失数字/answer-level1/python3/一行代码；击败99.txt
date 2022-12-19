直接理想总和（高斯累加，（首项+尾项）**项数//2） 减去 数组总和。

```
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        return (len(nums)+1)*len(nums)//2-sum(nums)
```
