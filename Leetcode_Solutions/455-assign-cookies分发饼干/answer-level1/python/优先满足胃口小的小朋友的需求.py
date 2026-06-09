# 贪心问题。**优先满足胃口小的小朋友的需求**。

# 1. 对 `g` 和 `s` 升序排序
# 2. 初始化两个指针 `i` 和 `j` 分别指向 `g` 和 `s` 初始位置
# 3. 对比 `g[i]` 和 `s[j]`
#     - `g[i] <= s[j]`：饼干满足胃口，把能满足的孩子数量加 1，并移动指针 `i = i + 1`，`j = j + 1`
#     - `g[i] > s[j]`：无法满足胃口，`j` 右移，继续查看下一块饼干是否可以满足胃口

# ```python
class Solution(object):
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        res = 0
        g.sort()
        s.sort()
        
        g_length = len(g)
        s_length = len(s)
        
        i = 0
        j = 0
        while i < g_length and j < s_length:
            if g[i] <= s[j]:
                # 可以满足胃口，把小饼干喂给小朋友
                res += 1
                i += 1
                j += 1
            else:
                # 不满足胃口，查看下一块小饼干
                j += 1
                
        return res
# ```

# ----

# ## 🐱

# - 我的题解项目: [GitHub - leetcode-notebook](https://github.com/JalanJiang/leetcode-notebook)
# - 如果你对做题和分享题解感兴趣，欢迎加入 [LeetCode 刷题小分队](https://github.com/leetcode-notebook/leetcode-notebook.github.io/blob/master/README.md)
# - 如果你觉得题解写得不错，欢迎关注公众号「编程拯救世界」，公众号专注于编程基础与服务端研发，定期分享算法与数据结构干货~

# ![](https://pic.leetcode-cn.com/19e1d10a6d54a3e362ba5b7ad024a689720b30848e7e7b9e3ca971eae5ebd7b6-file_1574392293896)