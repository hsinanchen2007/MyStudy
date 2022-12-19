# findLarger

从低位到高位找, 如果找到`01`这个模式, 就可以构造了.如果找不到,那么需要分情况考虑下,下面数字都是二进制
```
1 -> 10 # 未找到01, 返回1*2
100 -> 1000 # 未找到01, 返回 100 * 2
111 -> 1011 # 未找到01, 返回1011
101 -> 110 # 找到01, 01->10
1011100 -> 1100011 # 找到01, 01变成10, 在低位填充先0后1
```

# findSmaller

从低位到高位找, 如果找到`10`这个模式,就可以构造了,如果没有这个模式,返回-1. 如下
```
1 -> -1 # 未找到10
10 -> 01 # 找到10, 返回01
1011 -> 0111 # 找到10, 返回0111
```

# 代码
```python
class Solution:
    def findClosedNumbers(self, num: int) -> List[int]:

        def findLarger(n):
            num_digits = num_zeros = num_ones = 0
            find_01 = False
            while n:
                num_digits += 1
                if n & 1:
                    num_ones += 1
                else:
                    num_zeros += 1
                    if num_ones:
                        n >>= 1
                        find_01 = True
                        break
                n >>= 1
            if find_01:
                n <<= 1
                n += 1
                for i in range(num_zeros):
                    n <<= 1
                for i in range(num_ones - 1):
                    n <<= 1
                    n += 1
                return n
            else:
                if num_ones == 1:
                    return 1 << num_digits
                else:
                    res = 2
                    for i in range(num_ones - 1):
                        res <<= 1
                        res += 1
                    return res

        def findSmaller(n):
            num_digits = num_ones = num_zeros = 0
            find_10 = False
            while n:
                num_digits += 1
                if not n & 1:
                    num_zeros += 1
                else:
                    num_ones += 1
                    if num_zeros:
                        find_10 = True
                        n >>= 1
                        break
                n >>= 1
            if find_10:
                n <<= 1
                for i in range(num_ones):
                    n <<= 1
                    n += 1
                for i in range(num_zeros - 1):
                    n <<= 1
                return n
            else:
                return -1

        return [findLarger(num), findSmaller(num)]

```