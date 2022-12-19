### 解题思路

    暴力解题 
    长度小于等于2 直接返回最大值 长度等于0 就返回0
    每次第i次 取0-(i-1) 的最大值 进行累加
    最后返回 最大值就OK

### 代码

```python
class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if(len(nums)<=2 and len(nums)!=0):
            return max(nums)
        if (len(nums)==0):
            return 0
        sum = 0
        for i in range(2, len(nums)):
            nums[i] += max(nums[:i-1])
        return max(nums)
```