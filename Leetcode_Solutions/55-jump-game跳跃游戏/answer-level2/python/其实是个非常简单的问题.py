思路：从头开始跳，每一步记录当前能跳到的最远位置，如果能到达或超过最后一个位置则返回true，如果当前位置能跳到的最远位置是当前位置说明无法继续跳跃了，返回false。

```
class Solution:
    def canJump(self, nums: [int]) -> bool:
        canGo = 0
        for i in range(len(nums)):
            if nums[i] + i > canGo: canGo = nums[i] + i
            if canGo >= len(nums) - 1: return True
            if canGo == i: return False
        return True
```
