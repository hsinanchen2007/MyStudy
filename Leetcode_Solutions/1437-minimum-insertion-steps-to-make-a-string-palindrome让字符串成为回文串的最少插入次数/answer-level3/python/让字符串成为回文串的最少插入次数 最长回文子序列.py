### 解题思路
直接贴评论区的一个说法, 讲得很好:

换个角度想:当前字符串要变成回文,那只要把不一样的找出来就好了.即:求出反过来的字符串和当前字符串的最长公共子序列,然后减一下.

如 : "ab" --> reverse  ---> "ba",
"ab"和"ba"的 最长公共子序列长度是 1, 即 len("ab") = 2,  2 - 1 = 1, 即 只要插入1个字母就好咯. "aba" 或者"bab".
如 leetcode 和 
     edocteel 的最长公共子序列是  e t e ,长度为3,  即 8-3 = 5.
把公共部分保持不变,其他的插过来,或者插过去,就一样啦!

1804 ms	15 MB
### 代码

```python3
class Solution:
    def minInsertions(self, s: str) -> int:
        l = len(s)
        if s == s[::-1]: # 加了这个快了6000ms ...
            return 0
        dp = [[0]*(l+1) for _ in range(l+1)]
        for i in range(1, l+1):
            for j in range(1, l+1):
                if s[i-1]==s[l-j]: dp[i][j] = dp[i-1][j-1]+1 # 如果相等,则最长回文子序列长度+1, 如果不相等, 看s[:i-1]与s[:j]的回文子序列和 s[:i]与s[:j-1]的哪个长
                else: dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        return l-dp[-1][-1]

```

另外可以学一下lura_cache的用法, 就不用自己写memo了
这里实际上是另一种dp的思路, 即定义区间
状态dp[i][j]：表示s[i...j]的最大回文子序列长度

状态转移方程：若s[i]==s[j],则dp[i][j]=dp[i+1][j-1]+2，表示若s[i]==s[j]相等，那么它们俩的长度加上 s[i+1..j-1] 中的最长回文子序列就是 s[i..j] 的最长回文子序列；若s[i]!=s[j]，则dp[i][j]=max(dp[i][j-1],dp[i+1][j])，表示若s[i]!=s[j]，那么把它们两分别加入 s[i+1..j-1] 中，看看哪个子串产生的回文子序列更长即可。

作者：xiaoneng
链接：https://leetcode-cn.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/solution/cdong-tai-gui-hua-xin-ping-zhuang-jiu-jiu-by-xiaon/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

1232 ms	250.3 MB 区=区间动态规划
```
    def minInsertions(self, s: str) -> int:
        from functools import lru_cache
        @lru_cache(300000) #显示的定义这么多还是要占不少内存
        def F(i, j):
            if i >= j:
                return 0
            if s[i] == s[j]:
                return F(i + 1, j - 1)
            return 1 + min(F(i + 1, j), F(i, j - 1)) # 为什么是min? -- 相当于在找最短非回文子序列
        return F(0, len(s) - 1) #返回的直接是最小插入长度
```
如上述思路中提到的内容，如果我们想知道区间 [left, right] 范围里的最优解，那么可能存在两种情况，即 s[left] === s[right] 或者 s[left] !== s[right]。针对这两种情况，我们可以得到两种对应的结果，即 **0 + **[left + 1, right - 1] 和 **1 + **min([left + 1, right], [left, right - 1])。如果写成一个递推公式的话可以是：

作者：poppinl
链接：https://leetcode-cn.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/solution/bao-bao-ye-neng-kan-dong-de-leetcode-ti-jie-dp-by-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。