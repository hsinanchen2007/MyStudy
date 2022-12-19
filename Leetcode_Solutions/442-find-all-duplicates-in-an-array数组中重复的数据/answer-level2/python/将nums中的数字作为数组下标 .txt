
```python []
对应位置的数字取负数 如果发现已经是负数 说明这个下标是重复的。
class Solution(object):
    def findDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        res = []
        for n in nums:
            if nums[abs(n) - 1] < 0:
                res.append(abs(n))
            nums[abs(n) - 1] = - abs(nums[abs(n) - 1])
        return res

```

