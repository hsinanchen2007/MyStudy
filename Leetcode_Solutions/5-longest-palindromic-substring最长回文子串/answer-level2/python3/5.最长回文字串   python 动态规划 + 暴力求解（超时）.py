### 解题思路
1.观察是否存在状态，例如 babab,可知aba是回文序列，那么可以看出babab也是回文序列，当b = b的时候
2.因此我们可以用二维数组来i,j表示回文串的起始和结尾索引位置。
3.状态转移方程dp[i,j] = dp[i+1][j-1] if s[i] == s[j] else False
4.接下来看有没有特殊的边界情况存在，我们发现当0<=j-i<3的时候，只要满足s[i] == s[j]，无论里面是什么dp[i,j]都会是回文字串,将这种情况分开讨论，当j-i>=3的时候，才进行状态转移。

**错误：**
   在动态规划提交成功后，我想试着优化一下，因为我想的是在j-i<3的情况下如果一个字符串是个回文序列，那么之内的是否就不用考虑，直接break,这样的话可以减少一定的循环次数，但提交后，发现对于重复的数来说，比如s = aaaa,那么判断s[0:2]是回文子串，将dp[0][1] = True ,但是对于s[1:2]并没有判断，也就是dp[1][2] == False 还是为真的，这样当j = 3，j-i ==3 的情况下，会进行状态转移，dp[0][3] = dp[1][2]，此时dp[0][3]会被赋值为False，导致最终的答案错误。
   因此，动态规划的过程依赖过去的状态会是连续的，过去的任何一个时刻的状态都要考虑到！
  

### 代码

```python
class Solution:
    def longestPalindrome(self, s: str) -> str:
        # 观察是否存在状态，例如 babab,可知aba是回文序列，那么可以看出babab也是回文序列，当b = b的时候
        # 因此我们可以用二维数组来i,j表示回文串的起始和结尾索引位置。
        # 状态转移方程dp[i,j] = dp[i+1][j-1] if s[i] == s[j] else False
        # 接下来看有没有特殊的边界情况存在，我们发现当0<=j-i<3的时候，只要满足s[i] == s[j]，无论里面是什么dp[i,j]都会是回文字串,将这种情况分开讨论，当j-i>=3的时候，进行状态转移
        # 初始值
        m = len(s)
        max_len = 1
        start_index = 0
        if m < 2:
            return s
        dp = [[False for _ in range(m)] for _ in range(m)]
        for j in range(1,m):
            for i in range(0,j):
                if s[i]  == s[j]:
                    if j-i < 3:
                        dp[i][j] = True
                    else:
                        dp[i][j] = dp[i+1][j-1]
                else:
                    dp[i][j] = False
                if dp[i][j]:
                    cur_len = j-i+1
                    if cur_len > max_len:
                        max_len = cur_len
                        start_index = i
        return s[start_index:start_index+max_len]

                

                        

```