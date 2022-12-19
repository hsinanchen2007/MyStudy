### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def fib(self, n: int) -> int:
        if n == 0:
            return 0
        if n == 1 or n == 2:
            return 1

        tmp = 0
        sum_1 = 1
        sum_2 = 1
        for i in range(3, n+1):
            tmp = (sum_1 + sum_2)%1000000007
            sum_1 = sum_2
            sum_2 = tmp
        return tmp

```