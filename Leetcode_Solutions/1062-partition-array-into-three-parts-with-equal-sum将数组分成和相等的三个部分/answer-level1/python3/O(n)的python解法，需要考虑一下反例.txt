```
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        if sum(A)%3:
            return False    #总和一定得是3的倍数
        sum_3=sum(A)//3
        res=0               #局部求和的结果
        count=0                #记录数出了几个三分之一和
        for i in range(len(A)):
            res+=A[i]
            if res==sum_3:
                res=0
                count+=1
                if count==3:
                    break
        if count==3 and not res and sum(A[i+1:])==0:
            return True
        return False
```
