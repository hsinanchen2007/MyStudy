### 解题思路
直接看代码把

### 代码

```python3
class Solution:
    def isArmstrong(self, N: int) -> bool:
        s=str(N)
        k=len(s)
        res=0
        for i in s:
            res+=int(i)**k
        return res==N
```