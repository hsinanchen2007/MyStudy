### 解题思路
利用一维dp求解，dp[i]代表从第i个下标所能跳的最远的位置。当dp[i-1]>i说明能够跳到下标i，此时dp[i] =max(dp[i-1], i+nums[i]),否则说明不能调到，dp[i]=dp[i-1],然后判断dp[i]是否大于等于len(nums)-1，大于说明可以直接退出，否则返回false
### 代码

```python3
'''
利用一维dp求解，dp[i]代表从第i个下标所能跳的最远的位置。当dp[i-1]>i说明能够跳到下标i，此时dp[i] =max(dp[i-1], i+nums[i]),否则说明不能调到，dp[i]=dp[i-1],然后判断dp[i]是否大于等于len(nums)-1，大于说明可以直接退出，否则返回false
'''
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        if len(nums)<=1:
            return True
        dp = [0] * len(nums)
        dp[0] = nums[0]

        for i in range(1, len(nums)):
            if dp[i-1]>=i:
                dp[i] = max(dp[i-1], i+nums[i])
            else:
                dp[i] = dp[i-1]
            if dp[i]>=len(nums)-1:
                return True
        
        return False
```