# 题目问阶乘的结果有几个零，如果用笨方法求出阶乘然后再算 0 的个数会超出时间限制。

# 然后我们观察一下，5 的阶乘结果是 120，零的个数为 1：

# ```
5! = 5 * 4 * 3 * 2 * 1 = 120
# ```

# 末尾唯一的零来自于 `2 * 5`。很显然，如果需要产生零，阶乘中的数需要包含 2 和 5 这两个因子。

# 例如：`4 * 10 = 40` 也会产生零，因为 `4 * 10 = ( 2 * 2 ) * ( 2 * 5)` 。

# 因此，我们只要数一数组成阶乘的数中共有多少对 2 和 5 的组合即可。又因为 5 的个数一定比 2 少，问题简化为计算 5 的个数就可以了。

# ```python
class Solution(object):
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """
        
        res = 0
        
        while n >= 5:
            res += n // 5
            n //= 5
        
        return res
# ```

# ----

# ## 🐱

# - 我的题解项目: [GitHub - leetcode-notebook](https://github.com/JalanJiang/leetcode-notebook)
# - 如果你对做题和分享题解感兴趣，欢迎加入 [LeetCode 刷题小分队](https://github.com/leetcode-notebook/leetcode-notebook.github.io/blob/master/README.md)
# - 如果你觉得题解写得不错，欢迎关注公众号「编程拯救世界」，公众号专注于编程基础与服务端研发，定期分享算法与数据结构干货~

# ![](https://pic.leetcode-cn.com/19e1d10a6d54a3e362ba5b7ad024a689720b30848e7e7b9e3ca971eae5ebd7b6-file_1574392293896)