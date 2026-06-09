

### 代码

```python3
class Solution:
    def countAndSay(self, n: int) -> str:
        if n==1:
            return '1'
        dp=['0' for i in range(n)]
        dp[0]='1'
        dp[1]='11'
        def count(s):
            m=[]
            n=[]
            for i in range(len(s)):
                if s[i] not in n:
                    if n!=[]:
                        m.append(n)
                        n=[]
                n.append(s[i])
                if i==len(s)-1:
                    m.append(n)
            t=''
            for i in m:
                t+=str(len(i))+i[0]
            return t
        for i in range(2,n):
            dp[i]=count((dp[i-1]))
        return dp[n-1]
```