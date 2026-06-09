# ### 解题思路
# 既然记不住KMP中的next数组，还何必难为自己。
# 从“确定有限状态机”角度理解next数组：请移步👉[动态规划之 KMP 算法详解](https://leetcode-cn.com/problems/implement-strstr/solution/kmp-suan-fa-xiang-jie-by-labuladong/) ---[labuladong](https://leetcode-cn.com/u/labuladong/)

# ![image.png](https://pic.leetcode-cn.com/81e250db2994305ecea7bdb9b6ac9a6c8d359c72de8c0ffb66ee24286277032c-image.png)

# ### 代码

# ```python3
class Solution:
    def longestPrefix(self, s: str) -> str:
        if len(s) <= 1:return ""
        n = len(s)
        dp = [[0] * 26 for _ in range(n)]
        dp[0][ord(s[0])-97],shadow = 1,0
        for i in range(1,n):
            for j in range(0,26):
                dp[i][j] = dp[shadow][j]
            dp[i][ord(s[i])-97] = i + 1
            shadow = dp[shadow][ord(s[i])-97]
        return s[:shadow]



# ```