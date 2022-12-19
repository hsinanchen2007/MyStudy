**思路1:** 递归(暴力), 超时

```
# 暴力法 超时 (通过 13/70 个测试用例)
class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        nums = [1] + nums
        nums.append(1)
        def helper(lst):
            if len(lst) == 3:
                return lst[1]
            mmax = 0
            for i in range(1, len(lst)  - 1):
                tmp = lst[i-1] * lst[i] * lst[i+1]
                mmax = max(mmax, tmp + helper(lst[:i] + lst[i+1:]))
            return mmax
        return helper(nums)
```

**思路2:** 动态规划

1. 预处理 nums = [1] + nums + [1], 给原数组首尾添加1, 并设新的数组大小为n
2. 状态dp[i][j] 表示删除nums[i+1,..., j-1]之后的最大值，我们的目标是求dp[0][n-1]
3. 状态转移方程 dp[i][j] = max{dp[i][k] + dp[k][j] + nums[i]\*nums[k]\*nums[j]}, i+1 <= k <= j-1
4. 填充dp的方式，反斜三角
5. 初始化 d[i][i+2] = nums[i] \* nums[i+1] \* nums[i+2]

程序如下:
```
class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        nums = [1] + nums + [1]
        n = len(nums)
        dp = [[0] * n for _ in range(n)]
        for step in range(2, n):
            for i in range(n):
                if step == 2:
                    if i + step < n:
                        dp[i][i+step] = nums[i] * nums[i+1] * nums[i+2]
                        #print(i, i + step, dp[i][i+step])
                    continue
                for k in range(i+1, i+step):
                    if i + step < n:
                        dp[i][i+step] = max(dp[i][k] + dp[k][i+step] + nums[i] * nums[k] * nums[i+step], dp[i][i+step])
                        #print(i, i + step, dp[i][i+step])
        return dp[0][n-1]
```
