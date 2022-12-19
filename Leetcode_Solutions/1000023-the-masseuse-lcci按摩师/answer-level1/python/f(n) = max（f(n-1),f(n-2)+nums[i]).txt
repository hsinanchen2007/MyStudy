### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def massage(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        lenth =len (nums)
        dp =[]
        if lenth == 0:
            return 0
        dp.append(nums[0])
        if  lenth == 1:
            return nums[0]
        sin=max(nums[0],nums[1]) 
        dp.append (sin)
        
        for i in range(2,lenth,1):
            sin2=dp[i-2]+nums[i]
            dp.append (max(dp[i-1],sin2))
        return dp[lenth-1]
        
```