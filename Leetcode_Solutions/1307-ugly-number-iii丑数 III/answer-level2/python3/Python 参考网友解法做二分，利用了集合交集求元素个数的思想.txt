![image.png](https://pic.leetcode-cn.com/3bfc5323f5809278ea1c7b18da1d2ce5e262c1aa5f8dd90cd652e1b8ac9f5904-image.png)


```
class Solution:

    # 最大公约数
    def gcd(self, a, b):
        if a > b:
            a, b = b, a

        while a > 0:
            a, b = b%a, a
        return b


    def minMul(self, a, b):
        gcd_val = self.gcd(a, b)
        return a * b // gcd_val

    # 获取数值num在丑数中的索引号
    def getIndex(self, num, a, b, c):
        ab_com_mul = self.minMul(a, b)
        bc_com_mul = self.minMul(b, c)
        ac_com_mul = self.minMul(a, c)
        abc_com_mul = self.minMul(ab_com_mul, ac_com_mul)

        # 集合交集元素个数计算方式
        return int(num // a + num // b + num // c - num // ab_com_mul - num // ac_com_mul \
                - num // bc_com_mul + num // abc_com_mul)

    def nthUglyNumber(self, n: int, a: int, b: int, c: int) -> int:
        l, r = 1, 1000000000 * 2
        while l <= r:
            mid = l + (r-l) // 2
            val = max(mid // a * a, mid // b * b, mid // c * c)
            idx = self.getIndex(val, a, b, c)
            if idx == n:
                return val

            if idx < n:
                l = mid + 1
            else:
                r = mid - 1
```
