### 解题思路
DPDPDPDPDPDPDPDP

### 代码

```python3
class Solution:
    def massage(self, nums) -> int:
        if nums == []:
            return 0
        if len(nums) == 1:
            return nums[0]
        nums[1] = max(nums[0], nums[1])
        for i in range(2, len(nums), 1):
            nums[i] = max(nums[i] + nums[i - 2], nums[i - 1])

        return nums[len(nums) - 1]

```