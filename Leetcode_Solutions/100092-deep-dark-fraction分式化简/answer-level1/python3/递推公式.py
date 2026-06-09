```
#五行代码解决问题，递推公式求解
class Solution:
    def fraction(self, cont: List[int]) -> List[int]:
        cont=cont[::-1]
        n,m=cont[0],1
        for i in range(len(cont)-1):
            n,m=n*cont[i+1]+m,n
        return [n,m]
```