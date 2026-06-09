### 解题思路
检验相邻数字的正负！

### 代码

```python3
class Solution:
    def isMonotonic(self, A: List[int]) -> bool:
        if not A:
            return
        if len(A)<=2:
            return True

        flag=A[1]-A[0]
        for i in range(1, len(A)):
            if (A[i]-A[i-1])*flag<0:
                return False
            if not flag:
                flag=A[i]-A[i-1]
        return True
```