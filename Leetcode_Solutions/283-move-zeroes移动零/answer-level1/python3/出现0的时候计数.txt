### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        i, count = 0, 0
        for c in range(n):
            i = c-count
            if nums[i] == 0:
                nums.append(nums.pop(i))
                count += 1
            
        return nums
```