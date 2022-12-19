### 解题思路
如标题

### 代码

```python3
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        ln = len(nums)
        if ln == 0:
            return None
        s = set()
        for i in range(ln):
            if nums[i] not in s:
                s.add(nums[i])
            else:
                return nums[i]
        return None
```