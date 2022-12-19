思路：先用‘0’补齐长度较短的字符串，再从后往前遍历

```
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        res = ''
        jw = '0'
        len_a = len(a)
        len_b = len(b)
        if len_a > len_b:  # 补全字符串
            b = '0'*(len_a-len_b) + b
        else:
            a = '0'*(len_b-len_a) + a
        for i in range(len(a)-1, -1, -1):
            if (jw == '1')^(a[i] == '1')^(b[i] == '1'):  # 存在一个1或者全为1
                res = '1' + res
                if not (jw == a[i] == b[i] == '1'):
                    jw = '0'
            else:  # 存在一个0或者全为0
                res = '0' + res
                if not (jw == a[i] == b[i] == '0'):
                    jw = '1'
        return res if jw == '0' else '1' + res
```
