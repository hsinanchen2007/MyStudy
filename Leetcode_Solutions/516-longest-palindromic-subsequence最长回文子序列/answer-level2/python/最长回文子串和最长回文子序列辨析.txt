### 解题思路
如果大家做了题五：最长回文子串的话，相信对这个题目有很深刻的理解，这个题目的区别在于它要求的子序列不
要求是连续的；我们要明确的一个点就是，我们动态规划基本上都是自底向上的，这也就是我们状态转移方程的目的：从前一状态推后一状态，而这两个题目的区别就是这个状态的继承关系，对于连续的字串而言，如果前一状态不为回文串，会连带着后面的状态也不为回文串，对于不连续的子序列而言，举个例子，字符串"abbc"，对于其中的字串"bb"而言，明显最长的回文串就是"bb",而对于"abbc"而言，最长的字符串依然为"bb"，换而言之，这个不连续可以让我们继承它的字串的最长回文序列，我们定义dp[i][j]为区间(i,j)中的最大回文子序列。
##最长回文子串
在最大回文子串中，我们的动态规划转移方程为if str[i]==str[j]:dp[i][j]=dp[i+1][j-1],
else dp[i][j]=False, 然后求使得区间最大i，j，这个的含义是，由于我要求的子串是连续的，如果遇到字符串str[i]!=str[j],那它肯定不是最大回文子串，例如"bacb",当"b"=="b"时，由于"ac"不是回文串，那么连带着"bacb"就不是回文串，尽管"b"=="b"。
##最长回文子序列
以例子字符串"abbc"而言，当"a"!="c"时，即str[i]!=str[j],这时候两端的字符无法对这个最长的回文序列做出贡献，那么我们要继承它的子序列的最长回文序列，即if str[i]!=str[j] ,dp[i][j]=max(dp[i+1][j],dp[i][j-1]),这时候我们要怀疑这个dp[i+1][j]和dp[i][j-1]是否能代表这个子序列的最大回文序列，其实不需要怀疑，因为我们动态规划是自底向上，之前的状态dp[i+1][j]和dp[i][j-1]，无疑是从下面推上来的最优结构(区间(i+1,j)和区间(i,j-1)序列中的最大回文系列)
##总结
这题和最长回文字串的区别就是，它不要求求出的值是连续的，这就意味着当左右两端的字符串无法为提高最长回文串的长度时，我们可以继承它的字串的最大回文串长度，而最长回文串不行。
### 代码

```python
class Solution(object):
    def longestPalindromeSubseq(self, string):
        """
        :type s: str
        :rtype: int
        """
        array=[[0]*len(string) for i in range(len(string))]
        for i in range(len(string)):
            array[i][i]=1
        for i in range(len(string),-1,-1):
            for j in range(i+1,len(string)):
                if string[i]==string[j]:
                    array[i][j]=array[i+1][j-1]+2
                else:
                    array[i][j]=max(array[i+1][j],array[i][j-1])
        return max(max(array))
```