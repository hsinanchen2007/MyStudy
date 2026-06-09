### 解题思路
将为零的元素移动到list末尾即可

### 代码

```python
class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        for i in nums:
            if i==0:
                nums.append(0)
                nums.remove(i)
```