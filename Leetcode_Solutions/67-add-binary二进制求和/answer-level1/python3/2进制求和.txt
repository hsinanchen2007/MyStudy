1: 先使用int(), 将2进制转化为10进制
2: 然后将10进制x相加
3：然后转化为2进制

```
class Soution:
    def transfer_number(a: str, b: str) -> str:
        c, d = int(a, 2), int(b, 2)
        e = bin(c + d)
        # bin()函数在2进制前边会多加一个"0b", 所以要去掉.
        f = str(e)[2:]
        return f
```
