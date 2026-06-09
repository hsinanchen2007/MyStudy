```
from typing import List


def is_bipartite(graph: List[List[int]]) -> bool:
    # 一个字典，key是每个节点，value是这个节点的颜色
    color = {}

    def dfs(pos: int) -> bool:
        # 针对当前节点(pos)的每个相邻节点进行判断
        for j in graph[pos]:
            # 如果已经被染色了，说明是之前在给相邻节点上过色了
            if j in color:
                # 如果有任意相邻的节点是同色的，说明不能分成2个集合，返回False
                if color[j] == color[pos]:
                    return False
            else:
                # 没有被染过色，则通过异或操作(与1异或等于取反)，标记成与当前节点不同的颜色
                color[j] = color[pos] ^ 1
                # 递归调用
                if not dfs(j):
                    return False
        return True

    # 针对每个节点进行DFS
    for i in range(len(graph)):
        # 没有染过色的，默认初始化为0
        if i not in color:
            color[i] = 0
        # 只要有一个节点的相邻节点中有颜色一样的，就返回False，不需要继续进行判断了
        if not dfs(i):
            return False
    return True
```
