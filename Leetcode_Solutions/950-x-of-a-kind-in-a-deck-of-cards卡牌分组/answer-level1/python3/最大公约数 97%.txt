只需要纪录每种牌的个数，在对个数求最大公约数，为1则false，不为1则true。
```
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        D = {}
        for x in deck:
            D[x] = D.setdefault(x, 0) + 1
        a = []
        for v in D.values():
            a.append(v)
        gcd = a[0]
        for i in range(1, len(a)):
            gcd = math.gcd(gcd, a[i])
        if gcd == 1:
            return False
        return True  
```
