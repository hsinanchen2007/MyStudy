### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def maxSlidingWindow(self, nums, k):
        if len(nums)==0:
            return([])

        res=[]


        for i in range(len(nums)-k+1):
            res.append(max(nums[i:i+k]))
        return(res)
    



        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
```