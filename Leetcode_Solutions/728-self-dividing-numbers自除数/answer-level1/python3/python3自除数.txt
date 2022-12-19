```
class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        l=[]
        if left==0:
            left+=1
        for ii in range(left,right+1):
            jj=ii
            flag=0
            while jj%10!=0:
                if ii%(jj%10)!=0:
                    flag=0
                    break
                else:
                    jj//=10
                    flag=1
            if flag==1 and jj<10:
                l.append(ii)
        return l
```
