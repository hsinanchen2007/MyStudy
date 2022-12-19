
```
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows==1:
            return s   
   
        res=['']*numRows
        i=0 

        for v in s:
            if i==0:
                step=1
            elif i==numRows-1:
                step=-1
            res[i]+=v
            i+=step
            
        return ''.join(res)
```

