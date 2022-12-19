### 解题思路
时间复杂度：O（n）

### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
            return 0
        count = 0
        del_count = 0
        for i in range(len(nums)):
            if nums[i-del_count] not in nums[0:i-del_count]:
                count += 1
            else:
                del nums[i-del_count]
                del_count += 1
        return count
```