## 思路:

数学题

令 $A = [x_0, x_1, x_2, ..., x_{n-1}]$

当 $k = 0$时，得到$F(0) = 0 * x_0 + 1 * x_1 + 2 *x_2 + (n -1) * x_{n-1}$

当 $K > 0$时，那么有

$F(k) = 0 * x_{n-k}  + 1* x_{n-k+1} + ... + (k - 1) * x_{n - 1} + (k)*x_0 + (k + 1) * x_1 + ... + (n - 1) * x_{n - k - 1}$

令 $k = k + 1$，

$F(k+1) = 0 * x_{n - k + 1} + 1 * x_{n-k} + ...+ (k)*x_{n - 1} + (k + 1)*x_0 + (k + 2)*x_1 + ...+ (n - 1) * x_{n - k -1}+ (n) * x_{n - k}$

我们有：$F(k + 1) - F(k) = x_{n-k} + ...x_{n-1} + x_0 + x_1 ... + x_{n-k-1} - n * x_{n-k}$

化简可得：

$F(k + 1) - F(k) = \sum_{i = 0}^{n-1}x_i - n * x_{n - k}$

所以，我们有 $F(k) = F(k - 1) + sum(A) - len(A) * A[len(A) - k]$   



## 代码:

```python
class Solution:
    def maxRotateFunction(self, A: List[int]) -> int:
        n = len(A)
        cur = sum(A[i] * i for i in range(n))
        _sum = sum(A)
        res = cur
        for i in range(1, n):
            cur = _sum - n * A[-i] + cur
            res = max(res, cur)
        return res
```

