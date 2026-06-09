双指针，思路简单
```
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
 
        n=len(A)
        if n<3:
            return False
        i=0
        j=len(A)-1
        sum1=A[0]
        sum2=A[j]
        sumA=sum(A)
        if sumA%3!=0:
            return False
        benchmark=sumA/3
        print(A)
        while i<j-1 :
         
            if sum1!=benchmark:
                i+=1
                sum1+=A[i]
            if sum2!=benchmark:
                j-=1
                sum2+=A[j]
   
            if sum1==benchmark and sum2==benchmark and i+1<j:
                return True
       
        
        return False

```
