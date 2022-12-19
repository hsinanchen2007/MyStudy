### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        n=len(A)
        count=0
        if n<2:
            return count
        B=[0]*80001
        for i in range(n):
            B[A[i]]+=1
        for j in range(80001):
            if B[j]<=1:
                continue
            count=count+B[j]-1
            B[j+1]=B[j+1]+B[j]-1
            B[j]=1
        return count
                
        '''
        A.sort()
        n=len(A)
        count=0
        if n<2:
            return count

        for i in range(1,n):
            if A[i]>A[i-1]:
                continue
            else:
                while A[i-1]>=A[i]:
                    A[i]+=1
                    count+=1
        return count
        '''


```