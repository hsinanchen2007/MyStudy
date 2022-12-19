### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        if len(nums) == 0: return 0
        if len(nums) == 1: return nums[0]
        if len(nums) == 2: return max(nums)
        ans = [0]*len(nums)
        ans[:2] = nums[:2]
        ans[2] = nums[0]+nums[2]
        for i in range(3, len(nums)):
            ans[i] = nums[i] + max(ans[i-2], ans[i-3])
        return max(ans[-1], ans[-2])

```