### 解题思路
排序后遍历

### 代码

```python3
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        nums.sort()
        for i in range(len(nums)):
            if nums[i+1]== nums[i]:
                return nums[i]
```