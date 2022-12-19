### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        len_nums = len(nums)
        if len_nums == 1:
            return nums[0]
        mid = len_nums // 2
        if mid % 2 == 0:
            if nums[mid-1] == nums[mid]:
                return self.singleNonDuplicate(nums[0:mid+1])
            elif nums[mid+1] == nums[mid]:
                return self.singleNonDuplicate(nums[mid:])
            else:
                return nums[mid]
        else:
            if nums[mid] == nums[mid-1]:
                return self.singleNonDuplicate(nums[mid+1:])
            else:
                return self.singleNonDuplicate(nums[0:mid])
```