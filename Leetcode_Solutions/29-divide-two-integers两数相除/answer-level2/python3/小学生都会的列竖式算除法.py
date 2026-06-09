### 思路：
让我们先回顾一下小学时，怎么通过列竖式的方法计算两个整数的除法，以 `45/2` 为例：

![2019-07-01 19-26-57屏幕截图.png](https://pic.leetcode-cn.com/06d1587045a44cafe8be84000aeced19cfc27ea09aabd8df3a89de6c5d2d8d7d-2019-07-01%2019-26-57%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png){:width=100}
{:align=center}

仔细观察不难发现，这种算法是把除法化归成移位和减法两种运算方法。对于 `10` 进制数，移位运算就是乘（左移）除（右移）`10`，而我们都知道计算机中的移位运算是乘（左移）除（右移）`2`，因为计算机是通过二进制的方法存储数的。这样，类比十进制，二进制的除法（仍以 `45/2` 为例）可以写作（注意，这里我们并没有用到乘除法）

![2019-07-01 19-26-02屏幕截图.png](https://pic.leetcode-cn.com/b0b567805574f94e215153555d7bed5c3de04f3555bbae0e9c767afaf421d13d-2019-07-01%2019-26-02%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png){:width=150}
{:align=center}
### 代码：
清楚了这些，我们就能很容易写出代码了：
```python3 [-Python3]
def divide(self, dividend: int, divisor: int) -> int:
    sign = (dividend > 0) ^ (divisor > 0)
    dividend = abs(dividend)
    divisor = abs(divisor)
    count = 0
    #把除数不断左移，直到它大于被除数
    while dividend >= divisor:
        count += 1
        divisor <<= 1
    result = 0
    while count > 0:
        count -= 1
        divisor >>= 1
        if divisor <= dividend:
            result += 1 << count #这里的移位运算是把二进制（第count+1位上的1）转换为十进制
            dividend -= divisor
    if sign: result = -result
    return result if -(1<<31) <= result <= (1<<31)-1 else (1<<31)-1 
```
