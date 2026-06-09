先对x或y为1做特殊处理，然后两重while.

```
class Solution:
    def powerfulIntegers(self, x: int, y: int, bound: int) -> List[int]:
        if bound<2:
            return []
        if x==1:
            if y==1:
                return [2]
            else:
                i=0
                L=[]
                z=2
                while z<=bound:
                    L.append(z)
                    i+=1
                    z=1+y**i
                return L
        if y==1:
            return self.powerfulIntegers(y,x,bound)
        i=0
        j=0
        z=2
        L=[]
        while z<=bound:
            while z<=bound:
                L.append(z)
                z=x**i+y**j
                j+=1
            i+=1
            j=0
            z=x**i+y**j
        return list(set(L))
```