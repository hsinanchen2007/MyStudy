
debug两小时，发现是kmp记错了，py3
*第九行的海象运算符只有在python3.8以上才有*
```python
class Solution:
    def findGoodStrings(self, n: int, s1: str, s2: str, evil: str) -> int:
        MOD, lz = 10 ** 9 + 7, len(evil)
        def kmp_pnext(string):
            pnext, index = [-1], -1
            for i in range(len(string) - 1):
                while index != -1 and string[i] != string[index]:
                    index = pnext[index]
                pnext.append(index := index + 1)
                if string[i + 1] == string[index]:
                    pnext[i + 1] = pnext[index]
            return pnext
        
        @lru_cache(None)
        def D(ch, z):
            while z >= 0 and ch != evil[z]:
                z = pnext[z]
            return z + 1
                
        @lru_cache(None)
        def F(l, z, b1, b2):
            if z == lz: return 0
            if l == n: return 1
            res = 0
            for ch in ascii_lowercase:
                if b1 and s1[l] > ch or b2 and s2[l] < ch:
                    continue
                res += F(l + 1 , D(ch, z), b1 and s1[l] == ch, b2 and s2[l] == ch)
            return res % MOD
        
        pnext = kmp_pnext(evil)
        return F(0, 0, 1, 1)
```
