### 解题思路
主要找出数字组合，尤其是第一个分数可能是负数情况，因此正则用非贪婪选择处理字符串
reduce：真香，(((1+2)+3)+4)，每次将上次计算和传入第一个参数，这样累加即可
约分问题：通分分母用最小公倍数，分子相加即可，计算后还需要约分，找到分子分母最大公因素相除

### 代码

```python3
class Solution:
    def fractionAddition(self, expression: str) -> str:
        from re import findall
        from functools import reduce
        def gcd(a, b):
            while b:
                a, b = b, a % b
            return a
        def add(m, n):
            divide1, divisor1 = map(int,m.split('/'))
            divide2, divisor2 = map(int,n.split('/'))
            lcm = divisor1 * divisor2 // gcd(divisor1, divisor2)
            divide = divide1*(lcm//divisor1)+divide2*(lcm//divisor2)
            _gcd = gcd(divide, lcm)
            return f'{divide//_gcd}/{lcm//_gcd}'
        return reduce(add, findall('[+-]?\d+/\d+', expression))
```
![image.png](https://pic.leetcode-cn.com/145af0bb388cccf71093e1eb49ce7966be5beca4a39ee31fcaeb08b4a52faefd-image.png)

