### 解题思路

滚动动归，打家劫舍

### 代码

```python []
class Solution:
    def massage(self, nums: List[int]) -> int:
        pre, cur = 0, nums and nums[0] or 0
        for num in nums[1: ]:
            pre, cur = cur, max(cur, pre + num)
        return cur
```