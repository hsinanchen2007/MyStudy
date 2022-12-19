### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        length=len(nums)
        for i in range(1,length):
            if nums[i]<nums[i-1]:
                return nums[i]
        return nums[0]
```