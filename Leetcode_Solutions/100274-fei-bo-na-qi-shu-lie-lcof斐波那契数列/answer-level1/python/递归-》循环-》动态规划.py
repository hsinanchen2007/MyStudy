### 解题思路
递归超时，改用循环

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

###换成动态规划的思维，存一个数组，用空间换取时间

