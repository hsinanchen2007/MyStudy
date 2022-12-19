### 解题思路
刚学会F和D算法，试试而已。

### 代码

Floyd 最短路径算法
```
class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        mat=[[10001 for i in range(n)] for j in range(n)]
        for i,j,s in edges:
            mat[i][j]=s
            mat[j][i]=s
        for i in range(n):
            mat[i][i]=0
        for k in range(n):
            for i in range(0,n):
                for j in range(i+1,n):
                    if mat[i][k]+mat[k][j]<mat[i][j]:
                        mat[i][j]=mat[i][k]+mat[k][j]
                        mat[j][i]=mat[i][j]
        return min(range(n),key=lambda i:(sum([1 for j in range(n) if i!=j and mat[i][j]<=distanceThreshold]),-i))
```


Dijkstra 单点N次计算,D算法可以用最小堆优化每次pop,但我用了字典结构，怎么pop还没想好
```
class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        points=collections.defaultdict(list)
        for i,j,s in edges:
            points[i].append((j,s))
            points[j].append((i,s))
        def djs(home=dict(),out=dict()):
            while len(out):
                k,v=min(out.items(),key=lambda x:(x[1]))
                del out[k]
                if v>distanceThreshold:
                    return home
                home[k]=v
                for j,s in points[k]:
                    if j not in home:
                        if j not in out:
                            out[j]=v+s
                        else:
                            out[j]=min(out[j],v+s)
            return home
        return min(range(n),key =lambda i:(len(djs({i:0},{k:v for k,v in points[i]})),-i))
```
