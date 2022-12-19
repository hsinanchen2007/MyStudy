### 解题思路
感觉都格式化了
相对来说按i,j来跑确实容易写些
有个小坑就是|=


### 代码

```python3
class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if len(s3)!=len(s1)+len(s2) :
            return False
        m=len(s1)
        n=len(s2)
        dp=[[False]*(n+1) for _ in range(m+1)]
        dp[0][0]=True
        for i in range(m+1) :
            for j in range(n+1) :
                if(i>0 and s3[i+j-1]==s1[i-1]) :
                    dp[i][j] |= dp[i-1][j]
                if(j>0 and s3[i+j-1]==s2[j-1]) :
                    dp[i][j] |= dp[i][j-1]
        return dp[-1][-1]
```