### 解题思路
Python版本的bfs，首先统计路径对应的障碍物数量，超出视为失败。
然后若队列顶端路径障碍数量多于当前点已知障碍物，推出。
否则，继续遍历该点附近点，若附近点(l或l+1)小于当前点已知障碍物，加入队列。
同时，不考虑障碍，最短路为m+n-3,若k>=m+n-3,直接返回。
### 代码

```
class Solution:
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        m,n=len(grid),len(grid[0])
        k,queue,count,visited=min(k, m+n-3),collections.deque([(0,0,0)]),0,collections.defaultdict(lambda :float('inf'))
        if m+n-3==k or (m==1 and n==1):
            return m+n-2
        while queue:
            count+=1
            for _ in range(len(queue)):
                i,j,l=queue.popleft()
                if visited[(i,j)]<l:
                    continue
                for x,y in [[i+1,j],[i-1,j],[i,j+1],[i,j-1]]:
                    if 0<=x<len(grid) and 0<=y<len(grid[0]) and l<visited[(x,y)]:
                        if grid[x][y]==0:
                            queue.append((x,y,l))
                            visited[(x,y)]=l
                        elif l+1<=k and l+1<visited[(x,y)]:
                            queue.append((x,y,l+1))
                            visited[(x,y)]=l+1
                        if (m-1,n-1) in visited:
                            return count
        return 0 if len(grid)==1 and len(grid[0])==1 else -1
```
