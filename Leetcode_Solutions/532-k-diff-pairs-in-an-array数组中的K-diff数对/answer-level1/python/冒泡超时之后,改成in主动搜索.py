### 解题思路
其实方法有点笨

### 代码

```python
class Solution(object):
    def findPairs(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        result=0
        if k<0:
            return result
        for i in set(nums):
            c=nums[:]
            c.remove(i)
            if i+k in c:
                result+=1
        
        return result

```