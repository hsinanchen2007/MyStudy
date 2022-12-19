### 解题思路
听说有的大佬一行代码就完事了，我比较菜，想了很久用到了列表的特性才解决的

### 代码

```python
class Solution(object):
    def decompressRLElist(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        str1=[]
        for i in range(0,len(nums)):
          a = 2*i
          b = 2*i+1
          if b < len(nums):
             str1 = str1 + nums[a]*[nums[b]]
        return str1        
  


```