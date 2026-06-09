### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def singleNonDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        len_nums=len(nums)
        if len_nums==0:
            return False
        if len_nums==1:
            return nums[0]
        if nums[0]!=nums[1]:
            return nums[0]
        for i in range(1,len_nums-1):
            if nums[i]!=nums[i+1] and nums[i]!=nums[i-1]:
                return nums[i]
        return nums[len_nums-1]
```