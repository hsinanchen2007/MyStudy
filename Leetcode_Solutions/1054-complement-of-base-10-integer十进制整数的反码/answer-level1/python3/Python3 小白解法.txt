是很小白的算法了，可以分享给和我一样的小白看看，因为我发现很多大佬写的我都看不懂啊···
```
class Solution:
    def bitwiseComplement(self, N: int) -> int:
        a = bin(N)[2:]
        b = ''
        for i in range(len(a)):
            x = int(a[i]) ^ 1
            b = b + str(x)
        return int(b,2)
```
