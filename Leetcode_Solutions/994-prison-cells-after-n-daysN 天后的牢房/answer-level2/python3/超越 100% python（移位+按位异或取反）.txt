[题解原文](https://codeplot.top/2019/10/05/leetcode-957-N-%E5%A4%A9%E5%90%8E%E7%9A%84%E7%89%A2%E6%88%BF-Prison-Cells-After-N-Days/)
把 list 转换为 byte。两次移位然后按位异或后取反。

```python
class Solution:
    @staticmethod
    def bit2list(x):
        i = 128
        c = []
        while i > 0:
            if x & i > 0:
                c.append(1)
            else:
                c.append(0)
            i >>= 1
        return c

    def prisonAfterNDays(self, cells: [int], N: int) -> [int]:
        x = 0
        idx = 0
        j = 1
        for i in range(8):
            if cells[7-i] == 1:
                x = x | j
            j <<= 1
        mp = {}
        mp[x] = idx
        while idx < N:
            y = x << 1 & 0b011111111
            z = x >> 1
            x = ~(y ^ z) & 0b01111110
            idx += 1
            if x in mp: 
                break
            else: 
                mp[x] = idx
        if idx < N:
            N = (N - mp[x]) % (idx - mp[x])
            idx = 0
            while idx < N:
                y = x << 1 & 0b011111111
                z = x >> 1
                x = ~(y ^ z) & 0b01111110
                idx += 1
        return self.bit2list(x) 
```