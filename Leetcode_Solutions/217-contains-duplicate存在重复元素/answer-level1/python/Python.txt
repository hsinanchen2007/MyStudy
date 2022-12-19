### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        ans={}
        for i in nums:
            if i in ans:
                ans[i]=ans[i]+1
            else:
                ans[i]=1
        for i in ans:
            if ans[i]>1:
                return True
        return False
```