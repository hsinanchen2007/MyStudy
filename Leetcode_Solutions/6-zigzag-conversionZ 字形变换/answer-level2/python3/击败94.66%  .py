
```python3 []
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if s=='' or  numRows==1:
            return s
        else:  
            s1=['' for i in range(numRows)]
            k=-1
            i=0
            while i< len(s):
                if k==-1:
                    while  k<numRows-1:
                        k=k+1
                        s1[k]=s1[k]+s[i]
                        i=i+1
                        if i ==len(s):
                            return self.export(s1,numRows)
                if k==numRows-1:
                    k=k-1
                    while k>0:
                        s1[k]=s1[k]+s[i]
                        i=i+1
                        k=k-1
                        if i ==len(s):
                            return self.export(s1,numRows)
                    k=k-1
    
    
    def export(self,s1: str, numRows: int) -> str:
        s2=''
        for i in s1:
            for j in i:
                s2=s2+j
        return s2
        
```
