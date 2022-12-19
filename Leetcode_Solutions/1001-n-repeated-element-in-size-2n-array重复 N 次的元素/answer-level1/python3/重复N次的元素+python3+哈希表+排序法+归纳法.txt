### 1. 哈希表
```
class Solution:
    def repeatedNTimes(self, A: List[int]) -> int:
        dic = {}
        for i in A:
            dic[i] = dic.get(i,0)+1
        N = len(A)//2
        for key in dic:
            if dic[key]==N:
                return key
            
```
### 2.排序法
先排序，再找出该元素。
```
class Solution:
    def repeatedNTimes(self, A: List[int]) -> int:
        A.sort()
        N = len(A)//2
        if A[N]==A[N-1]:
            return A[N]
        if A.count(A[N]) == 1:
            return A[N-1]
        return A[N]
```
### 3.归纳法(比上面两种快)
因为这题其他元素都是只有一个，所以可以归纳得出：当数组长度大于4之后，一遍遍历中，肯定有3个相邻的元素中包含两个重复值（可以自己试一下）。所以把前面特殊情况先求出来，再遍历就可以了。
```
class Solution:
    def repeatedNTimes(self, A: List[int]) -> int:
        n = len(A)
        if n==2:
            return A[0]
        if n==4:
            if A[0]==A[-1]:
                return A[0]
        i,j,k = 0,1,2
        if A[i]==A[j]:
            return A[i]
        while k<n:
            if A[k]==A[i] or A[k]==A[j]:
                return A[k]
            i,j,k=i+1,j+1,k+1
            
```
