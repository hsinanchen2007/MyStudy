```
class Solution:
    def complexNumberMultiply(self, a: str, b: str) -> str:
        if not a:
            return b
        if not b:
            return a
        
        alist = a.split('+')
        blist = b.split('+')
        Real = int(alist[0]) * int(blist[0]) - int(alist[1][:-1]) * int(blist[1][:-1])
        Image = int(alist[0]) * int(blist[1][:-1]) + int(alist[1][:-1]) * int(blist[0])
        result = [str(Real), str(Image) + 'i']
        return "+".join(result)
```
