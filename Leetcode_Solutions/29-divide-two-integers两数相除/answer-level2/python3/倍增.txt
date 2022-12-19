主要分为3个步骤，核心点就一个：

1、首先判断最后结果的符号，也就是判断除数和被除数和0的关系，然后将两者都转化为正数。

2、然后我们不断的divisor倍增（用加法实现），直到找到倍增后大于dividend，这个时候我们保存这个倍数index。
然后将dividend减去index乘以divisor的值temp，；
接下来递归解决就行。

3、判断最后的结果，如果大于存储边界，则存储最大值即可。

```
class Solution(object):
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        if dividend < 0 and divisor < 0 or dividend > 0 and divisor > 0: # 为了个最后的数字添加符号
            tag = 1
        else: 
            tag = -1
        dividend = abs(dividend)
        divisor = abs(divisor) # 全都变为正数

        if dividend < divisor:
            return 0
        
        returnNum = 0 # 返回结果
        while dividend >= divisor:
            index = 1 # 存储商的
            temp = divisor
            while temp + temp <= dividend:
                temp += temp
                index += index
            returnNum += index
            dividend -= temp
            
        returnNum = returnNum * tag
        if returnNum >= 2147483648:
            return 2147483647
        return returnNum
```
