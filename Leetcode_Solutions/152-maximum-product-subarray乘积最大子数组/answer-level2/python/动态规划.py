### 解题思路
此处撰写解题思路
1,分析此题,是求连续的正数乘积序列
2.注意遇见负数该子序列会最大值变最小值,最小值变最大值

### 代码

```python
class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        maxs  = nums[0]
        imins   =  1
        imax   = 1
        res = 0
        for i in range(n):
            if nums[i] < 0:
                tmp = imax 
                imax = imins
                imins= tmp

            imax = max(imax * nums[i],nums[i])
            imins = min (imins * nums[i],nums[i])
            maxs = max(maxs,imax)

        return maxs
        
```