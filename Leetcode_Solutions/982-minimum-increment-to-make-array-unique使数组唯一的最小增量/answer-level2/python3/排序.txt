### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        nums = sorted(A)
        cnt = 0
        for i in range(1, len(nums)):
            if nums[i - 1] >= nums[i]:
                cnt += nums[i - 1] - nums[i] + 1
                nums[i] += nums[i - 1] - nums[i] + 1
        print(nums)
        return cnt
```