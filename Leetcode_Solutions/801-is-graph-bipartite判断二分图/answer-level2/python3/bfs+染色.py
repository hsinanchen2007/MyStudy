### 解题思路
把图中的节点拆分成两个独立子集，可以通过对节点染两种不同的颜色来表示。
从0开始，0染色成red，和0相连接的节点可以染色为blue，
然后再对这些blue的节点遍历，把他们连接的节点染为red...

所以可以用广度优先来做这个事。

### 代码

```python3
class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        
        # bfs
        color = [0] * len(graph)
        for i in range(len(graph)):
            if color[i]:
                continue
            color[i] = 1

            q = [i]
            while q:
                cur = q.pop()
                for node in graph[cur]:
                    if color[node] == 0:
                        color[node] = -color[cur]
                        q.append(node)
                    elif color[node] + color[cur]:
                        return False
        return True                        

```