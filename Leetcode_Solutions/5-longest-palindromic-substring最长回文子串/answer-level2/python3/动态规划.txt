### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:

    def longestPalindrome(self, s: str) -> str:
            #暴力法
        '''
        if s==s[::-1]:
            return s
        n=len(s)
        maxlen=1
        res=s[0]
        for i in range(n-1):
            for j in range(i,n):
                if j-i+1>maxlen and s[i:j+1]==s[i:j+1][::-1]:
                    maxlen=j-i+1
                    res=s[i:j+1]
        return res
        '''
                #动态规划，返回j-i+1最大的值
        n=len(s)
        dp=[[0]*n for _ in range(n)]#定义为s[i:j]是否为回文子串
        res=""
        for i in range(n-1,-1,-1):
            for j in range(i,n):
                dp[i][j]= s[i]==s[j] and (j-i<2 or dp[i+1][j-1])
                if dp[i][j] and j-i+1 >len(res):
                    res=s[i:j+1]
        return res

```