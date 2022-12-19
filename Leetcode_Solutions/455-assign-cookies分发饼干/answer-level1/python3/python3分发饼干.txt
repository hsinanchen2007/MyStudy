```
class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()
        k=0
        num=0
        for i in g:
            for j in range(k,len(s)) :
                if s[j]>=i:
                    k=j+1
                    num+=1
                    break
        return num
```
