```
class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        # 没有出度的点，或者减去通往出度为0的点的那些边后，出度为0的点
        # 所以使用bfs
        
        # 逆向的拓扑
        # 建图，建出度表
        from collections import defaultdict
        out_degree_list = [0]*len(graph)
        out_degree_graph = defaultdict(list)

        for i in range(len(graph)):
            for j in graph[i]:
                out_degree_list[i] += 1
                out_degree_graph[j].append(i)

        cur_level = []
        for j in range(len(out_degree_list)):
            if out_degree_list[j] == 0:
                cur_level.append(j)
        res = []

        while cur_level:
            next_level = []
            for j in cur_level:   # (i, j) mean that i is a starting point of an edge and j in the ending point
                res.append(j)
                for i in out_degree_graph[j]:
                    out_degree_list[i] -= 1
                    if out_degree_list[i] == 0:
                        next_level.append(i)
            cur_level = next_level
        
        return sorted(res)

        
```
