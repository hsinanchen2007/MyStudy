### 解题思路
1.确认问题与子问题
求第一个，第二个，第三个的最大值
2.确认问题单一
所有符合条件的最大值
3.确认边界
dp[0]=nums[0]
dp[1]=max(nums[0],nums[1])
4.确认状态转移
dp_cur=max(dp_last2+num[i],dp_last1)

### 代码

```python
import numpy as np
class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums)==0:
            return 0
        if len(nums)<3:
            return max(nums)
        #dp=list(np.zeros(len(nums)))
        dp_last2=nums[0]
        dp_last1=max(nums[0],nums[1])
        dp_cur=0
        for i in range(2,len(nums)):
            dp_cur=max(dp_last2+nums[i],dp_last1)
            dp_last2=dp_last1
            dp_last1=dp_cur
        return dp_cur
```