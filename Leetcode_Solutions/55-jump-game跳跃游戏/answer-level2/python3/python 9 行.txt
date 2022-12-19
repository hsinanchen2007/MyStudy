```
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        end = 0  # 用end来表示位置i处可以跳跃的范围nums[i]+i
        max_index = 0  # 用max_index来表示位置i到位置nums[i]+i之间是否存在一个位置j使得j+nums[j]>=i+nums[i],这样的话就从i位置起跳到j位置，而不是i+nums[i]位置
        for i in range(n):
            max_index = max(max_index, nums[i]+i)
            if i == end:
                if max_index >= n-1: return True  # 表示位置i到位置nums[i]+i之间存在一个位置j使得j+nums[j] > n-1，那肯定能跳到最后位置
                elif max_index == end and nums[end] == 0: return False  # 表示跳不出i到i+nums[i]这个范围，而且i+nums[i]处的值为0，那永远也跳不出i到i+nums[i]这个范围了，所以返回False
                end = max_index
```
