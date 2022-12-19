### 解题思路
![image.png](https://pic.leetcode-cn.com/496c4c4bed293fcbf454c0589f284f8eff38a3d4c64edb1a19c69c972fe42541-image.png)

一开始使用迭代减法，发现时间复杂度太高，遂想到用手算除法时使用的算法：
1、将被除数转化为字符串，从头开始寻找大于除数的数（比如326526,25的情况下就是32）；
2、接下来用迭代减法获得商和余数；
3、每次迭代获得的商均转化为字符串拼接至之之前的商之后；
4、余数转化为字符串，和被除数剩余部分拼接（在上面的例子下就是7和6526），并记录下余数字符串的长度；
5、接下来进行迭代，注意第2次迭代及之后需要判断是否取了两位及以上的剩余部分被除数，如果是，需要按量补0；
6、拼接后的数不大于除数时终止迭代，并在获得的字符串之后补上被除数剩余部分长度相等数量的0。

### 代码

```python3
class Solution:
    def low_divide(self, dividend: int, divisor: int) -> int:
        rt = 0
        while dividend-divisor >= 0:
            dividend -= divisor
            rt += 1
        return rt,dividend
        
    def divide(self, dividend: int, divisor: int) -> int:
        mx = 2147483647
        if dividend == 0:
            return 0
        elif abs(divisor) > abs(dividend):
            return 0
        elif divisor == 1:
            if dividend > 0:
                return min(dividend,mx)
            else:
                return dividend
        elif divisor == -1:
            if dividend > 0:
                return -dividend
            else:
                return min(-dividend,mx)
        else:
            divisor_abs = abs(divisor)
            dividend_abs = abs(dividend)
            dividend_str = str(dividend_abs)
            rt_a = ''
            l = 10
            while int(dividend_str) >= divisor_abs:
                n = 1
                while (dividend_abs := int(dividend_str[:n])) < divisor_abs:
                    n += 1
                    if n >= l+2:
                        rt_a += '0'
                rt,head = self.low_divide(dividend_abs,divisor_abs)
                l = len(str(head))
                dividend_str = str(head)+dividend_str[n:]
                rt_a += str(rt)
            if (app := len(dividend_str)-l) > 0:
                for n in range(app):
                    rt_a += '0'
            if (divisor > 0 and dividend < 0) or (divisor < 0 and dividend > 0):
                rt_a = '-'+rt_a
            return int(rt_a)
                
```