```
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        # 从开始到当前位置i可以跳跃的最大步s是否为s==i,出现说明当前i步能跳跃0步，
        # 且之前的状态无法跳过这个0。
        s = 0
        for i in range(len(nums)-1):
            s = max(i+nums[i],s)
            if s == i:
                return False
        return True
```
