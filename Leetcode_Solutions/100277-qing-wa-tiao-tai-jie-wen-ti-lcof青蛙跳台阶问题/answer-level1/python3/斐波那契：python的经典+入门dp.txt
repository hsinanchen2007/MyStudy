### 解题思路
经典的斐波那契数列（青蛙跳台阶）
这题蛮简单的哈 为了尽快运行用一下dynamic programming（因为递归实在是太慢了）
所以，我们用变量来存储下一次可能会用到的值，并且利用递归关系f_n = f_n-1 + f_n-2 (n ≥ 2)
注意Basic Case是n==0 与 n==1.

### 代码

```python3
class Solution:
    def numWays(self, n):
        if n == 0 or n == 1:
            return 1
        a = 1
        b = 1
        c = 0
        for i in range(2,n+1):
            c = a + b
            a = b
            b = b
        return f_n % 1000000007
```