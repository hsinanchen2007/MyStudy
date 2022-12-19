### 解题思路
动态规划

### 代码

```python3
class Solution:
    def canJump(self, nums: List[int]) -> bool:

        max_step = 0
        for i in range(len(nums)-1):
            max_step = max(max_step, nums[i] + i)
            if max_step <= i: 
                return False
        return max_step >= len(nums) - 1
```