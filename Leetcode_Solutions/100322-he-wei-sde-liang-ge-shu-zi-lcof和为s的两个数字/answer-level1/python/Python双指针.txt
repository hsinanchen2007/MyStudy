### 解题思路
从两端开始查找

### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        l = 0
        r = n-1
        while l<=r:
            if nums[l] +  nums[r] == target:
                return [nums[l],nums[r]]
            elif nums[l] +  nums[r] > target:
                r -= 1
            else:
                l += 1
        return
```