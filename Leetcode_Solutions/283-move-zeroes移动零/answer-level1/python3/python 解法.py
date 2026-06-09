### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        pointer_zero = 0
        for i in range(len(nums)):
            if nums[i] == 0:
                continue
            else:
                nums[pointer_zero], nums[i] = nums[i], nums[pointer_zero]
                pointer_zero += 1
        return nums

```