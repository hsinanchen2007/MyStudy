
![image.png](https://pic.leetcode-cn.com/3da8025e85df3888595db5549126af08acc94264dd0cc7f93d091dd86e4a3dcc-image.png)
```
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        """
            字符串相乘, 算法复杂度n的1.59次方

            给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，
            它们的乘积也表示为字符串形式。

            输入: num1 = "123", num2 = "456"
            输出: "56088"
        """
        if num1 == "0" or num2 == "0":
            return "0"
        n1, n2 = 0, 0
        t1, t2 = num1, num2 = int(num1), int(num2)
        while num1 >= 2:
            num1 >>= 1
            n1 += 1
        while num2 >= 2:
            num2 >>= 1
            n2 += 1

        k1, k2 = 1 << n1, 1 << n2
        r1, r2 = t1 & (k1 - 1), t2 & (k2 - 1)
        A, B, C, D = k1, r1, k2, r2
        return str(A * C + B * C + A * D + B * D)
```




![Karatsuba算法](https://pic.leetcode-cn.com/cd59653a9a36c81eb4d9ae1da9acbb142383fa4c826218fd9b2d331ab3838501-WechatIMG9.jpeg)
```
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        """
            字符串相乘, Karatsuba算法，n的1.58次方, https://zh.wikipedia.org/wiki/Karatsuba%E7%AE%97%E6%B3%95

            给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，
            它们的乘积也表示为字符串形式。

            输入: num1 = "123", num2 = "456"
            输出: "56088"
        """
        return str(self.karatsuba(num1, num2))

    def karatsuba(self, num1, num2):
        if not num1 or not num2:
            return 0
        n, m = len(num1), len(num2)
        if (n < 2) or (m < 2):
            return int(num1) * int(num2)

        maxLength = max(n, m)
        splitPosition = maxLength // 2
        high1, low1 = num1[:-splitPosition], num1[-splitPosition:]
        high2, low2 = num2[:-splitPosition], num2[-splitPosition:]
        z0 = self.karatsuba(low1, low2)
        z1 = self.karatsuba(str(int(low1) + int(high1 or "0")), str(int(low2) + int(high2 or "0")))
        z2 = self.karatsuba(high1, high2)

        return (z2 * 10 ** (2 * splitPosition)) + ((z1 - z2 - z0) * 10 ** (splitPosition)) + z0
```