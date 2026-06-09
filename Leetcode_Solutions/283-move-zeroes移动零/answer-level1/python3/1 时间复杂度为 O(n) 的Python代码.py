### 解题思路
非零元素的移动位数就是他前面的零元素的个数

### 代码

```python3
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i = 0
        for j in range(len(nums)):
            if nums[j] == 0:i += 1
            nums[j-i] = nums[j]
        for j in range ((len(nums)-i),len(nums)):
            nums[j] = 0
```