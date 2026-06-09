### 解题思路
直接用两个变量模拟就行

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        if not S:
            return ''
        res=''
        t=S[0]
        c=1
        for i in range(1,len(S)):
            if S[i]==S[i-1]:
                c+=1
            else:
                res+=t+str(c)
                t=S[i]
                c=1
        res+=t+str(c)
        if len(res)<len(S):
            return res
        else:
            return S
```