利用了正方形的定义，四边相等，对角线相等。
这里各个点之间的距离用了循环，一个个写太不pythonic，如果是求有效的五边形呢。
```
class Solution:
    def validSquare(self, p1: List[int], p2: List[int], p3: List[int], p4: List[int]) -> bool:        
        pl = [p1,p2,p3,p4]
        dist = []
        for i in range(len(pl)):
            for j in range(i+1,len(pl)):
                l = (pl[i][1]-pl[j][1])**2 + (pl[i][0]-pl[j][0])**2
                dist.append(l)        
        dist.sort()
        return True if dist[0]==dist[3]!=0 and dist[4]==dist[5] else False
```
