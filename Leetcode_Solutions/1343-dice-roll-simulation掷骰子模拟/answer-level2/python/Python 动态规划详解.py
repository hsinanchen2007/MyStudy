# ## 思路

# 用 `dp[i][j][k]` 表示第 `i` 轮掷骰子掷出数字 `j` 时 `j` 连续出现 `k` 次的组合数量。

# 那么有状态转移如下：

# **当 `j` 并非在连续出现时（即 `k == 1` 时）：**

# ```
// j 出现 1 次的组合数等于上一轮投出非数字 j 的所有情况和
dp[i][j][1] = sum(dp[i - 1][other != j][:])
# ```

# **当 `j` 连续出现 `k(k > 1)` 次时：**

# ```
if k <= rollMax[j]:
    // 本轮投出连续出现 k 次数字 j 的情况数量等于：上一轮连续投掷出 k - 1 次 j 的情况数量
    dp[i][j][k] = dp[i - 1][j][k - 1]
# ```

# ps：很多同学说测试用例是错的，可能是因为理解错题意了，题目说的是 **连续** 掷出数字 `i` 的次数不能超过 `rollMax[i]`，而不是数字的投掷总数。

# 具体实现：

# ```python
class Solution:
    def dieSimulator(self, n: int, rollMax: List[int]) -> int:
        dp = [[[0 for _ in range(16)] for _ in range(7)] for _ in range(n + 1)]
        mod = 10**9 + 7
                
        for i in range(1, n + 1):
            # 投掷的数
            for j in range(1, 7):
                # 第一次投掷
                if i == 1:
                    dp[i][j][1] = 1
                    continue
                
                # 数字 j 连续出现 k 次
                for k in range(2, rollMax[j - 1] + 1):
                    dp[i][j][k] = dp[i - 1][j][k - 1]
                    
                # 前一次投出的数不是 j
                s = 0
                for l in range(1, 7):
                    if l == j:
                        continue
                    for k in range(1, 16):
                        s += dp[i - 1][l][k]
                        s %= mod
                dp[i][j][1] = s
        
        res = 0
        for j in range(1, 7):
            for k in range(1, 16):
                # 求投掷 n 次时所有组合总和
                res += dp[n][j][k]
                res %= mod
                
        return res
# ```

# ----

# ## 🐱

# - 我的题解项目: [GitHub - leetcode-notebook](https://github.com/JalanJiang/leetcode-notebook)
# - 如果你对做题和分享题解感兴趣，欢迎加入 [LeetCode 刷题小分队](https://github.com/leetcode-notebook/leetcode-notebook.github.io/blob/master/README.md)
# - 如果你觉得题解写得不错，欢迎关注公众号「编程拯救世界」，公众号专注于编程基础与服务端研发，定期分享算法与数据结构干货~

# ![](https://pic.leetcode-cn.com/19e1d10a6d54a3e362ba5b7ad024a689720b30848e7e7b9e3ca971eae5ebd7b6-file_1574392293896)