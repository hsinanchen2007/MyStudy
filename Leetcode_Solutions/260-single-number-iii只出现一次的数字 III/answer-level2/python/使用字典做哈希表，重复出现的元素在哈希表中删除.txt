### 解题思路
使用字典，一定要及时删除重复出现的元素，同时字典的元素直接赋值None，执行时间会少一半，最后可以直接强制类型转换，内存占用也会少一丢丢

### 代码

```python
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        hash={}
        for ele in nums:
            if ele in hash:hash.pop(ele)
            else:hash[ele]=None
        return list(hash)
```
