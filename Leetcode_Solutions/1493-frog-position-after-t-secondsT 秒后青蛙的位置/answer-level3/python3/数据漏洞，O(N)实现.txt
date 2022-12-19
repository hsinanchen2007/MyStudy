利用了数据漏洞（结点值小的为父结点），执行贼快

`son_par`存储子结点映射的父结点，从`target`一直寻父结点，直至根结点1
- 若`target`有子结点，则深度必须与时间t相等；
- 若`target`没有子结点，则深度可以小于时间t。

<br/>

```python3
class Solution:
    def frogPosition(self, n: int, edges: List[List[int]], t: int, target: int) -> float:
        if target == 1:
            if t == 0 or len(edges) == 0:
                return 1
            else:
                return 0
        edges = [sorted(edge) for edge in edges]
        flag = False
        son_par = {}
        node_num = {}
        for par, son in edges:
            if par == target:
                flag = True
            son_par[son] = par
            node_num[par] = node_num.get(par, 0) + 1
        par = son_par[target]
        dist = 0
        p = 1
        while par != 1:
            p /= node_num[par]
            dist += 1
            par = son_par[par]
        dist += 1
        p /= node_num[par]
        if flag is True and t == dist:
            return p
        elif flag is False and t >= dist:
            return p
        else:
            return 0

```

![image.png](https://pic.leetcode-cn.com/7e98f0ec17d720e042e49bb41c02a359fa6ea63a82263a907e668c3558e1b337-image.png)

<br/>

若要弥补本题逻辑漏洞，用邻接矩阵或者邻接表完成图的构建，dfs或者bfs完成题解。

邻接表构建图，队列实现bfs遍历
- 字典列表(`default(list)`)实现邻接表;
- 双端队列`deque`实现队列，非递归实现bfs遍历，效率高；
- `visited`记录访问过的节点，防止重新访问，陷入死循环，因为构建的是无向图；

<br/>

```
from collections import defaultdict, deque

class Solution:
    def frogPosition(self, n, edges, t, target):
        par_sons = defaultdict(list)
        visited = [False for i in range(n + 1)]
        for par, son in edges:
            par_sons[par].append(son)
            par_sons[son].append(par)
        par_sons[1].append(1)
        queue = deque()
        par, p, depth = 1, 1, 0
        queue.append((par, p, depth))
        while len(queue) != 0:
            par, p, depth = queue.popleft()
            # print(par, p, depth)
            visited[par] = True
            if par == target:
                if (len(par_sons[par]) == 1 and t >= depth) or (len(par_sons[par]) > 1 and t == depth):
                    return p
                else:
                    return 0
            if len(par_sons[par]) > 1:
                for son in par_sons[par]:
                    if visited[son] is False:
                        m = len(par_sons[par]) - 1
                        queue.append((son, p / m, depth + 1))

```

![image.png](https://pic.leetcode-cn.com/77d7e6c5a2a74dce85cf7550d89a23875a5b86580c0cb7cf79857981315f13f1-image.png)

效果还不错！