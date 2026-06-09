### 解题思路
1. 不在范围内
2. 有此目标值
3. 目标值在其中两值范围

### 代码

```python3
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if target<nums[0]:
            return 0
        elif target>nums[-1]:
            return len(nums)

        for i,v in enumerate(nums):
            if v==target:
                return i
            elif nums[i-1]<target<nums[i]:
                return i
```