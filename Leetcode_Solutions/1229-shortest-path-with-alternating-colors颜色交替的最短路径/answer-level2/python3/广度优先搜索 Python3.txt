**思路：**

这道题的难点在于理解题意和编写代码。要求所有最短路径的长度，我们很容易想到广度优先搜索。问题是，从结点 0 出发，可以先走红色边，也可以先走蓝色边。我们当然可以先走红色边 BFS 一遍，再先走蓝色边 BFS 一遍。但是这样代码写两份就比较冗长。所以，我们需要在队列里加入结点的时候，设计一个变量，表示下一步是该走红色边还是该走蓝色边。我这里用 `True` 来表示下一步该走红色边，用 `False` 来表示下一步该走蓝色边。所以搜索队列的初始状态是 `[(0, True), (0, False)]` 。那么，将结点取出时，我们就可以判断第二个变量值来选择从哪个类型的边进行搜索。


**代码：**
```python
class Solution:
    def shortestAlternatingPaths(self, n: int, red_edges: List[List[int]], blue_edges: List[List[int]]) -> List[int]:
        # 答案数组
        ans = [-1] * n
        ans[0] = 0
        # 访问过的结点
        visited = set()
        visited.add((0, True))
        visited.add((0, False))
        # 初始结点
        q = [(0, True), (0, False)]
        # 红色边和蓝色边
        r = collections.defaultdict(set)
        b = collections.defaultdict(set)
        for e in red_edges:
            r[e[0]].add(e[1])
        for e in blue_edges:
            b[e[0]].add(e[1])
        # 步数
        step = 0
        # BFS
        while q:
            step += 1
            t = []
            while q:
                node, color = q.pop()
                if color and node in r:
                    for next_node in r[node]:
                        if (next_node, False) not in visited:
                            visited.add((next_node, False))
                            if ans[next_node] == -1:
                                ans[next_node] = step
                            t.append((next_node, False))
                elif not color and node in b:
                    for next_node in b[node]:
                        if (next_node, True) not in visited:
                            if ans[next_node] == -1:
                                ans[next_node] = step
                            t.append((next_node, True))
            q = t
        return ans
```