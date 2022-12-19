# 1.暴力法
除法的意义是`dividend`中有多少个`divisor`, 由此出发，我们使用`dividend=dividend-divisor`，每做一次减法判断差是否大于零，若差大于零就记一次数， 然后继续做差。此法会超出时间限制，如果dividend是一个很大的数，divisor是一个很少的数，做差的次数就会很多。
暴力法代码如下：
```python3
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        result = 0
        if dividend > 0 and divisor > 0:
            while dividend > 0:
                dividend = dividend-divisor
                if dividend >= 0:
                    result += 1
            return result

        elif dividend > 0 and divisor < 0:
            while dividend > 0:
                dividend = dividend + divisor
                if dividend>=0:
                    result += 1
            return 0-result

        elif dividend < 0 and divisor > 0:
            while dividend < 0:
                dividend = dividend+divisor
                if dividend <= 0:
                    result += 1
            return 0-result
        
        elif dividend<0 and divisor<0:
            while dividend < 0:
                dividend = dividend-divisor
                if dividend <= 0:
                    result += 1
            return result
        
        else:
            return 0
```


# 2.暴力法的改进
暴力法中减的太慢，接下来我们进行改进，将其成倍的减（在代码中使用加法，实质一样）,我们用一个示例来说明改进原理，如下：
以58 / 7为例：
curVal为当前累加值, count为当前计数
第一次：curVal = 7, count = 1,判断curVal < 58,进入下一次累加;
第二次：curVal = 7 + 7 = 14, count = 1 + 1,判断curVal < 58,进入下一次累加;
第三次：curVal = 14 + 14 = 28, count = 2 + 2 = 4,判断curVal < 58,进入下一次累加;
第四次：curVal = 28 + 28 = 56, count = 4 + 4 = 8,判断curVal < 58,进入下一次累加;
第四次：curVal = 56 + 56 = 112, count = 8 + 8 = 16,判断curVal > 58,找到比58大的值，累加终止;
那么目标值就在8~16之间，
count = 8时，7 * 8 = 56，最接近dividend，还差 58 - 56 = 2，
则剩下的工作计数判断 2里面有多少7了，即求2 / 7的值，
递归就出来了，按照同样的方式递归求解 2/7的值如 2 / 7 = count_2,
那最后的返回结果就是 8 + count_2

改进的暴力法程序如下：

```python3
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        # 使用异或判断符号
        sign = (dividend>0)^(divisor>0)
        # 方便起见全部使用正数来做除法，最后加上符号
        dividend = abs(dividend)
        divisor = abs(divisor)
        result = self.di(dividend, divisor)
        if sign:
            result = -result
        return result if -(1<<31)<=result<=(1<<31)-1 else (1<<31)-1

    def di(self, dividend, divisor):  
        if dividend<divisor:
            return 0  
        count = 1
        temp = divisor
        while temp + temp < dividend:
            count += count
            temp += temp
        return count+self.di(dividend-temp, divisor)
```

# 3. 使用移位
从小学学过的列竖式做除法的原理出发：[具体原理参考@YSY4869的详解](https://leetcode-cn.com/problems/divide-two-integers/solution/xiao-xue-sheng-du-hui-de-lie-shu-shi-suan-chu-fa-b/)

使用移位的代码：
```python3
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        # 使用异或判断符号
        sign = (dividend>0)^(divisor>0)
        # 方便起见全部使用正数来做除法，最后加上符号
        dividend = abs(dividend)
        divisor = abs(divisor)
        count = 0

        while dividend >= divisor:
            divisor <<= 1
            count += 1
        result = 0

        while count > 0:
            count -= 1
            divisor >>= 1
            if divisor <= dividend:
                dividend = dividend-divisor
                result += 1<<count
        if sign:
            result = -result

        return result if -(1<<31)<=result<=(1<<31)-1 else (1<<31)-1
```