动态规划

思路1：自顶向下

```python
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        from functools import lru_cache
        nums.sort(reverse=True)
        avg, mod = divmod(sum(nums), 2)
        # 不能被2整除
        if mod != 0: return False
        
        @lru_cache(None)
        def dfs(i, cur):
            if cur == 0: return True
            if i >= len(nums) or cur < 0: return False
            if dfs(i + 1, cur - nums[i]): return True
            if dfs(i + 1, cur): return True
        
        return dfs(0, avg)
```

思路2：自底向上

0/1 背包问题 , 可以百度 背包九讲 学习

```python
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        avg, mod = divmod(sum(nums), 2)
        # 不能被2整除
        if mod != 0: return False
        n = len(nums)
        
        dp = [[1] + [0] * avg for _ in range(n + 1)]
        for i in range(1, n + 1):
            for j in range(1, avg + 1):
                if j - nums[i - 1] >= 0:
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] | dp[i - 1][j]
        
        return dp[-1][-1]
```

优化为 空间为 $O(n)$

```python
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        avg, mod = divmod(sum(nums), 2)
        # 不能被2整除
        if mod != 0: return False
        n = len(nums)
        
        dp = [1] + [0] * avg 
        for i in range(1, n + 1):
            for j in range(avg, -1, -1):
                if j - nums[i - 1] >= 0:
                    dp[j] |= dp[j - nums[i - 1]] 
        
        return dp[-1]
```

