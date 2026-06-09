### 解题思路
通过字典遍历进行计算

### 代码

```python
class Solution(object):
    def findRepeatNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        con_dict = {}
        for item in nums:
            if item in con_dict:
                con_dict[item] += 1
            else:
                con_dict[item] = 1
        for key,value in con_dict.items():
            if value > 1:
                return key
```