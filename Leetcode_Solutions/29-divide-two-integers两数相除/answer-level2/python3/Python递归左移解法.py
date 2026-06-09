```
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        # 内嵌递归核心函数，函数另开是为了递归是不必重复执行abs
        def divide_inner(a, b):
            # 当被除数比除数小时，直接返回0
            if a < b:
                return 0
            # 当被除数大于除数，当小于除数的两倍，返回1
            elif a-b < b:
                return 1
            # 否则一直递归左移，就是获取一个偶数倍数
            else:
                ret = 1
                temp = b
                while a >= temp<<1:
                    ret *= 2
                    temp <<= 1
                return ret + divide_inner(a-ret*b, b)
        
        # 数据预处理，转为绝对值处理
        k = 1
        if dividend < 0:
            k *= -1
        if divisor < 0:
            k *= -1
        a = abs(dividend)
        b = abs(divisor)
        
        return max(min(k*divide_inner(a, b), 2**31-1), -(2**31))
```
