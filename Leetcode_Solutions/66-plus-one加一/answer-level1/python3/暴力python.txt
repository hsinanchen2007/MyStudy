```
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        n=len(digits)
        m=0
        if digits[n-1]+1>9:
            digits[n-1]=0
            m=1
        else:
            digits[n-1]+=1
            return digits
        for i in range(n-2,-1,-1):
            #print(digits[i])
            #print(i)
            if digits[i]+m>9:
                digits[i]=0
            else:
                digits[i]+=m
                return digits
            
        if digits[0]==0:
            digits.insert(0,1)
            return digits


                
```
