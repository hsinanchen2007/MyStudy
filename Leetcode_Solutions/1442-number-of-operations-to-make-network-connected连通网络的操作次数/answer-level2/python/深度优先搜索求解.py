### 解题思路
此处撰写解题思路
明确一个概念：要连接n个点，最少需要n-1条边。
对本题来说，子网（连通分量）的个数为n，那么需要的网线(边)就是n-1，如果给定的图中网线(边)有多余,那么拆走需要的即可，若是没有多余，则返回-1，即不能完成连通。
连通各个子网所需的网线数cable_required由深度优先算法给出的连通分量数count_of_cc-1得到，当前的网线数即是edges=len(connection)，若网络中一共有n台电脑，那么最少需要min_cable = n-1根网线，若当前网线数>=最少需求数，说明网线有多余，则直接返回所需网线数cable_required，反之则返回-1


### 代码

```python3
class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        # bfs记录访问过的顶点
        marked = [False for _ in range(n)]
        # 当前网线数
        edges = len(connections)
        # 初始化连通分量数
        count_of_cc = 0
        # 初始化需要的网线数
        cable_required = 0
        # 所有电脑连通需要最少的网线数
        min_cable = n - 1
        # 构建邻接表
        adj_table = [set() for _ in range(n)]
        for a,b in connections:
            adj_table[a].add(b)
            adj_table[b].add(a)
        # 深度优先搜索
        def dfs(s):
            marked[s] = True
            for i in adj_table[s]:
                if not marked[i]:
                    dfs(i)
        # 对图中每个顶点进行dfs搜索，确定连通分量数
        for i in range(n):
            if not marked[i]:
                dfs(i)
                count_of_cc += 1
        # 连接各个连通分量所需的最小边数
        cable_required = count_of_cc - 1
        # 若当前的边数足以连通图中所有点，则证明有冗余，返回所需边数
        if edges - min_cable >= 0:
            return cable_required
        else:
            return -1
```