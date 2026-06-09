```
# -*- coding: utf-8 -*-

# Author: Cynthia

"""
    题目分析: 不用乘号, 除号, 模运算符计算两个数的商, 32位整数范围
    比如 100/3=33...1, 7/-3=-2...1, -7/-3=2...-1
    思路: 回忆一下十进制除法是怎么算的
       33
    3|100   从左边开始, 找到第一个大于等于3的位置, 开始除, 然后100-3*3*10=10
       9    当然, 也可以理解是100/(3*10**1), 得到的3*10**1(另一种思路, 除数左移)

    二进制思路同理, 而且更简单, 因为但凡能除得起, 这一位的商的值肯定是1(没有2,3,4等其他取值)
          10
    101|101011   注意看这里的规律, 商的1是左移3位, 算1011的时候相当于:
        101      101011-1*(101 << 3)
          0011   还要注意, 处理左移2的时候, 被除数已经是11了, 商计0, 没必要再来
                 一次 11-0*(101 << 2)
"""
"""
    先不考虑计算过程中的溢出, 都转化成正数去算
    方法1, 右移被除数
"""


class Solution:

    def divide(self, dividend: int, divisor: int) -> int:

        # 如果被除数和除数符号不一致, 则flag为True
        flag = (dividend >= 0) ^ (divisor >= 0)
        dividend, divisor = abs(dividend), abs(divisor)

        d, count = dividend, 0
        while d >= divisor:
            d, count = d >> 1, count+1

        # count多移了一位, 这里要-1
        # count的意义为: 100右移1位可以去除以3
        count -= 1

        result = 0
        while count >= 0:

            d = dividend >> count
            if d >= divisor:
                result += 1 << count
                dividend -= divisor << count
            count -= 1

        return -result if flag else 2**31-1 if result >= 2**31 else result


s = Solution()
print(s.divide(10, 3))

```

```
# -*- coding: utf-8 -*-

# Author: Cynthia

"""
    先不考虑计算过程中的溢出, 都转化成正数去算
    方法2, 左移被除数, 好处是不会损失精度
       3            3
    3|100  ->  30|100
"""


class Solution:

    def divide(self, dividend: int, divisor: int) -> int:

        flag = (dividend >= 0) ^ (divisor >= 0)
        dividend, divisor = abs(dividend), abs(divisor)

        count = 0
        while dividend >= divisor:
            divisor <<= 1
            count += 1
        divisor >>= 1
        count -= 1

        result = 0
        while count >= 0:

            if dividend >= divisor:
                result += 1 << count
                dividend -= divisor
            divisor >>= 1
            count -= 1

        return -result if flag else 2**31-1 if result >= 2**31 else result


s = Solution()
print(s.divide(10, 3))

```
```
# -*- coding: utf-8 -*-

# Author: Cynthia

"""
    方法3, 考虑计算过程中的溢出
    本来想用负数计算的, 但是负数的位移运算搞不太明白, 还是先进行特例预处理吧
"""


class Solution:

    def divide(self, dividend: int, divisor: int) -> int:

        # 结果溢出: -2**31/(-1); 取正溢出: -2**31
        # 另外, 算count的时候, 需要右移dividend而不能左移divisor, 不然也可能溢出
        MAX_INT, MIN_INT = 2**31-1, -2**31
        FLAG = (dividend >= 0) ^ (divisor >= 0)

        # 处理除数取正溢出, 处理完之后可以确保除数不为MIN_INT
        if divisor == MIN_INT:
            if dividend == MIN_INT:
                return 1
            else:
                return 0

        # 处理结果溢出及被除数取正溢出
        if dividend == MIN_INT and divisor == -1: return MAX_INT

        f1 = (dividend >= 0)
        # 比如8/2, 先变成6/2, 再比如-8/2, 变成-6/2, 8/-2变成6/-2, -8/-2, -6/-2
        dividend = dividend+divisor if FLAG else dividend-divisor
        f2 = (dividend >= 0)

        # 1/-1, 1/-2这种情况
        if f1 ^ f2: return 0 if dividend != 0 else -1 if FLAG else 1

        dividend, divisor = abs(dividend), abs(divisor)

        d, count = dividend, 0
        while d >= divisor:
            d, count = d >> 1, count+1

        count -= 1

        result = 0
        while count >= 0:
            d = dividend >> count
            if d >= divisor:
                result += 1 << count
                dividend -= divisor << count
            count -= 1

        result += 1

        return -result if FLAG else result


s = Solution()
print(s.divide(-2147483648, -1))
```
```
# -*- coding: utf-8 -*-

# Author: Cynthia

"""
    方法4, 递归回溯
    比如: 100/3
    100, 3
        100, 30
            100, 300, return 100, 0
        100, 30, return 10, 3
    10 > 3, return 1, 3*10+3
"""


class Solution:

    def divide(self, dividend: int, divisor: int) -> int:

        flag = (dividend >= 0) ^ (divisor >= 0)
        dividend, divisor = abs(dividend), abs(divisor)

        def rf(dd, dr):

            # 递归回溯的头是除数左移大于了被除数
            if dd < dr: return dd, 0

            # 返回值为经递归子函数处理后被除数的剩余值和商
            dd, r = rf(dd, dr << 1)

            # 如果此时被除数大于除数, 该位为1否则为0
            # 为1, 则dd=dd-1*dr, 否则等于dd
            # 为1, 则r=(r<<1)+1, 否则等于r<<1
            return (dd-dr, (r << 1)+1) if dd >= dr else (dd, r << 1)

        left, ans = rf(dividend, divisor)
        return -ans if flag else 2**31-1 if ans > 2**31-1 else ans


s = Solution()
print(s.divide(7, 3))



```
```
# -*- coding: utf-8 -*-

# Author: Cynthia

"""
    方法5, 大神的5行神仙解法, 学习一下
    以1000/3十进制为例, 和之前的方法先提前算出来最大位移位数相比, 此法不先算出来
    而是先计算当前, 然后一有机会就往大了窜

    1000, 3, 位移0->1000-3, 30, 1, 位移1

    997, 30, 位移1->997-30, 300, 1+10, 位移2

    697, 300, 位移2, 697-300, 3000, 11+100, 位移3

    397 < 3000, 397, 300, 位移2

    397, 300, 397-300, 3000, 111+100, 位移3

    97 < 3000, 97, 300, 位移2

    97 < 300, 97, 30, 位移1

    97, 30, 位移1, 97-30, 300, 211+10, 位移2

    37 < 300, 位移2, 30, 位移1
    37, 30, 位移1, 37-30, 300, 位移2


"""


class Solution:

    def divide(self, dividend: int, divisor: int) -> int:
        dd, dr, r, c = abs(dividend), abs(divisor), 0, 0

        # 首先思考循环终止条件, 1000/3, 3->30->300->3000
        # 3000的时候dd < dr了, 但是此时不能退出, 而是要往回找
        # 什么时候退, dd < 3的时候, 即位移为0的dd < dr
        # dd < dr and c <= 0

        while dd >= dr or c > 0:

            if dd >= dr:
                dd, dr, r, c = dd - dr, dr << 1, r + (1 << c), c + 1
            else:
                dr, c = dr >> 1, c - 1

        # 1 << 31 相当于 2**31
        return min([-r, r][dividend ^ divisor >= 0], (1 << 31) - 1)


s = Solution()
print(s.divide(100, 3))

```
```
# -*- coding: utf-8 -*-

# Author: Cynthia

"""
    方法6, 结合方法4和方法5, 非递归, 但是找到头的过程中先不减dr
    100, 3
    100, 30
    100, 300

"""


class Solution:

    def divide(self, dividend: int, divisor: int) -> int:
        dd, dr, r, c = abs(dividend), abs(divisor), 0, 0

        while c >= 0:
            if dd >= dr:
                dr, c = dr << 1, c + 1
            else:
                dr, c = dr >> 1, c - 1
                if dd >= dr and c >= 0:
                    dd, r = dd - dr, r + (1 << c)

        return min([-r, r][dividend ^ divisor >= 0], (1 << 31)-1)


s = Solution()
print(s.divide(1, 1))

```




