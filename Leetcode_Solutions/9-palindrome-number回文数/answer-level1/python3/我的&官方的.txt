### 解题思路
可以先看下我之前写的代码，执行时间只超过了5%的用户。
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        if x == 0:
            return True

        # x是几位数
        num = 0
        while int(x / pow(10,num)) != 0:
            num += 1

        # 一半
        for i in range( 0, int(num/2) ):
            # 相对的两个数
            low = int(x / pow(10,i)) % 10
            high = int(x/pow(10,num-1-i)) % 10
            if low != high:
                return False

        return True
然后再看一下官方的。
其实我是有想到half的思路的，但是距离官方的思路还有一定的距离。
我总是止步于想要知道x是几位数，其实有了half的思路，再多深入地想想是可以脱离x是几位数这个瓶颈的。

### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        # 特殊情况
        if x < 0:
            return False
        if x != 0 and x % 10 == 0:
            return False

        temp = 0
        while temp < x:
            temp = temp * 10 + x % 10
            x = int(x/10)

        return temp == x or int(temp/10) == x
```