```python
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        res = []
        for i in range(len(nums) - 3):
            if i > 0 and nums[i] == nums[i - 1]: continue
            for j in range(i + 1, len(nums) - 2):
                if j > i + 1 and nums[j] == nums[j - 1]: continue
                pre, last = j + 1, len(nums) - 1
                while pre < last:
                    if nums[i] + nums[j] + nums[pre] + nums[last] == target:
                        res.append([nums[i], nums[j], nums[pre], nums[last]])
                        while pre < last and nums[pre + 1] == nums[pre]: pre += 1
                        while pre < last and nums[last - 1] == nums[last]: last -= 1
                        pre += 1; last -= 1
                    elif nums[i] + nums[j] + nums[pre] + nums[last] < target:
                        pre += 1
                    else:
                        last -= 1
        return res

```