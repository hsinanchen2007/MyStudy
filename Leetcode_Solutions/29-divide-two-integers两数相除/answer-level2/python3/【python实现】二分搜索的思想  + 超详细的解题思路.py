# 解题思路
## 一、考虑溢出
只有当被除数为−2^31，且除数为-1时，会产生溢出。
## 二、先对符号进行考虑：
1. 判断计算结果的符号：符号相反为负
2. 对两个数取绝对值，用于之后的运算

## 三、运用二分查找的思想
比如10 = 3+3+3+1，那么问题就是：10减多少个3，会让差在[0, 2]之间。
如果是逐个地增加3的个数，那么效率很低。
这时候就可以借用二分搜索的思想，反着用，每次成倍地增加3的数量，因为不能使用乘法，所以我们用加法。
用divisor_tmp 表示当前除数的值，判断 divisor_tmp + divisor_tmp > dividend  ？
若是，则表示除数的个数在(divisor_tmp , 2*divisor_tmp ]之间，那么将被除数fdividend减去当前除数cur，得到的差，再继续对这个差值与初始除数divisor进行递归操作。直到差值满足[0, divisor-1]
否则，divisor_tmp  += divisor_tmp

对于计数器count，它会保存每次递归时除数的倍数，并相加，得到最后的数。

比如：13 / 2
1轮递归：
初始时：divisor_tmp = 2， count = 1，dividend  = 13
递归时：divisor_tmp = 2*4=8， count = 4，dividend  = 13-8=5

2轮递归：
初始时：divisor_tmp = 2， count = 1，dividend  = 5
递归时：divisor_tmp = 2*2=4， count = 2，dividend  = 5-4=1

3轮递归：
初始时：divisor_tmp = 2， count = 1，dividend  = 1
返回 count = 0

累加三轮的count=4+2+0=6
![1.png](https://pic.leetcode-cn.com/f187eb41514a8aa08b60a2222d240644e8cb0f9517233412065e69ae581f4a17-1.png)


```
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        # 溢出判断
        MAX_VALUE = pow(2, 31) - 1 # 允许的最大数
        if dividend + 1 == -MAX_VALUE and divisor == -1:
            return MAX_VALUE
        # 特殊情况
        if divisor == 1:
            return dividend
        if dividend == divisor:
            return 1
        # 符号处理
        sign = True
        if (dividend < 0 < divisor) or (dividend > 0 > divisor):
            sign = False # 负数
 
        # 反向二分查找
        def binarysearch(divident_tmp, divisor):
            divisor_tmp = divisor
            # 判断是否满足条件：被除数小于除数
            if divident_tmp < divisor_tmp:
                return 0
            count = 1 # 计数至少大于1
            # 当除数的两倍小于被除数时，除数要增加两倍，同时计数也要增加两倍
            while divisor_tmp + divisor_tmp <= divident_tmp:
                    count += count
                    divisor_tmp += divisor_tmp
                # 被除数divident_tmp在(divisor_tmp, 2*divisor_tmp]之间
            return binarysearch(divident_tmp - divisor_tmp, divisor) + count

        # 被除数和除数取绝对值，用于接下来的运算
        dividend, divisor = abs(dividend), abs(divisor)
        res = binarysearch(dividend, divisor) if sign else 0 - binarysearch(dividend, divisor)
        return res
```
