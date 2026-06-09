### 解题思路
看到题目之后根据示例考虑所有的极端情况，针对目标小于顺序数组最小和目标大于顺序数组最大分别进行处理。然后对在数组中的情况利用while循环从头遍历，条件设置为小于等于即可同时处理**存在目标**和**不存在目标**两种情况。

### 代码

```python3
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if target > max(nums):
            return len(nums)
        elif target < min(nums):
            return 0
        for i in range(len(nums)):
            while target<=nums[i]:
                return i
            
```