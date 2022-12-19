```
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if len(str1)<len(str2):
            str1,str2=str2,str1

        n1=len(str1)
        n2=len(str2)

        x=str2
        while True:
            nx=len(x)
            if n1%nx==0 and n2%nx==0 and str1==x*(n1//nx) and str2==x*(n2//nx):
                return x
            else:
                x=x[0:nx-1]

            if nx==1:
                return ""
                
                



```
