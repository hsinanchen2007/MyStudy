### 解题思路
此处撰写解题思路

### 代码

```python
class Solution:
    def printNumbers(self, n: int) -> List[int]:
        # 1:直接导入pow
        # import math
        # N = math.pow(10,n)

        # 2:python自带**用法
        # N = 10**n

        # 3:快速幂a^n,O(logn)
        # N = 1
        # a = 10
        # while n > 0:            
        #     if n%2 == 1:
        #         N *= a
        #     n //= 2
        #     a *= a

        # 4不用快速幂，单纯想看一下时间
        N = 1
        for i in range(n):
            N *= 10
        ans = []
        for i in range(1, int(N)):
            ans.append(i)
        return ans    
```