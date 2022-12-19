感觉这题完全就是麻烦，但是不难。
```
class Solution:
    def myAtoi(self, str: str) -> int:
        import re
        if not str.strip():
            return 0
        str = str.lstrip()
        if str.startswith('-') or str.startswith('+'):
            if len(str) == 1:
                return 0
            if not str[1].isdigit():
                return 0
        else:
            if not str[0].isdigit():
                return 0
        s = re.search('\d+|-\d+',str)
        a = s.start()
        b = s.end()
        ans = int(str[a:b])
        if ans > pow(2,31) - 1:
            return pow(2,31) - 1
        elif ans < -pow(2,31):
            return -pow(2,31)
        return ans
```
