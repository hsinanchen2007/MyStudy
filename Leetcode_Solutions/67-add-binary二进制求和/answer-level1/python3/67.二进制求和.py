思路：设置plus标志表示进位，然后记录两个字符串的最后一位索引，进行反向遍历，然后把所有情况判断一下。
代码有点傻-、-！
```
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        plus = False
        alen = len(a)-1
        blen = len(b)-1
        res = ''
        if alen > blen:
            alen,blen,a,b = blen,alen,b,a
        while blen >= 0:
            if alen < 0:
                if b[blen] == '1':
                    if plus:
                        res = '0' + res
                        plus = True
                        blen -= 1
                    else:
                        res = '1' + res
                        plus = False
                        blen -= 1
                else:
                    if plus:
                        res = '1' + res
                        plus = False
                        blen -= 1
                    else:
                        res = '0' + res
                        plus = False
                        blen -= 1
            else:
                if a[alen] == b[blen]:
                    if b[blen] == '1':
                        if plus:
                            res = '1' + res
                            plus = True
                            alen -= 1
                            blen -= 1
                        else:
                            res = '0' + res
                            plus = True
                            alen -= 1
                            blen -= 1
                    else:
                        if plus:
                            res = '1' + res
                            plus = False
                            alen -= 1
                            blen -= 1
                        else:
                            res = '0' + res
                            plus = False
                            alen -= 1
                            blen -= 1
                else:
                    if plus:
                        res = '0' + res
                        plus = True
                        alen -= 1
                        blen -= 1
                    else:
                        res = '1' + res
                        plus = False
                        alen -= 1
                        blen -= 1
        if plus:
            res = '1' + res
        return res
```
