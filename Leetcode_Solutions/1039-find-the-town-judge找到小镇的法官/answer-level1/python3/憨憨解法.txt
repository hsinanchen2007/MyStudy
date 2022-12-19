
```python3
class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
      l=[i[0] for i in trust]
      m=0
      for t in range(1,N+1):
        if t not in l:
          m=t 
          break
      for k in range(1,N+1):
        if [k,m] not in trust and k!=m:
          return -1
      return m


      

```
