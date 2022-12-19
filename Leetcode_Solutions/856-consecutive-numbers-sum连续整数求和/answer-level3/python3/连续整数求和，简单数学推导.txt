**思路**

设连续正整数为p到q，则N满足下式

$$
N = \sum_{i=1}^pi - \sum_{i=1}^qi = \frac{p(p+1)}{2} - \frac{q(q+1)}{2} \\
$$

能推出：

$$
(q-p)(q+p+1) = 2N
$$

设 a = q-p , b = q+p+1，则a,b为2N的因子， 有

$$
b+a= 2*q+1 \\
b-a= 2*p+1 
$$
可以发现a,b必须一个为奇数一个为偶数，又a,b为2N的因子，故此题实质是求2N的所有因子，且`2N/因子`与`因子`满足一奇一偶关系。



**代码**

```python 
import math

class Solution:

    def consecutiveNumbersSum(self, N: int) -> int:
        cnt = 0
        for a in range(1, math.ceil(math.sqrt(2*N))):
            # 下面语句意为 2*N 除以 a 得 b 余 c
            b, c = divmod(2*N, a)
            # 余数为0时，a,b才是因子
            if c == 0:
                # a,b一奇一偶满足条件
                if (a % 2 == 0 and b % 2 == 1) or (a % 2 == 1 and b % 2 == 0):
                    cnt += 1
        return cnt
