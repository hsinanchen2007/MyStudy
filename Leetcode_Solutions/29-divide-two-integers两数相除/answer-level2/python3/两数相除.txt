
使用移位配合加减法运算实现。
前面加了一些判断对于特殊情况，加速处理，比如被除数为0，除数为1/-1 直接返回结果，除数为2，移位返回结果。其他情况，使用移位/加减法计算实现，满足速度要求。
执行用时 : 36 ms , 在所有 Python 提交中击败了 30.41% 的用户
内存消耗 : 11.9 MB, 在所有 Python 提交中击败了5.47%的用户


class Solution(object):
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        if dividend == 0:
            return 0
        if divisor == 1:
            return dividend
        if divisor == -1:
            return min(2**31 - 1, -dividend)
        
        if divisor == 2:
            return dividend >> 1
        if divisor == -2:
            return -dividend >> 1
        
        if dividend < 0:
            dvd_sign = -1
            dividend = -dividend
        else:
            dvd_sign = 1
            
        if divisor < 0:
            dvr_sign = -1
            divisor = -divisor
        else:
            dvr_sign = 1
         
        if dividend < divisor:
            return 0
            
        quot_ = 0
       
        while dividend >= (divisor << 1):
            i = 1
            while (divisor << i) < dividend:
                i += 1
            if i >= 2:
                quot_ += 2 << (i - 2)
            dividend -= (divisor << (i - 1))
        
        while dividend >= divisor:
            quot_ += 1
            dividend -= divisor
        
        if dvd_sign + dvr_sign == 0:
            return -quot_
        else: