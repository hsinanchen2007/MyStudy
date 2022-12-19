### 解题思路
回溯法44ms，12.7mb 动态规划872ms，21.4mb
回溯法：
当第一次出现星号时它可能对应从0开始的多个元素，所以我从对应0个元素开始去假设（即i不变，j+1，而且此时用match_i,back_j去mantain当前的i与j的位置），一点点去试，如果当前探索元素不对应，则回到最开始出现星号的位置，再假设对应1个元素（即match_i += 1 ，i = match_i），一点点去试，直至出现第二个星号（此时对前一个星号的假设完全成立，更新此时的match_i,back_j）或者在这种假设下一直成功探索到s的最后一个元素为止。
循环结束时s探索完毕，但p不一定探索完毕，当此时s中没有元素再能与p剩下的元素相对应，除非p剩下的全是星号，否则不能匹配。




### 代码

```python
class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        i = j = 0  # i,j两个索引分别指向s,p
        back_j = -1  #记录最近一次星号出现的位置
        match_i = 0  #match_i前面的元素即0到match_i-1的元素一定匹配，match_i与之后的元素可能匹配
        ls = len(s)
        lp = len(p)
        while i < ls:
            if j < lp and (s[i] == p[j] or p[j] == '?'):  
                i += 1
                j += 1
            elif j < lp and p[j] == '*':  
                back_j = j  
                match_i = i  
                j += 1  
            elif back_j != -1:  
                j = back_j + 1
                match_i += 1  
                i = match_i
            else:  
                return False
        return list(p[j:]).count('*') == len(p[j:]) 



    def isMatch(self, s: str, p: str) -> bool:
        s = [x for x in s]
        s.insert(0, '')
        p = [x for x in p]
        p.insert(0, '')
        m = len(s)
        n = len(p)
        dp = [[False for _ in range(n)] for _ in range(m)]
        dp[0][0] = True
        for i in range(1, n):
            if p[i] == '*':
                dp[0][i] = dp[0][i-1]
        for i in range(1, m):
            for j in range(1, n):
                if s[i] == p[j] or p[j] == '?':
                    dp[i][j] = dp[i-1][j-1]
                elif p[j] == '*':  # 仔细考虑
                    dp[i][j] = (dp[i][j-1] or dp[i-1][j])
        return dp[-1][-1]
```