### 解题思路
用filter函数

### 代码

```python
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        return filter(lambda x:nums.count(x)==1,nums)
```