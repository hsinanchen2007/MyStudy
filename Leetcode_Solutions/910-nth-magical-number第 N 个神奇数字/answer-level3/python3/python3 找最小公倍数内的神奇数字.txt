### 解题思路
注意几个点
1、最小公倍数x最大公约数  = AxB
2、最小公倍数内的神奇数字个数为 lcm / A + lcm / B - 1
3、神奇数字以最小公倍数为周期

### 代码

```python3
from math import gcd
class Solution:
    def nthMagicalNumber(self, N: int, A: int, B: int) -> int:
        #这种数字是有规律的，找不到规律就做不出来
        #先找到最小公倍数之内的所有神奇数字
        MOD = 10 ** 9+7
        lcm = int(A * B /gcd(A,B))
        n = int(lcm / A + lcm / B - 1) #最小公倍数之内神奇数字的个数
        #应该把这些数字都找出来
        num_set = [lcm]
        i = 1
        while len(num_set) < n:
            if A * i < lcm:
                num_set.append(A*i)
            if B * i < lcm:
                num_set.append(B*i)
            i += 1
        num_set = sorted(num_set)
        k,v = divmod(N-1,n)
        res = k * lcm + num_set[v]
        return int(res % MOD)
```