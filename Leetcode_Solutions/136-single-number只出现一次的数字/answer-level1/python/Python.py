### 解题思路
用dict中的key记录nums中出现的整数，用相应的value记录次数，若出现次数为1则返回key

### 代码

```python
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        d = {}
        brief = set(nums)
        
        for i in brief:
            d[i] = 0

        for j in nums:
            d[j] += 1

        for key,value in d.items():
            if value == 1:
                return key


```