用的dfs方法，如果一个点没有着色的话，根据其邻居已经作色的情况，选择改点的颜色
```
class Solution:
    def gardenNoAdj(self, N: int, paths: List[List[int]]) -> List[int]:
        graph = {}
        # 用visit和color记录已经填充的位置和对应颜色
        visited = [0]*(N+1)
        color = [0]*(N+1)
        # 自己肯定可以与自己连通
        for i in range(1, N+1):
            graph[i] = [i]

        for path in paths:
            graph[path[0]].append(path[1])
            graph[path[1]].append(path[0])

        def dfs(node):
            # 先收集neighbour的color
            neighbour_color = {}
            for neighbour in graph[node]:
                if visited[neighbour]:
                    if color[neighbour] not in neighbour_color:
                        neighbour_color[color[neighbour]] = 0
            # 寻找可以填入的color
            filled_color = 1
            while filled_color in neighbour_color:
                filled_color += 1
            visited[node] = 1
            color[node] = filled_color
            for neighbour in graph[node]:
                if visited[neighbour] == 0:
                    dfs(neighbour)
            
        for i in range(1, N+1):
            if visited[i] == 0:
                dfs(i)
        return color[1:]
            

                    


```
