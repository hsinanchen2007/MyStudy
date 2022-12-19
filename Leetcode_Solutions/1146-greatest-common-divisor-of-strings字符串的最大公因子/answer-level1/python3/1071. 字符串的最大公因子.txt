
__1. 结论__
虽然是一个easy级别的题，但从思考角度来看还是很值得一做，在没有看大佬们讨论和题解前，我最终的解题结论是用最大公约数的方法解答，
从串的最大公因子到最大公约数还挺有意思，这时候隐约有种感觉，其它类似求最大公XXX的题可能也能用求最大公约数的方法解答，求最小
公XXX可能能用求最小公倍数的方法求。嗯~~？可能是的


__2. 原理__
len1， len2 分别是输入的两个串的长度，假设两个串存在最大因子，则设最大公因子的长度为x
len1 = a*x
len2 = b*x

所以可以通过求len1， len2的最大公约数 求x
再用长度为x的子串验证即可

__3. 时空复杂度__
时间复杂度 O(max（len1, len2）)
空间复杂度 O(1)


__4.劣质代码实现__
```
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        len1 = len(str1)
        len2 = len(str2)
        gcd = self.gcd(len1, len2)
        j = 0
        for item in str1:
            if j == gcd:
                j = 0
            if str1[j] != item:
                return ""
            j += 1

        for item in str2:
            if j == gcd:
                j = 0
            if str1[j] != item:
                return ""
            j += 1

        return str1[:gcd]

    def gcd(self, num1, num2):
        """最大公约数"""
        while num2 > 0:
            t = num1 % num2
            num1 = num2
            num2 = t
        return num1
```

__5.总结__
最终提交结果不太理想，虽然在空间上还算可以，但是时间上不优，且也不知道分析是否有误，请广大朋友指正！^V^
