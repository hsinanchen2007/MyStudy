### 解题思路
找出质数的个数再找出非质数排列

### 代码

```python3
class Solution:
    def numPrimeArrangements(self, n: int) -> int:
        import math
        zhi = len([i for i in range(2,n+1) if 0 not in [i%d for d in range(2,int(i**0.5)+1)]])
        return math.factorial(zhi)*math.factorial(n-zhi)%1000000007
```