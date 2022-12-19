```
class Solution:
    def titleToNumber(self, s: str) -> int:
        res = 0
        i = 0
        # 逆向遍历，从个位算起
        for cur in s[::-1]:
            # 转数字-64是为了得到ASCII码，乘以26的i次方转成10进制
            res += (ord(cur) - 64) * pow(26,i)
            i += 1
        return res
```
