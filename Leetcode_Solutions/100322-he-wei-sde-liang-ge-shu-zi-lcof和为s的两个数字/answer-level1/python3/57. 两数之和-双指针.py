### 解题思路
left、right指针卡两头，由于是顺序数组，和小了left+1，和大了right-1.

### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        if not target or len(nums) == 1:
            return []
        if nums[-2]+nums[-1] < target or nums[0]+nums[1] > target:
            return []
        map = {}

        l, r = 0, len(nums)-1
        while l < r:
            if nums[l] + nums[r] < target:
                l += 1
            elif nums[l] + nums[r] > target:
                r -= 1
            else:
                return [nums[l], nums[r]]
        return []
```