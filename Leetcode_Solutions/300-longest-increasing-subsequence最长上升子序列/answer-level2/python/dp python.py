### 解题思路
当前dp更新时扫描前面的数组元素，有更小的数组num[i]就取出它的dp[i]+1 比较

### 代码

```python
class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #dp[i]表示当前num[i]的最长上升子序列的长度
        if not nums:
            return 0
        dp = [1] * len(nums)
        for i in range(len(nums)):
            for j in range(0, i+1):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], dp[j]+1)
        
        return max(dp)


    
```