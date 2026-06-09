### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def decompressRLElist(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        return [nums[i+1] for i in range(0,len(nums),2) for j in range(nums[i])]
```