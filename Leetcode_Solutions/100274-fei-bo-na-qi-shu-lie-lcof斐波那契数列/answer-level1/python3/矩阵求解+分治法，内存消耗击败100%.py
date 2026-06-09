### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def fib(self, n: int) -> int:
        if n == 0:
            return 0

        def metric(n):
            base = [[1, 1], [1, 0]]
            # 求 pow(base, n)

            if n == 1:
                return base
            elif n % 2 == 0:
                half = metric(n//2)
                return metric_product(half, half)
            else:
                half = metric(n//2)
                return metric_product(metric_product(half, half), base)
        def metric_product(x, base):
            a = x[0][0]*base[0][0] + x[0][1]*base[1][0]
            b = x[0][0]*base[0][1] + x[0][1]*base[1][1]
            c = x[1][0]*base[0][0] + x[1][1]*base[1][0]
            d = x[1][0]*base[0][1] + x[1][1]*base[1][1]
            return [[a, b], [c, d]]

        ans = metric(n)
        f_n = ans[0][1]
        print(f_n)
        return f_n % 1000000007
        
        
        
```