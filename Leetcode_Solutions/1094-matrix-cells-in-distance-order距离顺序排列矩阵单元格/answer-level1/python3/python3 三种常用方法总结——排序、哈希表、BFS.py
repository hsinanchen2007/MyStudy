一、排序
    计算出每一个点到目标点的曼哈顿距离，按照距离从小到大排序即可。
    时间复杂度：O(nlogn); 空间复杂度：O(n) 【n=R*C】

```python3
class Solution:
    def allCellsDistOrder(self, R: int, C: int, r0: int, c0: int) -> List[List[int]]:
        res=[[i,j] for i in range(R) for j in range(C)]
        res.sort(key=lambda x: abs(x[0]-r0)+abs(x[1]-c0))
        return res
```
二、哈希表
    遍历一次后，将距离作为key值，点坐标作为value值存入hashmap中；
    让key值从0开始依次向后遍历，将hashmap中对应的value放入结果res中即可。
    注意：此处的哈希表也可用数组代替，原理是一样的。
    时间复杂度：O(n); 空间复杂度：O(n) 【n=R*C】

```python3
class Solution:
    def allCellsDistOrder(self, R: int, C: int, r0: int, c0: int) -> List[List[int]]:
        res=[]
        hashmap=collections.defaultdict(list)
        for r in range(R):
            for c in range(C):
                key=abs(r-r0)+abs(c-c0)
                hashmap[key].append([r,c])
        for i in range(R+C):
            res+=hashmap.get(i,[])
        return res
```
三、广度优先搜索（BFS）
    使用队列实现，注意：每当队列中新添加一个点后，要及时将该点标记为已访问，防止重复访问；
    每当队列中pop出一个点后，就在结果res中加入该点。
    时间复杂度：O(n); 空间复杂度：O(n) 【n=R*C】

```python3
class Solution:
    def allCellsDistOrder(self, R: int, C: int, r0: int, c0: int) -> List[List[int]]:
        res=[]
        dic=[[-1,0],[0,1],[1,0],[0,-1]]
        visit=[[False]*C for _ in range(R)]
        queue=collections.deque()
        queue.append([r0,c0])
        visit[r0][c0]=True
        while queue:
            cur=queue.popleft()
            res.append(cur)
            for dx,dy in dic:
                tx=cur[0]+dx
                ty=cur[1]+dy
                if 0 <= tx < R and 0 <= ty < C and not visit[tx][ty]:
                    visit[tx][ty]=True
                    queue.append([tx,ty])
        return res
```