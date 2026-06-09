# > 作者：[江不知](http://jalan.space)
# > 题解项目：[LeetCode Notebook](https://github.com/JalanJiang/leetcode-notebook)
# > 公众号：**编程拯救世界**（ID: CodeWarrior_）：专注于编程基础与服务端研发。

# ### 解一

# 调用函数懒蛋法。

# ```Python []
class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        return bin(n).count('1')
# ```

# ### 解二

# 手动循环计算 1 的个数。

# ```Python []
class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        n = bin(n)
        count = 0
        for c in n:
            if c == "1":
                count += 1
        return count  
# ```

# ### 解三

# 十进制转二进制的方式。每次对 2 取余判断是否是 1，是的话就 `count = count + 1`。

# ```Python []
class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        count = 0
        while n:
            res = n % 2
            if res == 1:
                count += 1
            n //= 2
        return count
# ```

# ### 解四

# 位运算法。

# 把 `n` 与 `1` 进行与运算，将得到 `n` 的最低位数字。因此可以取出最低位数，再将 `n` 右移一位。循环此步骤，直到 `n` 等于零。

# ```Python []
class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        count = 0
        while n:
            count += n&1
            n >>= 1
        return count
# ```

# ----

# ## 🐱

# - 我的题解项目: [GitHub - leetcode-notebook](https://github.com/JalanJiang/leetcode-notebook)
# - 如果你对做题和分享题解感兴趣，欢迎加入 [LeetCode 刷题小分队](https://github.com/leetcode-notebook/leetcode-notebook.github.io/blob/master/README.md)
# - 如果你觉得题解写得不错，欢迎关注公众号「编程拯救世界」，公众号专注于编程基础与服务端研发，定期分享算法与数据结构干货~

# ![](https://pic.leetcode-cn.com/19e1d10a6d54a3e362ba5b7ad024a689720b30848e7e7b9e3ca971eae5ebd7b6-file_1574392293896)