一开始用了这种，超时了
```
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        A.sort()
        #print(A)
        count=0
        for index in range(1,len(A)):
            while A[index]<=A[index-1]:
                A[index]+=1
                print(A)
                count+=1

        return count
```

把while循环改成了直接计算
```
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        A.sort()
        #print(A)
        count=0
        for index in range(1,len(A)):
            if A[index]<=A[index-1]:
                count=count+A[index-1]-A[index]+1
                A[index]=A[index-1]+1
                                
        return count
```
