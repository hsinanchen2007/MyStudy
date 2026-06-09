### 代码

```python3
class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        S2=''
        T2=''
        for i in S:
            if i=='#':
                S2=S2[:-1]
            else:
                S2=S2+i
        for i in T:
            if i=='#':
                T2=T2[:-1]
            else:
                T2=T2+i
        return S2==T2
```