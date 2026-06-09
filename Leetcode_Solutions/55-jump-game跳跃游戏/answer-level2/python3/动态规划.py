### 解题思路


### 代码

```python
class Solution(object):
    def canJump(self, nums):
        last = len(nums) - 1
        for i in range(len(nums) - 2, -1, -1):
            if last-i<=nums[i]:
                last=i
        return last == 0
```