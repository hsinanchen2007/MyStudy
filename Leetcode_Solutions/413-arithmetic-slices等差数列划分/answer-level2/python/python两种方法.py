```
class Solution(object):
    def numberOfArithmeticSlices(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        k=0
        a=[]
        sum=0
        if len(A)<=2:
            return 0
        while k+1<=len(A)-1:
            left=k
            right=k+1
            s=0
            if right+s+1 <len(A):
                while A[right]-A[left]==A[right+s+1]-A[left+s+1]:
                    s=s+1
                    if left+s+1 ==len(A)-1:
                        break
                if right+s-left+1>=3:
                    a.append(right+s-left+1)
            k=left+s+1
        if len(a)>0:
            for i in a:
                for j in range(1,i):
                    sum=sum+j-1
            return sum
        else:
            return 0
```
```
class Solution(object):
    def numberOfArithmeticSlices(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        dp=0
        sum=0
        if len(A)<=2:
            return 0
        d1=A[1]-A[0]
        for i in range(2,len(A)):
            d2=A[i]-A[i-1]
            if d2==d1:
                dp+=1
                sum+=dp
            else:
                dp=0
            d1=d2
        return sum
        
            
```

