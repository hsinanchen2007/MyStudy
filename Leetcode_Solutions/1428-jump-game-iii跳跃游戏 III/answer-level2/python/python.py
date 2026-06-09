
python 采用bfs，使用队列实现，使用一个map记录已经走过的点，避免重复走入死循环

```
class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        m=len(arr)
        q=[start]
        mp={}
        while len(q):
            s=q.pop()
            if arr[s]==0:
                return True
            for s2 in [s+arr[s],s-arr[s]]:
                if 0<=s2<m and s2 not in mp:
                    mp[s2]=1
                    q.append(s2)
        return False
```
