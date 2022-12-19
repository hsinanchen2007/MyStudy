### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [[0]*2 for _ in range(n+1)]
        for i in range(1, n+1):
            dp[i][0] = max(dp[i-1][1], dp[i-1][0]) #第i个不抢
            dp[i][1] = nums[i-1] + dp[i-1][0] # 第i位抢，dp = 第i位值 + 第 i-1 不抢
        return max(dp[n][0], dp[n][1]) # dp数组最后一个房子抢或不抢的最大值
        # 时间复杂度：O(n)
        # 空间复杂度：O(n)
```
优化空间：
```python []
class Solution:
    def rob(self, nums: List[int]) -> int:
        yes, no = 0, 0
        for num in nums:
            yes, no = num + no, max(yes, no)
        return max(yes, no)
        # 时间复杂度：O(n)
        # 空间复杂度：O(1)
```