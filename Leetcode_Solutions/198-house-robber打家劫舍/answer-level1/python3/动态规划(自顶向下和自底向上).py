## 思路：

动态规划

思路一：自顶向下

思路二：自底向上

动态方程：`dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1])`

大家有不清楚的地方，欢迎留言！

## 代码：

思路一：

```python
class Solution:
    def rob(self, nums: List[int]) -> int:
        import functools 
        n = len(nums)
        @functools.lru_cache(None)
        def helper(i):
            if i >= n: return 0
            return max(helper(i + 1), nums[i] + helper(i + 2))
        return helper(0)
```

思路二：

```python
class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0: return 0
        dp = [0] * (n + 1)
        dp[1] = nums[0]
        for i in  range(2,n + 1):
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1])
        return dp[-1]
        
```

