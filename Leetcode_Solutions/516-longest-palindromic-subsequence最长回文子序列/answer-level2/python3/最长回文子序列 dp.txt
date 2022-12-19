### 解题思路
最长回文子序列反而比最长回文子串要简单些 (第5题)
可以直接用状态转移就完事
不用判断子串的index是否能对上
执行用时 :
1400 ms
, 在所有 Python3 提交中击败了
85.44%
的用户

dp[i][j]代表str前i位和reverse str前j位的最长回文子序列长度
### 代码

```python3
class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        l = len(s)
        if s == s[::-1]: # 加了这个快了6000ms ...
            return l
        dp = [[0]*(l+1) for _ in range(l+1)]
        for i in range(1, l+1):
            for j in range(1, l+1):
                if s[i-1]==s[l-j]: dp[i][j] = dp[i-1][j-1]+1 # 如果相等,则最长回文子序列长度+1, 如果不相等, 看s[:i-1]与s[:j]的回文子序列和 s[:i]与s[:j-1]的哪个长
                else: dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        return dp[-1][-1]
```

实际上一种更好的理解是
我们说这个问题对 dp 数组的定义是：在子串 s[i..j] 中，最长回文子序列的长度为 dp[i][j]。**相当于定义区间, 312戳气球的dp定义也是这个思想**

为啥这个问题要这样定义二维的 dp 数组呢？我们前文多次提到，找状态转移需要归纳思维，说白了就是如何从已知的结果推出未知的部分，这样定义容易归纳，容易发现状态转移关系。

具体来说，如果我们想求 dp[i][j]，假设你知道了子问题 dp[i+1][j-1] 的结果（s[i+1..j-1] 中最长回文子序列的长度），你是否能想办法算出 dp[i][j] 的值（s[i..j] 中，最长回文子序列的长度）呢？
可以！这取决于 s[i] 和 s[j] 的字符：
如果它俩相等，那么它俩加上 s[i+1..j-1] 中的最长回文子序列就是 s[i..j] 的最长回文子序列：
如果它俩不相等，说明它俩不可能同时出现在 s[i..j] 的最长回文子序列中，那么把它俩分别加入 s[i+1..j-1] 中，看看哪个子串产生的回文子序列更长即可：

作者：labuladong
链接：https://leetcode-cn.com/problems/longest-palindromic-subsequence/solution/zi-xu-lie-wen-ti-tong-yong-si-lu-zui-chang-hui-wen/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。