### 解题思路
时间复杂度：O（n）
空间复杂度：O（1）

### 代码

```python3
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        i = 0
        j = 0
        has_occured = False
        while j < len(nums):
            if has_occured:
                nums[i] = nums[j]
            if nums[j] == val:
                j += 1
                has_occured = True
            else:
                j += 1
                i += 1

        return i
```