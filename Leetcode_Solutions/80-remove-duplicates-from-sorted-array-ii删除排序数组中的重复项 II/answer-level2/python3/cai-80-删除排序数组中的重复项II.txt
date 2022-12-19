### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        p, r, n = 0, 1, len(nums)
        f = 1
        while r < n:
            if nums[r] != nums[p]:
                p += 1
                nums[p] = nums[r]
                f = 1
            elif nums[r] == nums[p] and f:
                p += 1
                nums[p] = nums[r]
                f = 0
            r += 1
        return p+1
```