![三步问题.png](https://pic.leetcode-cn.com/e348055c847c8b5418875af0fbd60c5faa205d58eb8b5c984ca76b0c6c2cc1b2-%E4%B8%89%E6%AD%A5%E9%97%AE%E9%A2%98.png)

借鉴这位老哥的回答↓ [@Ai6jgmdfab](/u/Ai6jgmdfab/)
这道题次要考察动态规划，主要是考察为什么可以在过程中取模而不影响最终结果，（python）只在最终return的结果上取模就超时了
状态转移方程不用说了：S(n) = S(n-1)+S(n-2)+S(n-3)
因为要对结果S(n)取模，用S(n)'代S(n)取模的结果，即 if S(n) > 1000000007: S(n)'= S(n) - n*1000000007   
于是如果对S(n+1)取模有：S(n+1) = S(n) + S(n-1) + S(n-2) = S(n)' + n*1000000007 + S(n-1) + S(n-2)
S(n+1) % 1000000007 = ( S(n)' + S(n-1) + S(n-2) ) % 1000000007
所以即使在中间取模也不影响结果
```
class Solution(object):
    def waysToStep(self, n):
        # S(n) = S(n-1)+S(n-2)+S(n-3)
        if n==0:
            return 0
        if n==1:
            return 1
        if n==2:
            return 2
        if n==3:
            return 4
        s_3,s_2,s_1 = 1,2,4
        for i in range(n-3):
            s_0 = (s_3+s_2+s_1) % 1000000007
            s_3,s_2,s_1 =s_2,s_1,s_0
        return s_0
```
