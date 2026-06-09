1. 暴力递归求解方法
```
class Solution(object):
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        s = 0
        for i in str(num):
            s += int(i)
        return self.addDigits(s) if len(str(s)) > 1 else s
```

2. 数学
看到其他的大神的求解

```
"""
s1 = 100 * a + 10 * b + c
s2 = a + b + c

差值 s1 - s2 = 99 * a + 9 * b
差值可以被9整除，每一个循环都这样，缩小了9倍
"""
class Solution(object):
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        if num > 9:
            num = num % 9
            if num == 0:
                return 9

        return num
```
