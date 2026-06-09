### 解题思路
思路很简单：遍历数组，如果遇到0，则和右边第一个非0的元素交换即可。

### 代码

```python
class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        for i in range(len(nums)):
            if nums[i] == 0:
                j = i
                while j < len(nums) and nums[j] == 0:
                    j += 1
                if j == len(nums):
                    break
                nums[i] = nums[j]
                nums[j] = 0
```