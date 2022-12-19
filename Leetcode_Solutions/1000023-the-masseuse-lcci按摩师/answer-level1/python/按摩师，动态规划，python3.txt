### 解题思路
状态转移方程：`nums[i] = max(nums[i-2]+nums[i], nums[i-1])`
不需要新建`dp`数组，直接在原数组修改

# 时间复杂度O(N)，空间复杂度O(1)

### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        for i in range(1, len(nums)):
            if i == 1:
                nums[i] = max(nums[i], nums[i-1])
                continue
            nums[i] = max(nums[i-2]+nums[i], nums[i-1])
        return nums[-1] if nums else 0
```