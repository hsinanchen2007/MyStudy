### 解题思路
改了个顺序 不然又他娘的ot了

### 代码

```python3
class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        n=len(s)
        dp=[[1]*n for _ in range(n)]
        for i in range(n-1) :
            if s[i]==s[i+1]:
                dp[i][i+1]=2
        for k in range(2,n) :
        # 间隔1 2的已经初始化了
        # k是每次间隔 从3开始算  也就是aaab中的aaa 应该说连着三个
            for i in range(n-k) :
                j=i+k
                if s[i]==s[j]:
                    dp[i][j] = dp[i+1][j-1]+2
                else:
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1])
        return dp[0][n-1]


```