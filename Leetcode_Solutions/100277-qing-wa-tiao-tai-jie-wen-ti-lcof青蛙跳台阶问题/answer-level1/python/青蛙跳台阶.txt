### 解题思路
此题的公式和斐波那契数列一样，差别在于起始值不同。
f(0) = 1, f(1) = 1

**但同样要注意需要把结果对1e9+7取模！！！**

### 代码

```python3
class Solution:
    def numWays(self, n: int) -> int:
        a,b = 1,1

        for _ in range(n):
            a,b = b, a+b
        
        return a % 1000000007
```