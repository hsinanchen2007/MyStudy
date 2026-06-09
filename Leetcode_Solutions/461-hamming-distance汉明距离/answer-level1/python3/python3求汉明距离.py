首先进行异或运算，将二进制位不一致的转为1.`x^=y`
其次将结果转为二进制数，并去掉0b.`y=bin(x).replace('0b','')`
接着将二进制字符串转换成列表并进行求和得到个数。`x=sum([int(i) for i in list(y)])`
```
class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        x^=y
        x=sum([int(i) for i in list(bin(x).replace('0b',''))])
        return x
```
