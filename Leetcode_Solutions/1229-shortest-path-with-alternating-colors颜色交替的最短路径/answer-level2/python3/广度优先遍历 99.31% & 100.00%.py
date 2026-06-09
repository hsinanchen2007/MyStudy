图类问题的基本解题思路是广度优先遍历（深度也可以），遍历的时候记录已经访问的过的节点，避免有环。
该问题的不同在于path要红蓝相间，所以遍历的时候记录一下该节点前面的edge是红还是蓝，来决定接下来有哪些节点可去。另一个是记录已访问过节点的时候要记录颜色信息，同一个节点，红色边到达和蓝色边到达要区别对待。

总结一下：
1. 建立两张哈希表，记录不同颜色的边。
2. 基于队列进行广度优先搜索（因为这里是找最短路径，所以用广度优先搜索比较合适一些，大家都往前一步一步走，先到达的就是最短的，记下来。）
3. 把当前节点连同颜色记录到已访问节点。并更新该节点的最短路径。
4. 根据当前节点前edge的颜色来选择哈希表，下一个节点如果没访问过就入队。注意记录当前edge颜色信息。



```
class Solution:
    def shortestAlternatingPaths(self, n, red_edges, blue_edges):
        # define
        RED = 1
        BLUE = -1
        def other(c):
            return -c
        
        # list to hash_dic
        red_edges_dic = {}
        blue_edges_dic = {}
        for e in red_edges:
            start, end = e
            if red_edges_dic.get(start) is None:
                red_edges_dic[start] = []
            red_edges_dic[start].append(end)
        for e in blue_edges:
            start, end = e
            if blue_edges_dic.get(start) is None:
                blue_edges_dic[start] = []
            blue_edges_dic[start].append(end)
        edges = {
            RED: red_edges_dic,
            BLUE: blue_edges_dic
        }
        
        path_length = [-1 for i in range(n)]
        
        # bfs
        length = 0
        accesed = {0:True}
        que = [(0, RED), (0, BLUE)]
        while que:
            for i in range(len(que)):
                node, color = que.pop(0)
                if path_length[node] < 0:
                    path_length[node] = length
                next_nodes = edges[color].get(node)
                if next_nodes:
                    for next_node in next_nodes:
                        if accesed.get(color * next_node) is None:
                            accesed[color * next_node] = True
                            que.append((next_node, other(color)))
            length += 1
        
        return path_length
```
