正向推，思路直白，时间空间复杂度也更低。

```python
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        step = 0 # 当前位置
        reachable = 0 # 最大可以到达的位置
        target = len(nums) - 1 # 目标位置
        while step <= reachable: # 只要还可以继续探索
            reachable = max(step + nums[step], reachable) # 就更新可以到达的位置
            if reachable >= target: # 达到目标就收工
                return True
            else: # 否则继续探索
                step += 1
        return False
```
