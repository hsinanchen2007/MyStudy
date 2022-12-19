
```
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        return [m for m in set(nums) if nums.count(m) > len(nums) / 2][0]

```
set实现实际上也是hash