```
class Solution:
    def MyRun(self,cont,value,fraction,n):
        while -n<=len(cont):
            n_new =n-1
            value_new=value*cont[n]+fraction
            fraction_new=value
            return self.MyRun(cont,value_new,fraction_new,n_new)
        else:
            return [value,fraction]
    def fraction(self, cont):
        if len(cont)==1:
            return [cont[0],1]
        return self.MyRun(cont,cont[-1]*cont[-2]+1,cont[-1],-3)
s1=Solution()
print(s1.fraction([3, 2, 0, 2]))
```
