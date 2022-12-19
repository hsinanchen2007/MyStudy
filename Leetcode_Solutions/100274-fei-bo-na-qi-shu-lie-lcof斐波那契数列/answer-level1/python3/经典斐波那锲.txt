### 解题思路
时间复杂度 O(N)

### 代码

```python3
class Solution:
    def fib(self, n: int) -> int:
        a,b = 0,1
        for i in range(n):
            b,a=a+b,b
        return a % 1000000007

```