
```
class Solution:   
    def getRow(self, rowIndex: int) -> List[int]:
        k = []
        k.append([1])
        k.append([1,1])
        for m in range(2,rowIndex+1):
            k.append([1]+[k[m-1][i-1]+k[m-1][i] for i in range(1,len(k[m-1]))]+[1])
        return k[rowIndex]
```


