### 解题思路
此处撰写解题思路
加入指针，值相同时保存指标最大的元素
### 代码

```python
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) <= 1:
            return len(nums)
        flag = 0
        for i in range(1, len(nums)):
            if nums[flag]!= nums[i]:
                flag += 1
                nums[flag] = nums[i]
        return flag + 1
```