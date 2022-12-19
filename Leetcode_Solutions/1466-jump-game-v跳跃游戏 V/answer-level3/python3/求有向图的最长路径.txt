### 解题思路
转换成有向图后，求最长的路径

### 代码

```python3
class Solution:
    def maxJumps(self, arr: List[int], d: int) -> int:
        
        g = collections.defaultdict(list)
        A = arr
        N = len(A)
        for i in range(N):
            for j in range(i+1, min(N, i+d+1)):
                if A[i] <= A[j]:
                    break
                g[i].append(j)
            
            for j in range(i-1, max(-1, i-d-1), -1):
                if A[i] <= A[j]:
                    break
                    
                g[i].append(j)
        
        
        # print(g)
        
        ans = [1 for _  in range(N)]
        
        def dfs(node, parent):
            if ans[node] > 1:
                return ans[node]
            
            dist = 1
            for v in g[node]:
                if v != parent:
                    dist = max(dist, 1 + dfs(v, node))
            
            ans[node] = dist
            return dist
        
        for i in range(N):
            dfs(i, -1)
        return max(ans)
```