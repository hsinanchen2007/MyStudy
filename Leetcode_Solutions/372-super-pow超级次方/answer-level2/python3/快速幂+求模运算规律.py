由于给出的 `b` 是一个十进制数组，所以我们将指数按照位数拆分即可：

$$6^{1325}=6^{1000}\times 6^{300}\times 6^{20} \times 6^5$$

可以仿照快速幂的思路，在累乘的时候十倍增即可：

$$6^1 \\ (6^1)^{10} \times 6^3 \\ ((6^1)^{10} \times 6^3)^{10} \times 6^{2} \\ (((6^1)^{10} \times 6^3)^{10} \times 6^{2})^{10} \times 6^5$$

然后在求得时候，每一个累乘的乘子 mod 1337 维护结果求得答案。

```python
class Solution:
    def qpow(self, x, n, m):
        ans = 1
        while n > 0:
            if n & 1 == 1:
                ans = ans * x % m
            x = x * x % m     
            n >>= 1
        return ans    
        
    def superPow(self, a: int, b: List[int]) -> int:
        res = 1
        for i in b:
            res = self.qpow(res, 10, 1337) * self.qpow(a, i, 1337)
        return res % 1337
```