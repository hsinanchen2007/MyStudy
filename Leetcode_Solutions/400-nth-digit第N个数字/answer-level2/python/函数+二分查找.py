## 题目

在无限的整数序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...中找到第 n 个数字。

输入:11

输出:0

说明: 第11个数字在序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 里是0，它是10的一部分。

## 分析

根据题意， 是求将自然数数列拼接起来的字符串第n个字符， 如` 1 2 3 4 5 6 7 8 9 10` 的第11个字符是`0`

设， 自然数数列有x项，构成的字符串长度为y

当`x=234`时, 1-9是1位的， 10-99是2位的， 100-234是3位的

则`y = 3 * (234-99) + 2 * 90 + 1 * 9`

用a代表x的位数， 可以得到函数 `y = a*(x-10^(a-1)-1)  + (a-1)*9*10^(a-2) + (a-2)*9*10^(a-3) + ... + 9`

化简可得： `y = a*x + a - 10^(a-1) - 10^(a-2) - ... - 10^0`

由于函数y是递增的，可以用二分查找找到离y离n最近时的x的取值， 就可以求出第n位的数字

## 代码


```Python
class Solution(object):
    def findNthDigit(self, n):
        """
        :type n: int
        :rtype: int
        """

        def func(x):
            if x == 0: return 0
            a = len(str(x))
            return x * a + a - sum(10**i for i in range(a))

        if n < 1:
            return

        left = 0
        right = 2 ** 31
        target = n
        mid = None
        found = False
        while left < right-1:
            mid = (left + right)//2
            mid_val = func(mid)
            if mid_val > target:
                right = mid
            elif mid_val < target:
                left = mid
            else:
                found = True
                break
        if found:
            return str(mid)[-1]
        if func(mid) > target:
            right = mid
        offset = func(right) - n
        return str(right)[-1-offset]
```