### 解题思路
通过与运算的短路计算，注意and
### 代码

```python3
class Solution:
    def sumNums(self, n: int) -> int:
        def getsum(n):
            sum = n and n + getsum(n-1) 
            return sum
        return getsum(n)
```