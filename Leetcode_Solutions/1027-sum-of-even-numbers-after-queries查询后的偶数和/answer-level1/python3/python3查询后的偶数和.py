
### 代码

```python3
class Solution:
    def sumEvenAfterQueries(self, A: List[int], queries: List[List[int]]) -> List[int]:
        evenlist=[0]*len(queries)
        evensum=0
        for num in A:
            if num%2==0:
                evensum+=num
        for i,que in enumerate(queries):
            if A[que[1]]%2==0:
                if que[0]%2==0:
                    evensum+=que[0]
                else:
                    evensum-=A[que[1]]
                A[que[1]]+=que[0]
            else:
                A[que[1]]+=que[0]
                if A[que[1]]%2==0:
                    evensum+=A[que[1]]
            evenlist[i]=evensum
        return evenlist
```