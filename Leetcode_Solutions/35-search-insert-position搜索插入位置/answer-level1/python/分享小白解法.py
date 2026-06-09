### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
#判断target是否在数组中，在的话直接返回位置
        if target in nums:
            return nums.index(target)
#判断target是否比数组中所有的数大，是的话直接返回数组的长度
        if target>nums[-1]:
            return len(nums)
#排除以上两种情况
        for i in range(len(nums)):
            if nums[i]>=target:
                return i
```