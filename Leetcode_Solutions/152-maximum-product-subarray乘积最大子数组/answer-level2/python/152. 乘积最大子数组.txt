### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 1: return nums[0]
        res = 0
        maxNum, minNum = 1, 1
        for i in range(len(nums)):
            if nums[i] < 0:
                maxNum, minNum = minNum, maxNum
            maxNum = max(maxNum*nums[i], nums[i])
            minNum = min(minNum*nums[i], nums[i])
            res = max(res, maxNum)
        return res
```