### 解题思路
5分钟搞定

### 代码

```python3
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if target in nums:
            return nums.index(target)
        else:
            i= 0
            if target < nums[0]:
                return 0
            elif target > nums[-1]:
                return len(nums)
            else:
                for i in range(len(nums)-1):
                    if target>nums[i] and target <nums[i+1]:
                        return i+1
```