```python
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()
        for i in range(len(nums) - 2):
            if nums[i] > 0 : break
            if i > 0 and nums[i] == nums[i - 1]: continue
            pre, last = i + 1, len(nums) - 1
            while pre < last:
                if nums[pre] + nums[last] + nums[i] == 0:
                    if pre > i + 1 and nums[pre] == nums[pre - 1]: pass
                    else:
                        res.append([nums[i], nums[pre], nums[last]])
                    pre += 1
                elif nums[pre] + nums[last] + nums[i] > 0:
                    last -= 1
                else:
                    pre += 1
        return res

```