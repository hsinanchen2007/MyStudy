满足奖励条件的情况可以分解为如下6种不重叠情况个数的和： 
- a 不含A的LL结尾;
- b 不含A的L结尾, 且倒数第二位不为L;
- c 不含A的非L结尾;
- d 含A的LL结尾;
- e 含A的L结尾，且倒数第二位不为L;
- f 含A的非L结尾;

```
class Solution:
    def checkRecord(self, n):
        a, b, c, d, e, f = 0, 1, 1, 0, 0, 1
        for k in range(n):
            a, b, c = b, c, (a + b + c) % 1000000007
            d, e, f = e, f, (d + e + f + c) % 1000000007
        return f
```
时间 O(n), 空间 O(1)
如果用快速矩阵幂可以将时间降为 O(log n)