```
class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        s=set()
        def dfs(i):
            if i<0 or i>=len(arr):
                return False
            if arr[i]==0:
                return True
            if i in s:
                return False
            s.add(i)
            return dfs(i+arr[i]) or dfs(i-arr[i])
        return dfs(start)
```