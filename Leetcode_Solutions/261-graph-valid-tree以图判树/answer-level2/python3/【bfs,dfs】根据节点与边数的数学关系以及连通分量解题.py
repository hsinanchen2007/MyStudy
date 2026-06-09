执行用时 :116 ms, 在所有 python3 提交中击败了98.48%的用户
内存消耗 :14.9 MB, 在所有 python3 提交中击败了100.00%的用户

先判断边数和节点数量是否满足：
节点数-1 = 边数的关系，然后再使用dfs或者bfs进行一次遍历，再通过一次遍历是否遍历了全部节点来判断连通分量是否为1

思路：1 dfs
```
class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        flag = n==len(edges)+1
<!-- flag判断是否满足节点和边数量的关系,如果不满足条件，直接返回False -->
        if not flag:
            return flag
        mark = [0 for _ in range(n)]
        grid = [[] for _ in range(n)]
<!-- mark用来记录是否访问过，grid是邻接矩阵 -->
        for x,y in edges:
            grid[x].append(y)
            grid[y].append(x)
<!-- 深度优先遍历 -->
        def dfs(root):
            for node in grid[root]:
                if not mark[node]:
<!-- 访问过的都在mark中进行标记 -->
                    mark[node] = 1
                    dfs(node)
        mark[0] = 1
        dfs(0)
<!-- 通过计算mark列表中的和是否等于它的长度来判断连通分量是否是1，如果连通分量为1，mark列表中所有元素都应为1 -->
        return sum(mark)==len(mark)
```

思路二：bfs

与以上题解思路相同，只是一次遍历的方式进行了改变

```
class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        flag = n==len(edges)+1
        if not flag:
            return flag
        mark = [0 for _ in range(n)]
        grid = [[] for _ in range(n)]
        for x,y in edges:
            grid[x].append(y)
            grid[y].append(x)
<!-- 广度优先搜索 -->
        def bfs(root):
            que = []
            que.append(root)
            while que:
                node = que.pop(0)
                for ns in grid[node]:
                    if not mark[ns]:
                        que.append(ns)
                        mark[ns] = 1
        mark[0] = 1
        bfs(0)
        return sum(mark)==len(mark)
```

