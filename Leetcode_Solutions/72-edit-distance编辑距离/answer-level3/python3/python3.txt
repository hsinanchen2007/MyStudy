### 解题思路
转移方程dp[i][j]=min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])(如果word1[i]!=word2[j])
否则 dp[i][j]=dp[i-1][j-1]

### 代码

```python3
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        
        len1=len(word1)
        len2=len(word2)
        if len1*len2==0:
            return len1+len2
            
        dp=[[0]*(len1+1) for _ in range(len2+1)]
        for i in range(1,len1+1):
            dp[0][i]=i
        for i in range(1,len2+1):
            dp[i][0]=i
        for  i in range(1,len2+1):
            for j in range(1,len1+1):
                if word1[j-1]==word2[i-1]:
                    dp[i][j]=dp[i-1][j-1]
                else:
                    dp[i][j]=min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1
        return dp[-1][-1]
```

        
