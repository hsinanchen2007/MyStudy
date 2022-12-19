### 解题思路
这道题其实过程就是二进制-十进制-二进制。理解好二进制转为十进制的做法和bin()的用法，但是bin函数前面有0x前缀，结果为字符串，只需要在2位置开始取值就可以了

### 代码

```python3
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        m,n=0,0
        for i in range(len(a)):
            m+=eval(a[i])*2**(len(a)-i-1)
        for i in range(len(b)):
            n+=eval(b[i])*2**(len(b)-i-1)
        return bin(m+n)[2:]
```