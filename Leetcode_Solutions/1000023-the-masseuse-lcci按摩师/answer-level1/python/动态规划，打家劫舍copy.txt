### 解题思路
![image.png](https://pic.leetcode-cn.com/d79081ec4a1727e061e25f88a6b2412319f875756f17c1a8c2485b9a1394073b-image.png)


### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        if not nums:
            return 0
        if len(nums) in [1, 2]:
            return max(nums)
        if len(nums) == 3:
            return max(nums[1], nums[0] + nums[2])
        
        dp = {}
        dp[0] = nums[0]
        dp[1] = max(nums[:2])
        dp[2] = max(nums[1], nums[0] + nums[2])

        for i in range(3, len(nums)):
            dp[i] = nums[i] + max(dp[i - 2], dp[i - 3])
        return max(dp[len(nums) - 2], dp[len(nums) - 1])
```