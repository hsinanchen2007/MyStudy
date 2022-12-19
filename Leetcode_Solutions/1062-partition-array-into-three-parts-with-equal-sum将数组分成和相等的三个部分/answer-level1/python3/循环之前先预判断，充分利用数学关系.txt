### 解题思路
循环之前先预判断，充分利用数学关系

### 代码

```python3
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        n = len(A)
        s = sum(A)
        s0 = s/3
        s1 = 0
        for i in range(0,n-2):
            s1 += A[i]
            if s0 != s1:
                continue
            s2 = 0
            for j in range(i+1,n-1):
                s2 += A[j]
                if s1 != s2:
                    continue
                return True 
        return False
```