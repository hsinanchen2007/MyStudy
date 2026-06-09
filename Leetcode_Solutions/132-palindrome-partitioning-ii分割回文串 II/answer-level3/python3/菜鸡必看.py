### 解题思路
调用了一个函数 来判断[i][j]是否回文串
主要还是用的动态规划思想

### 代码

```python3
class Solution:
    def minCut(self, s: str) -> int:
        if len(s)<1 :
            return 0
        isPalin=self.calIsPalin(s)
        f=[float("inf")]*(len(s)+1)
        f[0]=0
        for i in range(1,len(s)+1 ) :
            f[i]=float("inf")
            for j in range(i) :
                if isPalin[j][i-1] :
                    f[i]=min(f[i],f[j]+1)
        return f[-1]-1
    def calIsPalin(self,s:str) :
            n=len(s)
            f=[[0]*n for _ in range(n) ]
            # odd
            c=0
            for c in range(n) :
                i = j = c
                while i>=0 and j<n and s[i]==s[j] :
                    f[i][j]=1
                    i-=1
                    j+=1
            c=0
            for c in range(n-1) :
                i=c
                j=i+1
                while i>=0 and j<n and s[i]==s[j] :
                    f[i][j]=1
                    i-=1
                    j+=1
            return f
        
```