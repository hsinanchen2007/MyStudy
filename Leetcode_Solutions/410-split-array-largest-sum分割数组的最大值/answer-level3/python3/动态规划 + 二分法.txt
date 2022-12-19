
## 思路:

刚看这题，有点像[1335. 工作计划的最低难度](https://leetcode-cn.com/problems/minimum-difficulty-of-a-job-schedule/)

思路一：动态规划

用自顶向下方法好做

```python
class Solution:
    def splitArray(self, nums: List[int], m: int) -> int:
        from functools import lru_cache
        n = len(nums)

        @lru_cache(None)
        def dfs(i, k):
            if k == 1:
                return sum(nums[i:])
            res = float("inf")
            cur = 0
            for j in range(i, n):
                cur += nums[j]
                # 关键
                if res <= cur:
                    break
                res = min(res, max(cur, dfs(j + 1, k - 1)))
            return res

        return dfs(0, m)
```


思路二：二分法

```python
class Solution:
    def splitArray(self, nums: List[int], m: int) -> int:
        left = max(nums)
        right = sum(nums)
        
        def helper(mid):
            cur = 0
            res = 1
            for num in nums:
                cur += num 
                if cur > mid:
                    res += 1
                    cur = num 
            return res 
        
        while left < right:
            mid = (left + right) // 2
            if helper(mid) > m:
                left = mid + 1
            else:
                right = mid
        return left
```

当然还可以优化！
顺便上面那个题也做一下，一样的

