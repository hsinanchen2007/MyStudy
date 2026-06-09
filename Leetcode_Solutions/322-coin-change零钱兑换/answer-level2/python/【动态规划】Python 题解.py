# 比较典型的动态规划问题。

# 假设 `f(n)` 代表要凑齐金额为 n 所要用的最少硬币数量，那么有：

# ```lisp
f(n) = min(f(n - c1), f(n - c2), ... f(n - cn)) + 1
# ```

# 其中 `c1 ~ cn` 为硬币的所有面额。

# ----

# 再具体解释一下这个公式吧，例如这个示例：

# ```angelscript
输入: coins = [1, 2, 5], amount = 11
输出: 3 
解释: 11 = 5 + 5 + 1
# ```

# 题目求的值为 `f(11)`，第一次选择硬币时我们有三种选择。

# 假设我们取面额为 1 的硬币，那么接下来需要凑齐的总金额变为 `11 - 1 = 10`，即 `f(11) = f(10) + 1`，这里的 `+1` 就是我们取出的面额为 1 的硬币。

# 同理，如果取面额为 2 或面额为 5 的硬币可以得到：

# - `f(11) = f(9) + 1`
# - `f(11) = f(6) + 1`

# 所以：

# ```lisp
f(11) = min(f(10), f(9), f(6)) + 1
# ```

# Python 代码：

# ```python
class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        res = [0 for _ in range(amount + 1)]
        
        for i in range(1, amount + 1):
            cost = float('inf')
            for c in coins:
                if i - c >= 0:
                    cost = min(cost, res[i - c] + 1)
            res[i] = cost
        
        if res[amount] == float('inf'):
            return -1
        else:
            return res[amount]
# ```

# ----

# ## 🐱

# - 我的题解项目: [GitHub - leetcode-notebook](https://github.com/JalanJiang/leetcode-notebook)
# - 如果你对做题和分享题解感兴趣，欢迎加入 [LeetCode 刷题小分队](https://github.com/leetcode-notebook/leetcode-notebook.github.io/blob/master/README.md)
# - 如果你觉得题解写得不错，欢迎关注公众号「编程拯救世界」，公众号专注于编程基础与服务端研发，定期分享算法与数据结构干货~
