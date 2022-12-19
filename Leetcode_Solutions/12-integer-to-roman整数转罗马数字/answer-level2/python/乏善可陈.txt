将复合符号看作一个符号，按照每个符号代表的数字大小从大到小取模，得到整个罗马数字序列。

整道题目的代码如下：

```python
class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        m = num / 1000
        num = num % 1000

        cm = num / 900
        num = num % 900

        d = num / 500
        num = num % 500

        cd = num / 400
        num = num % 400

        c = num / 100
        num = num % 100

        xc = num / 90
        num = num % 90

        l = num / 50
        num = num % 50

        xl = num / 40
        num = num % 40

        x = num / 10
        num = num % 10

        ix = num / 9
        num = num % 9

        v = num / 5
        num = num % 5

        iv = num / 4
        num = num % 4

        i = num

        res = m*'M'+cm*'CM'+d*'D'+cd*'CD'+c*'C'+xc*'XC' + \
            l*'L'+xl*'XL'+x*'X'+ix*'IX'+v*'V'+iv*'IV'+i*'I'

        return res
```

