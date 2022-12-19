回文子串比回文子序列还要麻烦些
判断最长回文子串和最长回文子序列都可以转化为
判断str 和 reverse str的最长公共子序列
但是前者还要判断
我们可以看到，当 SS 的其他部分中存在非回文子串的反向副本时，最长公共子串法就会失败。为了纠正这一点，每当我们找到最长的公共子串的候选项时，**都需要检查子串的索引是否与反向子串的原始索引相同**

比如 S="caba"，S'="abac" ，S’ 中 aba 的下标是 0 1 2 ，倒置前是 3 2 1，和 S 中 aba 的下标符合，所以 aba 就是我们需要找的。当然我们不需要每个字符都判断，我们只需要判断末尾字符就可以。

作者：windliang
链接：https://leetcode-cn.com/problems/longest-palindromic-substring/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-bao-gu/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

5640ms

```
class Solution:
    def longestPalindrome(self, s: str) -> str:
        l = len(s)
        if s == s[::-1]: # 不加这个无法过
            return s
        dp = [[0]*(l+1) for _ in range(l+1)]
        maxlen, preRv = 0, 0
        for i in range(1, l+1):
            for j in range(1, l+1):
                if s[i-1]==s[l-j]: 
                    dp[i][j] = dp[i-1][j-1]+1
                    if dp[i][j]>maxlen:
                        # 检查索引, 这个可以找个case推一下, 只需要判断回文子串最后一个字符就可以, 看其在reverse后的index+字串长度能不能对上reverse前的index. 因为j从1开始所以不用-1
                        if l-j+dp[i][j]==i: maxlen, preRv = dp[i][j], i
                else: dp[i][j] = 0     
        return s[preRv-maxlen:preRv]
```

当然对于回文子串(不是子序列!)比较好的方法还是中心扩展
256 ms
, 在所有 Python3 提交中击败了
89.04%
的用户
```
class Solution:
    def longestPalindrome(self, s: str) -> str:
        def solve(s, l, r):
            while l>=0 and r<len(s) and s[l]==s[r]:
                l -= 1
                r += 1
            return s[l+1:r]

        res = ''
        for i in range(len(s)):
            tmp = solve(s, i, i) # 子串长度为奇数, 中心为一个字符
            if len(tmp)>len(res):
                res = tmp
            tmp = solve(s, i, i+1) # 字串长度为偶数, 中心为两个字符
            if len(tmp)>len(res):
                res = tmp
        return res
        
```