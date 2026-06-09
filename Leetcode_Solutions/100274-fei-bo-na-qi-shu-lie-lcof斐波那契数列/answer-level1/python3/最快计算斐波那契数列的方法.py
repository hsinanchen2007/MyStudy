这是我最喜欢的计算斐波那契数列的方法，详见[Fast Fibonacci algorithms](https://www.nayuki.io/page/fast-fibonacci-algorithms)
这种方法基于如下的公式：
$$
 F(2k) = F(k) \left[ 2F(k+1) - F(k) \right] \\
 F(2k+1) = F(k+1)^2 + F(k)^2
$$
这种的计算方法的时间复杂度是 $\Theta(\log n)$
```python3
# returns F(n)
def fibonacci(n: int):  
    return _fib(n)[0]


# returns (F(n), F(n-1))
def _fib(n: int):
    if n == 0:
        # (F(0), F(1))
        return (0, 1)
    else:
        # F(2n) = F(n)[2F(n+1) − F(n)]
        # F(2n+1) = F(n+1)^2+F(n)^2
        a, b = _fib(n // 2)
        c = a * (b * 2 - a)
        d = a * a + b * b
        if n & 1:
            return (d, c + d)
        else:
            return (c, d)
```
