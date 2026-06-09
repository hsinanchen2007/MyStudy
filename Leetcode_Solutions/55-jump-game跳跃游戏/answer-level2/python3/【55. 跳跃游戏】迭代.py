### 解题思路
坑[0]

### 代码

```python3
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        maxCurrent = 0
        for i in range(len(nums)):
            maxCurrent = max(maxCurrent, i + nums[i])
            if i >= maxCurrent:
                break
        if maxCurrent < len(nums) - 1:
            return False
        return True
```