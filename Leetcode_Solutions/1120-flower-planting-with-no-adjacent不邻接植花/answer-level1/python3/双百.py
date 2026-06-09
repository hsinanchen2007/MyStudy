### 解题思路
折腾我整整一晚上，不是不会，是想省时间和空间。我又想到一种集合方法，应该会更快，我再试试。


### 代码

```python3
class Solution:
    def gardenNoAdj(self, N: int, paths):
        color=[1]*N
        graph=[[] for i in range(N)]
        for path in paths:
            if path[0]>path[1]:
                graph[path[0]-1].append(path[1]-1)
            else:
                graph[path[1]-1].append(path[0]-1)
        for i in range(1,N):
            flower=[1,2,3,4]
            for node in graph[i]:
                if color[node] in flower:
                    flower.remove(color[node])
            color[i]=flower[0]
        return color
```
试出来了。。  方法二：只开辟必要的空间，而不是每行开辟一个数组。
```
class Solution:
    def gardenNoAdj(self, N: int, paths):
        from collections import defaultdict
        color=[1]*N
        graph=defaultdict(list)
        for path in paths:
            if path[0]>path[1]:
                graph[path[0]-1].append(path[1]-1)
            else:
                graph[path[1]-1].append(path[0]-1)
        graph=sorted(graph.items())
        for i,n in graph:
            flower=[1,2,3,4]
            for node in n:
                if color[node] in flower:
                    flower.remove(color[node])
            color[i]=flower[0]
        return color
```