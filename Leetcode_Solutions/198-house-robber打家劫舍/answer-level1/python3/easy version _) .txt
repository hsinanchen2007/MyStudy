### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def rob(self, nums: List[int]) -> int:
        if not nums:
            return 0
        if len(nums) < 3:
            return max(nums)
        temp = [0] * len(nums)
        temp[0] = nums[0]
        temp[1] = max(nums[0], nums[1])
        for i in range(2,len(nums)):
            temp[i] = max(temp[i-2]+nums[i], temp[i-1])
        return temp[-1]

```