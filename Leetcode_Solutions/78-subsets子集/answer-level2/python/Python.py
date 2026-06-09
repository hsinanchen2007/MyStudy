### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ans=[[]]

        for i in nums:
            ans=ans+[cur+[i] for cur in ans]
        return ans
```