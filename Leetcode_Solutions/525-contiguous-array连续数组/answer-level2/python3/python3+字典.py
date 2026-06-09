### 解题思路
借鉴了powcai大佬的思路

### 代码

```python3
class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        for idx, val in enumerate(nums):
            if val == 0:
                nums[idx] = -1

        res = 0
        cur_sum = 0
        lookup = {0: -1}
        for idx, num in enumerate(nums):
            cur_sum += num
            if cur_sum in lookup:
                res = max(res, idx - lookup[cur_sum])
            else:
                lookup[cur_sum] = idx
        return res
```