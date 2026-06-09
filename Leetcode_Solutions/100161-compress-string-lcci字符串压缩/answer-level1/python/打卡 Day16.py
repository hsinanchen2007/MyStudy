
### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        lens = len(S)
        if lens == 0 or lens == 1 or lens == 2:
            return S
        ans = S[0]
        n=1 
        for i in range(1,lens):
            if ans[-1] == S[i]:
                n+=1
            else:
                ans+=str(n)
                ans+=S[i]
                n=1
            if i == lens-1:
                ans+=str(n)
            if len(ans) >= lens:
                return S
        return ans
```