### 解题思路
利用字典的key val存储二维信息

### 代码

```python
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        d = {}
        for idx, val in enumerate(nums):
            sub = target - val
            if val in d:
                return [d[val], idx]
            else:
                d[sub] = idx
```