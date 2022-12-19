```python
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        res = float('inf')
        for i in range(len(nums) - 2):
            if i > 0 and nums[i] == nums[i - 1]: continue
            l, r = i + 1, len(nums) - 1
            while l < r:
                tempSum = nums[l] + nums[r] + nums[i]
                if tempSum == target: return target
                elif tempSum < target:
                    if abs(target - res) > abs(tempSum - target):
                        res = tempSum
                    l += 1
                else:
                    if abs(target - res) > abs(tempSum - target):
                        res = tempSum
                    r -= 1
        return res
```