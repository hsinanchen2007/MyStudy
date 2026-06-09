将第一家和最后一家分开考虑。

```
class Solution:
    def rob(self, nums: List[int]) -> int:
        if not nums:
            return 0
        if len(nums) <= 2:
            return max(nums)
        m, n = nums[0], max(nums[0], nums[1])
        p, q = nums[1], max(nums[1], nums[2])
        for i in nums[2:-1]:
            m, n = n, max(m+i, n)
        for j in nums[3:]:
            p, q = q, max(p+j, q)
        return max(n, q)
```