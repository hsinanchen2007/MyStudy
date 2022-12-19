思路：
将题设中的计算机网络建模为一个无向图G，那么：

所需最少操作次数（在可行的条件下） = G中的连通分量数 - 1
可行条件： G中的冗余边数 >= 所需最少操作次数
![form.PNG](https://pic.leetcode-cn.com/4bc9dd217f984ad0e500760892d18322f6b9d7fb03c7b0052c89fbafb1649379-form.PNG)
G的一个连通分量p中的边数 = p中所有结点度的和 / 2

代码：
初学Python, 对很多语言特性不了解，写出来的代码可能有点繁。
之所以用Python而不用我最擅长（其实也不怎么擅长）的C语言是因为队列用数组实现怕越界，链表实现又嫌麻烦。比赛的时候，时间结束后才提交成功，只差了不到半分钟#_#,算法菜鸡继续努力。
```Python3 []
from collections import deque
class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        num_component = 0  #G中连通分量的数目
        num_remains = 0    #G中冗余边的数目
        
        #构建图G的邻接表表示：
        G = []
        for i in range(0, n):
            G.append([])
        for pair in connections:
            G[pair[0]].append(pair[1])
            G[pair[1]].append(pair[0])
        
        #以BFS统计G中连通分量和冗余边的数目：
        color = [0] * n
        for computer in range(0, n):
            if(color[computer] != 0):
                continue
            #对新发现的包含computer的连通分量进行遍历
            num_component += 1
            num_node = 0    #该连通分量中的结点数
            num_degree = 0  #该连通分量中所有结点度的和
            Q = deque([])
            Q.append(computer)
            color[computer] = 1
            while(len(Q) != 0):
                u = Q.popleft()
                num_node += 1
                for v in G[u]:
                    if not color[v]:
                        color[v] = 1
                        Q.append(v)
                    num_degree += 1
            num_remains += (num_degree / 2) - (num_node - 1)
        
        #判断是否可行：
        if num_component - 1 <= num_remains:
            return num_component - 1
        else:
            return -1
```

