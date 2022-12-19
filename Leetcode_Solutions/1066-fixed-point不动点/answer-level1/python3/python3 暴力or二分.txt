思路1：上来就是顺序遍历。。
```
class Solution:
    def fixedPoint(self, A: List[int]) -> int:
        for i in range(len(A)):
            if A[i]==i:
                return i
        return -1
```
思路2：既然是有序的那还是想一下二分的方法吧（写了半天二分，发现这道题二分没这么好写，首先存在题目无解的情况；其次本题可能会有多种解的情况，我们要输出的是索引最小的那个index）
```
class Solution:
    def fixedPoint(self, A: List[int]) -> int:
        left,right = 0,len(A)-1
        while left<right:
            mid = (left+right)//2
            if A[mid]>=mid:
                right=mid
            if A[mid]<mid:
                left = mid+1
            
        return left if A[left]==left else -1
```

