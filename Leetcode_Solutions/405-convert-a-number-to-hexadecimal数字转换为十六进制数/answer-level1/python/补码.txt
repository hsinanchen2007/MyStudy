```
def toHex(self, num):
        """
        :type num: int
        :rtype: str
        """
        s = ''
        c = '0'

        if num == 0:
            return c
        # 取补码
        if num < 0:
            num += 2 ** 32
        # 转换
        while num > 0:
            # 取余加权值
            d = num % 16
            if d >= 0 and d <= 9:
                c = chr(ord("0") + d)
            elif d >= 10:
                c = chr(ord("a") + d - 10)
            s = c + s
            num = int(num / 16)

        return s
```
