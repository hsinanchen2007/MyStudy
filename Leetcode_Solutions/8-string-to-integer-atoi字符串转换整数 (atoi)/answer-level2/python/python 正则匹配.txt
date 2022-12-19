### 解题思路
正则匹配，\s匹配任意空字符，*表示0次或多次，[-+]？表示中括号里的字符出现1次或0次\d+表示匹配1个以上的数字

### 代码

```python
import re
class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        pat = re.compile('\s*[-+]?\d+')
        if pat.match(str):
            res = pat.match(str).group()
            if -2 ** 31 < int(res) < 2 ** 31 - 1:
                return int(pat.match(str).group())
            else:
                if int(res) < 0:
                    return -2 ** 31
                else:
                    return 2 ** 31 - 1
        else:
            return 0
```