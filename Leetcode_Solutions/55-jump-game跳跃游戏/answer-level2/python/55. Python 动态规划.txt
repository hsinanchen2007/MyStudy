### 解题思路
最开始用回溯做会超时，所以改成了动态规划。
这里的动态规划公式很简单不多做解释，dp记录的是当前位置最远可以到达的位置，所以当上一个位置最远可以到达的位置小于当前位置时，就可以返回False了。

### 代码

```python
class Solution(object):
    def canJump(self, nums):
        """ 
        :type nums: List[int]
        :rtype: bool
        """
        length = len(nums)
        dp = [0] * length
        dp[0] = nums[0]
        for i in range(1, length):
            if dp[i - 1] < i :
                return False
            dp[i] = max(dp[i - 1], i + nums[i])
        print(dp)
        return True
```