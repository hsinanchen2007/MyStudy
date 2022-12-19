观察发现，数组去重后的和*3跟原来的数组的和刚好相差要找元素的2倍。
```
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        return (sum(set(nums))*3 - sum(nums)) // 2

```