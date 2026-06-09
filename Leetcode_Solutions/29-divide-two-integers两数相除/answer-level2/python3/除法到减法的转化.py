# 参见了各种大佬的题解, 我就从中挑选了一些我认为**比较好用**的方法.
- 方法一：
题干中说明不能用乘法和除法, 那么我们可以用减法, 被除数最多可以减多少个除数还能保证是非负的即可.
```python []
class Solution:
    def divide(self, dividend, divisor):
        sig = True if dividend*divisor > 0 else False  # 判断二者相除是正or负
        dividend, divisor= abs(dividend), abs(divisor)  # 将被除数和除数都变成正数
        count = 0  # 用来表示减去了多少个除数，也就是商为多少
        while divisor <= dividend:  # 当被除数小于除数的时候终止循环
            dividend -= divisor
            count += 1
        res = count if sig == True else -count  # 给结果加上符号
        return max(min(res, 2**31-1), -2**31)
```


但是会超时！！！（ps：比如2**30/1会算好久好久...）
- 方法二：
针对于第一种的缺陷, 我们应该想到让除数成倍的增长, 这样被除数进行的减法操作就会少很多.
```python []
class Solution:
    def divide(self, dividend, divisor):
        sig = True if dividend*divisor > 0 else False  # 判断二者相除是正or负
        dividend, divisor= abs(dividend), abs(divisor)  # 将被除数和除数都变成正数
        res = 0                               # 用来表示减去了多少个除数，也就是商为多少
        while divisor <= dividend:              # 当被除数小于除数的时候终止循环
            tmp_divisor, count = divisor, 1     # 倍增除数初始化
            while tmp_divisor <= dividend:      # 当倍增后的除数大于被除数重新，变成最开始的除数
                dividend -= tmp_divisor
                res += count
                count += 1                      # 更新除数扩大的倍数
                tmp_divisor = divisor*count     # 更新除数
        res_value = res if sig == True else -res  # 给结果加上符号
        return max(min(res_value, 2**31-1), -2**31)
```
- 方法三
该方法是对方法二的优化, 因为方法二中还是用到了乘法.
```python [方法二]
tmp_divisor = divisor*count     # 乘法运算
```
所以我们可以用移位运算来代替乘法运算, 每次移动一位相当于扩大了两倍, 这个时候大家应该能感觉出来方法三比方法二的计算速度可能会更快一些(因为方法二是除数扩大倍数是1倍1倍的增加, 而方法三中除数扩大的倍数是两倍两倍的增加).
```python []
class Solution:
    def divide(self, dividend, divisor):
        sig = True if dividend*divisor > 0 else False   # 判断二者相除是正or负
        dividend, divisor= abs(dividend), abs(divisor)  # 将被除数和除数都变成正数
        res = 0                                         # 用来表示减去了多少个除数，也就是商为多少
        while divisor <= dividend:                      # 当被除数小于除数的时候终止循环
            tmp_divisor, count = divisor, 1             # 倍增除数初始化
            while tmp_divisor <= dividend:              # 当倍增后的除数大于被除数重新，变成最开始的除数
                dividend -= tmp_divisor
                res += count
                count <<= 1                             # 向左移动一位
                tmp_divisor <<= 1                       # 更新除数(将除数扩大两倍)
        res_value = res if sig == True else -res        # 给结果加上符号
        return max(min(res_value, 2**31-1), -2**31)
```

- 方法四
该方法也称为作弊法，因为python自带求商的运算符号"//".
```python []
class Solution:
    def divide(self, dividend, divisor):

        sig = False if dividend * divisor < 0 else True  # 判断二者相除是正or负
        dividend, divisor = abs(dividend), abs(divisor)
        tmp = dividend // divisor
        res_value = tmp if sig == True else -tmp
        return min(max(res_value, -2**31), 2**31 - 1)
```

如果哪里有问题, 或者大家有更好的想法, 欢迎分享哈~（方法三是热心市民提供的想法，非常感谢）