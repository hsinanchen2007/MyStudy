
由于字符串不可变没有`reverse`方法，所以转换为列表来操作，然后用`.join()`方法变回字符串负数直接截取出数的部分翻转，然后判断溢出则取0
非要用字符串的话可以`str(x)[::-1]`来反转操作
```
class Solution:
    def reverse(self, x: int) -> int:
        li = list(str(x))
        if li[0] == '-':
            li[1:] = reversed(li[1:])
            res = int(''.join(li))
            if res < (-2)**31:
                return 0
            return res
        else:
            li.reverse()
            res = int(''.join(li))
            if res > 2**31 - 1:
                return 0
            return res
```
