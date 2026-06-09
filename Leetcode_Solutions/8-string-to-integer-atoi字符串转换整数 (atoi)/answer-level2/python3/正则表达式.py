![image.png](https://pic.leetcode-cn.com/2e253f17a5c9d3cdda47d9568cf5c2c89722d34de639d0b4164d5b0c84af4de3-image.png)

```
class Solution:
    def myAtoi(self, s: str) -> int:
        import re
        s = re.findall('^[\-\+]?[0-9]+', s.lstrip())
        s = max(min(int(*s), 2**31-1), -2**31)
        return s
```