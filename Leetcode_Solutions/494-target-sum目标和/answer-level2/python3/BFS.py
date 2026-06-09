思路：根据题目的思想，列表中的每个值有两种可能性：+和-
那么每次增加两条分路，例如：
    i = 0: [nums[0], num[0]*(-1)]
    i = 1: [nums[0]+nums[1], nums[0]-nums[-1], -nums[0]+nums[1], -nums[0]-nums[1]]
依此规律一直加上去


```python []
class Solution:
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        
        stack = [nums[0], nums[0]*(-1)]
        for i in range(1, len(nums)):
            mid_stack = []
            while stack:
                node = stack.pop()
                mid_stack.append(node+nums[i])
                mid_stack.append(node-nums[i])
            stack = mid_stack
        return stack.count(S)
```
