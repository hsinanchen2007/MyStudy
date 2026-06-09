### 解题思路
先预处理将分子分母，操作符放在一个list里面。
依此取出操作符和下一个分子分母，计算时先计算最小公倍数，然后+或者-
最后的结果再求一次最大公约数，约一下。

### 代码

```python3
class Solution:
    def fractionAddition(self, expression: str) -> str:
        # 预处理
        numerator = []
        denominator = []
        operators = []
        num_str = ""
        for c in expression:
            if c not in ["+", "-", "/"]:
                num_str += c
            else:
                if c in ["+", "-"]:

                    if num_str:
                        operators.append(c)
                        denominator.append(int(num_str))
                        num_str = ""
                    else:
                        num_str = c
                else:
                    if len(numerator) == len(denominator):
                        numerator.append(int(num_str))
                    else:
                        denominator.append(int(num_str))
                    num_str = ""
        denominator.append(int(num_str))
        res = [numerator.pop(0), denominator.pop(0)]
        while operators:
            op = operators.pop(0)
            next_num, next_deno = numerator.pop(0), denominator.pop(0)
            lcm = self.least_common_multiple(res[1], next_deno)
            if lcm != next_deno:
                next_num *= lcm / next_deno
                next_deno = lcm
            if res[1] != next_deno:
                res[0] *= lcm / res[1]
                res[1] = lcm
            if op == '+':
                res[0] += next_num
            else:
                res[0] -= next_num
        gcd = self.greatest_common_divisor(res[0], res[1])
        res[0] /= gcd
        res[1] /= gcd
        return "{}/{}".format(int(res[0]), int(res[1]))

    def least_common_multiple(self, x, y):
        # 最小公倍数
        return x * y / self.greatest_common_divisor(x, y)

    def greatest_common_divisor(self, x, y):
        # 辗转相除 求最大公约数
        while y != 0:
            x, y = y, x % y
        return x
```