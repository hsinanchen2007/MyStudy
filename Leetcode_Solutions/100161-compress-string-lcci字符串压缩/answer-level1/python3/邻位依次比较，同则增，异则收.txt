### 解题思路
邻位依次比较，同则增，异则收

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        n = len(S)
        if n == 0 or n == 1:
            return S
        final = ''
        acc = 1
        base = 0
        for i in range(1,n):
            if S[i] == S[i - 1]:
                acc += 1
            else:
                final = '%s%s%d'%(final, S[base], acc)
                acc = 1
                base = i
            if i == n - 1:
                final = '%s%s%d'%(final, S[base], acc)
        if len(final) >= n:
            return S 
        else:
            return final

```