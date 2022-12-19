### 解题思路
注意：
1、斐波那契数列
2、递归会超时
3、用循环计算，同时注意result=result%1000000007

### 代码

```python3
class Solution:
    def numWays(self, n: int) -> int:
        if n == 0:
            return 1
        if n in [1, 2]:
            return n
        a, b = 1, 2
        for i in range(n - 2):
            result = a + b
            a, b = b, result
        return result % 1000000007
```