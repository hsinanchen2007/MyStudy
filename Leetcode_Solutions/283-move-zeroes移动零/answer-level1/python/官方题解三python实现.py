### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        k = 0 #慢指针
        for i in range(len(nums)):
          if nums[i]:
            tmp = nums[k]
            nums[k] = nums[i]
            nums[i] = tmp
            k += 1
```