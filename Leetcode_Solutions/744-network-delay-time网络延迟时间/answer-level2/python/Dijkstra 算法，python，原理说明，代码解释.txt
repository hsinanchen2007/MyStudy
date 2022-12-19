### 解题思路


### 代码

```python3
class Solution:
    def networkDelayTime(self, times: List[List[int]], N: int, K: int) -> int:
        """
        dijskra算法
        每次选择距离最短的目的地x加入目的地集合，更新K到x的邻接点的距离
        """
        # 记录K到其他目的地的距离
        dist = [float('inf') for i in range(N+1)]
        dist[K] = 0
        # 构建图
        hashMap = dict()
        for u,v,w in times:
            if u not in hashMap:
                hashMap[u] = []
            hashMap[u].append((v,w))
            if u==K:
                dist[v] = min(dist[v], w)
        # 每次循环找到一个距离最短且不在集合中的目的地加入集合
        ends = {K}
        # 还有节点未确定最短距离
        while len(ends)<N:
            next_i = 0
            # 寻找不在集合中且距离最短的目的地
            for i in range(1,N+1):
                if i not in ends and dist[i]<dist[next_i]:
                    next_i = i
            # 没找到
            if next_i == 0:
                return -1
            # 找到
            ends.add(next_i)
            # 该节点没有邻接点
            if next_i not in hashMap:
                continue
            # 更新K到它的邻接点的距离
            for v,w in hashMap[next_i]:
                dist[v] = min(dist[v], w+dist[next_i])
        return max(dist[1:])


```



        

        
        
```