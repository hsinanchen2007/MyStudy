四个数取出两个数之后,做加减乘除处理之后加入到原数组中会剩下三个数,递归交给下一层去处理
```python
class Solution:
    def judgePoint24(self, nums: List[int]) -> bool:
        if not nums: return False
        def helper(nums):
            if len(nums) == 1: return abs(nums[0]-24) < 1e-6
            for i in range(len(nums)):
                for j in range(len(nums)):
                    if i != j:
                        newnums = [nums[k] for k in range(len(nums)) if i != k != j]
                        if helper(newnums + [nums[i]+nums[j]]): return True
                        if helper(newnums + [nums[i]-nums[j]]): return True
                        if helper(newnums + [nums[i]*nums[j]]): return True
                        if nums[j] != 0 and helper(newnums + [nums[i]/nums[j]]): return True
            return False
        return helper(nums)
```