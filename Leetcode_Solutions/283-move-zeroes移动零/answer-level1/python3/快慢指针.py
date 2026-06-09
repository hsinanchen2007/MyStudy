### 解题思路
快指针遇到非0数据就慢指针交换数据，慢指针始终指向0

### 代码

```python3
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i, j = 0, 0
        while j < len(nums):
            if not nums[j] == 0:
                nums[i], nums[j] = nums[j], nums[i]
                i += 1 
            j += 1

```