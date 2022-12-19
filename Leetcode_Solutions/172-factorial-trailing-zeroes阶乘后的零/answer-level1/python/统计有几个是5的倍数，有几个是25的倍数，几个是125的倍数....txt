        #本质上是计算含有多少个5的质因子
        #思路：给定一个数，比如200，那么在1-200里面统计一下
        #有几个是5的倍数，有几个是25的倍数，几个是125的倍数
        #             5的倍数    25的倍数     125的倍数   ......
        # 5               1
        # 10              1
        # 15              1
        # ...
        # 25              1           1
        # 30              1
        # ...
        # 50              1           1
        # ...
        # 125             1           1           1 

class Solution(object):
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """     
        sum = 0
        i = 5
        while i <= n:
            sum += n / i
            i *= 5
        return sum