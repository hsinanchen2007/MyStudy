### 解题思路
菜鸡思路：先把nums排序，遍历nums，检查是否有相邻的两个元素相等，若相等则直接返回。

### 代码

```python3
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        nums = sorted(nums)
        n = len(nums)
        if n < 2 or n > 100000 or nums == []:
            return false
        else:
            i = 0
            while i < n-1:
                if nums[i] == nums[i+1]:
                    return nums[i]
                i += 1
        
```