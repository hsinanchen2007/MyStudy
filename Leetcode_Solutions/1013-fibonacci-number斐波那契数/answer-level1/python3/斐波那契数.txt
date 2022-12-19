### 解题思路
斐波那契数这个题不是本来就是考察递归的嘛。。。看了别的大佬的题解，也有使用逐步迭代的。

### 代码

```python3
class Solution:
    def fib(self, N: int) -> int:
        if N <= 1:
            return N
        else:
            return self.fib(N-1) + self.fib(N-2)

```