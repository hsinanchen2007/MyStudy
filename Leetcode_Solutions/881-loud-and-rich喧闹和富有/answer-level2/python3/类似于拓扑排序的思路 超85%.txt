```python
from collections import defaultdict,deque
class Solution:
    def loudAndRich(self, richer: List[List[int]], quiet: List[int]) -> List[int]:
        
        '''
            in_graph:记录图的前置节点
            out_degree:记录点的出度
            zeros:出度为0的点集合
            思路：每次从zeros弹出一个元素，根据in_graph查找前置节点，对前置节点的结果进行更新。更新zeros和out_degree.
        '''
        in_graph = defaultdict(list)
        out_degree = {}
        for u,v in richer:
            in_graph[u].append(v)
            out_degree[v] = out_degree.get(v,0)+1
        
        #print(in_graph)
        n = len(quiet)
        zeros = [i for i in range(n) if i not in out_degree]
        answer = {i:i for i in range(n)}
        while zeros:
            v = zeros.pop(0)
            #print(v)
            for u in in_graph[v]:
                #print('-',u)
                if u in answer:
                    if quiet[answer[v]] < quiet[answer[u]]:
                        answer[u] = answer[v]
                else:
                    answer[u] = answer[v]
                out_degree[u] -= 1
                if out_degree[u] == 0:
                    del out_degree[u]
                    zeros.append(u)
                #print(answer)
        #print(answer)
        return [answer[i] for i in range(n)]
```