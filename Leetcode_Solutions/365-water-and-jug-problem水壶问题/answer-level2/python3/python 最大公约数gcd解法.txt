```
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        def gcd(a,b):
            while b!=0:
                r=a%b
                a=b
                b=r
            return a
        if x==0 and y==0:
            return z==0
        if x+y<z:
            return False
        if y==0:
            return z%gcd(x,y)==0
        if x==0:
            return z%gcd(y,x)==0
        return z%gcd(x,y)==0

```

