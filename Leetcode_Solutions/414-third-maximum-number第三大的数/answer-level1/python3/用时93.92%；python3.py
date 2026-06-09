### 解题思路
维护一个长度为三的降序数组，遍历整个nums，如果有比数组中最小的数字大的则将数组最后一位pop，然后添加新的数字。最后输出最小的即可。

### 代码

```python3
class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        nums = list(set(nums))
        if len(nums) < 3:
            return max(nums)
        elif len(nums) == 3:
            return min(nums)
        res = nums[:3]
        res = sorted(res,  reverse=1)
        for x in nums[3:]:
            if x > res[-1]:
                res.pop()
                res.append(x)
                res = sorted(res,  reverse=1)
        return res[-1]

```