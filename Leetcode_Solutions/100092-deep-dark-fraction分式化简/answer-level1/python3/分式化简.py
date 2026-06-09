```
class Solution:
    def fraction(self, cont: List[int]) -> List[int]:
        outList=[0,1]              
        for index in range(len(cont)-1,-1,-1):                
            outList = [outList[1],cont[index]*outList[1]+outList[0]]
        return outList[::-1]
```