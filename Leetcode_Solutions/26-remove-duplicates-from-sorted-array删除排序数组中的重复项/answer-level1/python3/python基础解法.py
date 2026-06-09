### 解题思路
单指针判断和前一个数是否相等，相等计数不变，不想等计数加1

### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums: 
            return 0
        j = 1
        for i in range(1, len(nums)):
            if nums[i] != nums[i - 1]:
                nums[j] = nums[i]
                j += 1
        return j
```