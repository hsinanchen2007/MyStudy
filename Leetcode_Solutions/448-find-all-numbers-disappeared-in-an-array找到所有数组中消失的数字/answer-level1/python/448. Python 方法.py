### 解题思路
两次遍历，第一遍历进行标记，标记方法是将nums[num - 1]标记为负值，这里需要注意的是需要判断指向的值是否已经是负数，否则对于出现两次的数，两次取负值就变成正的了。

### 代码

```python
class Solution(object):
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        for num in nums:
            num = abs(num)
            if nums[num - 1] > 0:
                nums[num - 1] = -nums[num - 1]
        res = []
        for i in range(len(nums)):
            if nums[i] > 0:
                res.append(i + 1)
        return res
```