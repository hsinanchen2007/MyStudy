相比于用库函数，自己实现的这个位运算并不表现得更快。

``` python
class Solution:
    # bad
    def reverseBits(self, n: int) -> int:
        return int(bin(n)[2:].zfill(32)[::-1],2)
    
    def reverseBits(self, n: int) -> int:
        r = 0
        for i in " "*32:
            r <<= 1
            r |= n&1
            n >>= 1
        return r
```