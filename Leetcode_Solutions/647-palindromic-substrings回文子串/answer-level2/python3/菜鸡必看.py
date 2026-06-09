### 解题思路
另外谁教下我二维数组怎么求和？
发现用sum()不行，然后for-loop又各种出错
我偷懒直接用的计数
有没有一句的那种 谢谢大佬了

### 代码

```python3
class Solution:
    def countSubstrings(self, s: str) -> int:
        n=len(s)
        f=[[0]*n for _ in range(n) ]
        # odd
        sum=0
        c=0
        for c in range(n) :
            i = j = c
            while i>=0 and j<n and s[i]==s[j] :
                f[i][j]=1
                sum+=1
                i-=1
                j+=1
        c=0
        for c in range(n-1) :
            i=c
            j=i+1
            while i>=0 and j<n and s[i]==s[j] :
                f[i][j]=1
                sum+=1
                i-=1
                j+=1

        return sum
```