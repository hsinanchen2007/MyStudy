### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        wr = 0
        rd = 0
        while rd < len(nums):
            if nums[rd] != 0:
                nums[wr], nums[rd] = nums[rd], nums[wr]
                wr += 1
            rd += 1
```