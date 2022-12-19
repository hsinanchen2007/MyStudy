### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        if len(nums) == 1:
            return nums[0]
        if len(nums) == 2:
            return nums[0] if nums[0] > nums[1] else nums[1]
        if len(nums) == 3:
            return nums[1] if nums[1] > nums[0] + nums[2] else nums[0] + nums[2]
        l = len(nums) // 2
        a = self.massage(nums[:l]) + self.massage(nums[l+1:])
        b = self.massage(nums[:l-1]) + self.massage(nums[l:])
        return max(a, b)

```