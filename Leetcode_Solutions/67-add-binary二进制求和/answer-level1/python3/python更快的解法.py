看了一圈大佬们的代码，发现用都是用bin转，但是同样的代码，为什么我的要慢：
然后发现用format直接转实现更快（我也不知道啥原因）
```
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        return '{:b}'.format(int(a, 2) + int(b,2))
```